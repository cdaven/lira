//---------------------------------------------------------------------------
#include "../Headers.h"
#pragma hdrstop
#pragma warn -8057

#include "guimain.h"
#include "welcome1.h"
#include "songproperties.h"
#include "about.h"
#include "fsettings.h"
#include "splash.h"

#include "Settings.h"
#include "../Exceptions.h"
#include "../MediatorInterface.h"
#include "../Song/ConcreteSongFacade.h"
#include "../Song/SongProperty.h"
#include "../Song/Song.h"
#include "../ImportExport/ConcreteImportExportFacade.h"
#include "../Database/ConcreteDatabaseEngine.h"
//#include "../Playlist/ConcretePlaylistFacade.h"
#include "../Player/ConcretePlayerFacade.h"
#include "../Constants.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LMDButton"
#pragma link "LMDCustomButton"
#pragma link "LMDCustomComponent"
#pragma link "LMDTrayIcon"
#pragma link "LMDWndProcComponent"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
    Screen->Cursor = crAppStart;

    MEDIATOR = new Mediator();

    IMPORTEXPORT = new ConcreteImportExportFacade();
    DATABASE = new ConcreteDatabaseEngine();
    SONG = new ConcreteSongFacade((MediatorInterface *)MEDIATOR);
//    PLAYLIST = new ConcretePlaylistFacade((MediatorInterface *)MEDIATOR);
    PLAYER = new ConcretePlayerFacade();

    MEDIATOR->setImportExportFacade(IMPORTEXPORT);
    MEDIATOR->setSongFacade(SONG);
    MEDIATOR->setDatabaseEngine(DATABASE);
//    MEDIATOR->setPlaylistFacade(PLAYLIST);
    MEDIATOR->setPlayerFacade(PLAYER);

    try {
        auto_ptr<TSplashForm> SplashForm(new TSplashForm(0));
        SplashForm->MessageLabel->Caption = "Läser in databas ...";
        SplashForm->Show();
        Application->ProcessMessages();
        SONG->readFromDatabase();
    }
    catch(EInOutError &) {}
    catch(BadFileFormatException &) {
        Screen->Cursor = crArrow;
        if(Application->MessageBox("Databasfilen har ett felaktigt format. Du rekommenderas att radera filen\noch läsa in data från alla musikfiler igen.\n\nVill du radera databasfilen?", "Korrupt databasfil", MB_ICONERROR + MB_YESNO)
            == ID_YES)
            DeleteFile(AnsiString(database::FILENAME_SONGS));
    }

    Screen->Cursor = crAppStart;
    m_settings.load();
    if(m_settings.getMainFolderPath() == "")
        ShowWelcomeForm();

    if(!Application->Terminated) {
        Screen->Cursor = crAppStart;
        try {
            PLAYER->setPlayer(m_settings.getPlayerType(), m_settings.getPlayerPath());
        }
        catch(InvalidPlayerTypeException &) {
            Screen->Cursor = crArrow;
            Application->MessageBox("Felaktiga inställningar har angetts. Du kommer nu få göra om dessa.", "Felaktig data", MB_ICONWARNING);
            ShowWelcomeForm();
        }
        catch(FileNotFoundException &) {
            Screen->Cursor = crArrow;
            Application->MessageBox("Felaktiga inställningar har angetts. Du kommer nu få göra om dessa.", "Felaktig data", MB_ICONWARNING);
            ShowWelcomeForm();
        }

        if(!Application->Terminated) {
            Screen->Cursor = crAppStart;
            try {
                auto_ptr<TSplashForm> SplashForm(new TSplashForm(0));
                SplashForm->MessageLabel->Caption = "Läser in musikfiler ... (Detta kan ta upp till någon minut första gången.)";
                SplashForm->Show();
                Application->ProcessMessages();
                SONG->updatePath(m_settings.getMainFolderPath());
            }
            catch(FolderNotFoundException &) {
                Screen->Cursor = crArrow;
                Application->MessageBox("Felaktiga inställningar har angetts. Du kommer nu få göra om dessa.", "Felaktig data", MB_ICONWARNING);
                ShowWelcomeForm();
            }

            if(!Application->Terminated) {
                m_settings.save();
                Show();
                Application->BringToFront();
                Screen->Cursor = crArrow;
            }
        }
    }
}
//---------------------------------------------------------------------------
__fastcall TMainForm::~TMainForm()
{
    delete IMPORTEXPORT;
    delete SONG;
    delete DATABASE;
//    delete PLAYLIST;
    delete PLAYER;

    delete MEDIATOR;
}
//---------------------------------------------------------------------------
void TMainForm::UpdateSongList()
{
    TListItem *pItem = 0;
    SongProperty properties;
    int index;

    properties.addProperty("title");
    properties.addProperty("file name");
    properties.addProperty("lead artist");
    properties.addProperty("album");
    properties.addProperty("content type");
    properties.addProperty("recording time");

    for(int i = 0; i < SongList->Items->Count; i++) {
        pItem = SongList->Items->Item[i];
        index = (int)pItem->Data;

        SONG->getSongProperties(index, &properties);

        pItem->Caption = properties.getPropertyRightValue("title");
        pItem->SubItems->Clear();
        pItem->SubItems->Add(properties.getPropertyRightValue("lead artist"));
        pItem->SubItems->Add(properties.getPropertyRightValue("album"));
        pItem->SubItems->Add(properties.getPropertyRightValue("content type"));
        pItem->SubItems->Add(properties.getPropertyRightValue("recording time"));

        AnsiString filename = properties.getPropertyRightValue("file name");
        filename = filename.SubString(m_settings.getMainFolderPath().Length() + 2, filename.Length());

        pItem->SubItems->Add(filename);
    }
}
//---------------------------------------------------------------------------
void TMainForm::GetAndPutSongsInList(SongProperty *a_properties)
{
    StatusBar->SimpleText = "Hämtar låtar ur databasen ...";
    Screen->Cursor = crHourGlass;

    TListItem *pItem;
    intvector songs = SONG->getSongsMatchingProperties(*a_properties);

    SongList->Items->BeginUpdate();

    a_properties->clear();
    a_properties->addProperty("index");

    for(unsigned int i = 0; i < songs.size(); i++) {
        SONG->getSongProperties(songs[i], a_properties);

        pItem = SongList->Items->Add();
        pItem->Data = (void *)StrToInt(a_properties->getPropertyRightValue("index"));
    }

    UpdateSongList();
    SongList->Items->EndUpdate();
    a_properties->clear();

    Screen->Cursor = crArrow;
    StatusBar->SimpleText = "";
}
//---------------------------------------------------------------------------
void TMainForm::ShowWelcomeForm()
{
    Screen->Cursor = crArrow;

    Welcome1Form = new TWelcome1Form(&m_settings);
    if(Welcome1Form->ShowModal() == mrCancel) {
        Application->Terminate();
        Application->ProcessMessages();
    }

    delete Welcome1Form;
}
//---------------------------------------------------------------------------
void TMainForm::ShowSongsFromYear(const AnsiString &a_year)
{
    SongProperty sp;
    sp.addProperty("recording time", a_year);
    SongList->Clear();
    GetAndPutSongsInList(&sp);
}
//---------------------------------------------------------------------------
void TMainForm::ShowSongsWithRating(int a_rating)
{
    SongProperty sp;
    SongList->Items->BeginUpdate();
    SongList->Clear();

    switch(a_rating) {
        case 1:
            sp.addProperty("rating", "?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "1?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "2?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "3?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "4?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "5?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "6?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "7?");
            GetAndPutSongsInList(&sp);
            break;
        case 2:
            sp.addProperty("rating", "8?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "9?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "10?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "11?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "12?");
            GetAndPutSongsInList(&sp);
            break;
        case 3:
            sp.addProperty("rating", "13?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "14?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "15?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "16?");
            GetAndPutSongsInList(&sp);
            break;
        case 4:
            sp.addProperty("rating", "17?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "18?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "19?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "20?");
            GetAndPutSongsInList(&sp);
            break;
        case 5:
            sp.addProperty("rating", "21?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "22?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "23?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "24?");
            GetAndPutSongsInList(&sp);
            sp.addProperty("rating", "25?");
            GetAndPutSongsInList(&sp);
            break;
    }

    SongList->Items->EndUpdate();
}
//---------------------------------------------------------------------------
void TMainForm::ShowSongsByArtist(const AnsiString &a_artist)
{
    SongProperty sp;
    SongList->Items->BeginUpdate();
    SongList->Clear();

    if(a_artist == "Alla A-D") {
        sp.addProperty("lead artist", "A*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "B*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "C*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "D*");
        GetAndPutSongsInList(&sp);
    }
    else if(a_artist == "Alla E-H") {
        sp.addProperty("lead artist", "E*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "F*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "G*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "H*");
        GetAndPutSongsInList(&sp);
    }
    else if(a_artist == "Alla I-L") {
        sp.addProperty("lead artist", "I*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "J*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "K*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "L*");
        GetAndPutSongsInList(&sp);
    }
    else if(a_artist == "Alla M-P") {
        sp.addProperty("lead artist", "M*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "N*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "O*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "P*");
        GetAndPutSongsInList(&sp);
    }
    else if(a_artist == "Alla Q-T") {
        sp.addProperty("lead artist", "Q*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "R*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "S*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "T*");
        GetAndPutSongsInList(&sp);
    }
    else if(a_artist == "Alla U-X") {
        sp.addProperty("lead artist", "U*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "V*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "W*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "X*");
        GetAndPutSongsInList(&sp);
    }
    else if(a_artist == "Alla Y-Ö") {
        sp.addProperty("lead artist", "Y*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "Z*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "Å*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "Ä*");
        GetAndPutSongsInList(&sp);
        sp.addProperty("lead artist", "Ö*");
        GetAndPutSongsInList(&sp);
    }
    else {
        sp.addProperty("lead artist", a_artist + "*");
        GetAndPutSongsInList(&sp);
    }

    SongList->Items->EndUpdate();
}
//---------------------------------------------------------------------------
void TMainForm::ShowSongsBySituation(const AnsiString &a_situation)
{
    SongProperty sp;
    sp.addProperty("situation", a_situation);

    SongList->Clear();
    GetAndPutSongsInList(&sp);
}
//---------------------------------------------------------------------------
void TMainForm::ShowSongsByMood(const AnsiString &a_mood)
{
    SongProperty sp;
    sp.addProperty("mood", a_mood);

    SongList->Clear();
    GetAndPutSongsInList(&sp);
}
//---------------------------------------------------------------------------
void TMainForm::ShowSongsInGenre(const AnsiString &a_genre)
{
    SongProperty sp;
    sp.addProperty("content type", a_genre);

    SongList->Clear();
    GetAndPutSongsInList(&sp);
}
//---------------------------------------------------------------------------
AnsiString TMainForm::RemoveSingleAmpersands(const AnsiString &a_string)
{
    AnsiString retval;
    TReplaceFlags flags;

    flags << rfReplaceAll;

    retval = StringReplace(a_string, "&&", "§§", flags);
    retval = StringReplace(retval, "&", "", flags);
    retval = StringReplace(retval, "§§", "&", flags);

    return retval;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Year1Click(TObject *Sender)
{
    ShowSongsFromYear(IntToStr(((TMenuItem *)Sender)->Tag));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Hela2000talet1Click(TObject *Sender)
{
    ShowSongsFromYear("200?");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Hela1990talet1Click(TObject *Sender)
{
    ShowSongsFromYear("199?");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Hela1980talet1Click(TObject *Sender)
{
    ShowSongsFromYear("198?");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Hela1970talet1Click(TObject *Sender)
{
    ShowSongsFromYear("197?");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Hela1960talet1Click(TObject *Sender)
{
    ShowSongsFromYear("196?");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Hela1950talet1Click(TObject *Sender)
{
    ShowSongsFromYear("195?");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Rating1Click(TObject *Sender)
{
    AnsiString text;
    int rating;

    text = RemoveSingleAmpersands(((TMenuItem *)Sender)->Caption);

    try {
        rating = StrToInt(text.SubString(1, 1));
    }
    catch(EConvertError &) {
        SongList->Clear();
        return;
    }

    ShowSongsWithRating(rating);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Artist1Click(TObject *Sender)
{
    AnsiString text = RemoveSingleAmpersands(((TMenuItem *)Sender)->Caption);
    ShowSongsByArtist(text);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Situation1Click(TObject *Sender)
{
    AnsiString text = RemoveSingleAmpersands(((TMenuItem *)Sender)->Caption);
    ShowSongsBySituation(text);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Mood1Click(TObject *Sender)
{
    AnsiString text = RemoveSingleAmpersands(((TMenuItem *)Sender)->Caption);
    ShowSongsByMood(text);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Genre1Click(TObject *Sender)
{
    AnsiString text = RemoveSingleAmpersands(((TMenuItem *)Sender)->Caption);
    ShowSongsInGenre(text);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GothicRock1Click(TObject *Sender)
{
    SongProperty sp;

    SongList->Items->BeginUpdate();
    SongList->Clear();

    sp.addProperty("content type", "Gothic Rock");
    GetAndPutSongsInList(&sp);
    sp.addProperty("content type", "Gothic");
    GetAndPutSongsInList(&sp);

    SongList->Items->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Punk2Click(TObject *Sender)
{
    SongProperty sp;

    SongList->Items->BeginUpdate();
    SongList->Clear();

    sp.addProperty("content type", "Punk Rock");
    GetAndPutSongsInList(&sp);
    sp.addProperty("content type", "Punk");
    GetAndPutSongsInList(&sp);

    SongList->Items->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Psykedeliskrock2Click(TObject *Sender)
{
    SongProperty sp;

    SongList->Items->BeginUpdate();
    SongList->Clear();

    sp.addProperty("content type", "Psykedelisk Rock");
    GetAndPutSongsInList(&sp);
    sp.addProperty("content type", "Psykedelisk");
    GetAndPutSongsInList(&sp);

    SongList->Items->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RockRoll1Click(TObject *Sender)
{
    SongProperty sp;

    SongList->Items->BeginUpdate();
    SongList->Clear();

    sp.addProperty("content type", "Rock & Roll");
    GetAndPutSongsInList(&sp);
    sp.addProperty("content type", "Klassisk Rock");
    GetAndPutSongsInList(&sp);

    SongList->Items->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Swing1Click(TObject *Sender)
{
    SongProperty sp;

    SongList->Items->BeginUpdate();
    SongList->Clear();

    sp.addProperty("content type", "Swing");
    GetAndPutSongsInList(&sp);
    sp.addProperty("content type", "Storband");
    GetAndPutSongsInList(&sp);

    SongList->Items->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Humor2Click(TObject *Sender)
{
    SongProperty sp;

    SongList->Items->BeginUpdate();
    SongList->Clear();

    sp.addProperty("content type", "Humor");
    GetAndPutSongsInList(&sp);
    sp.addProperty("content type", "Komedi");
    GetAndPutSongsInList(&sp);

    SongList->Items->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SongListDblClick(TObject *Sender)
{
    if(SongList->ItemIndex == -1)
        return;

    MainForm->Cursor = crHourGlass;

    TItemStates selected = TItemStates() << isSelected;
    TListItem *pItem = SongList->Selected;
    intvector songindexes;

    while(pItem) {
        songindexes.push_back((int)pItem->Data);
        pItem = SongList->GetNextItem(pItem, sdAll, selected);
    }

    try {
        SONG->playMultipleSongs(songindexes);
    }
    catch(NoPlayerException &) {
        Application->MessageBox("Du har inte uppgett vilken spelare du vill använda.", "Spelare saknas", MB_ICONEXCLAMATION);
    }
    catch(FileNotFoundException &e) {
        AnsiString msg = "Kan inte spela upp filen " + e.Message + " eftersom den inte finns.";
        Application->MessageBox(msg.c_str(), "Fil saknas", MB_ICONEXCLAMATION);
    }

    MainForm->Cursor = crArrow;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SongListCompare(TObject *Sender,
      TListItem *Item1, TListItem *Item2, int Data, int &Compare)
{
    int column = SongList->Tag;

    if(column == 0) {
        if(CompareStrings(Item1->Caption, Item2->Caption))
            Compare = 1;
        else
            Compare = -1;
    }
    else {
        column--;
        
        if(CompareStrings(Item1->SubItems->Strings[column], Item2->SubItems->Strings[column]))
            Compare = 1;
        else
            Compare = -1;
    }

    Compare *= m_sortdirection;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SongListColumnClick(TObject *Sender,
      TListColumn *Column)
{
    StatusBar->SimpleText = "Sorterar lista ...";
    Screen->Cursor = crHourGlass;

    int old_sortbycolumn = SongList->Tag;
    SongList->Tag = Column->Index;

    if(old_sortbycolumn == SongList->Tag)
        m_sortdirection *= -1;
    else
        m_sortdirection = 1;

    SongList->Items->BeginUpdate();
    SongList->CustomSort(NULL, 0);
    SongList->Items->EndUpdate();

    Screen->Cursor = crArrow;
    StatusBar->SimpleText = "";
}
//---------------------------------------------------------------------------
bool TMainForm::CompareStrings(AnsiString a_string1, AnsiString a_string2)
{
    if(a_string1.LowerCase().SubString(1, 4) == "the ")
        a_string1 = a_string1.SubString(5, a_string1.Length());
    if(a_string2.LowerCase().SubString(1, 4) == "the ")
        a_string2 = a_string2.SubString(5, a_string2.Length());

    if(AnsiCompareStr(a_string1, a_string2) > 0)
        return true;
    else
        return false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Spelauppislumpmssigordning1Click(
      TObject *Sender)
{
    if(SongList->ItemIndex == -1)
        return;

    TItemStates selected = TItemStates() << isSelected;
    TListItem *pItem = SongList->Selected;
    intvector songindexes;

    while(pItem) {
        songindexes.push_back((int)pItem->Data);
        pItem = SongList->GetNextItem(pItem, sdAll, selected);
    }

    random_shuffle(songindexes.begin(), songindexes.end());

    try {
        SONG->playMultipleSongs(songindexes);
    }
    catch(NoPlayerException &) {
        Application->MessageBox("Du har inte uppgett vilken spelare du vill använda.", "Spelare saknas", MB_ICONEXCLAMATION);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ShowAllButtonClick(TObject *Sender)
{
    SongList->Clear();
    SongProperty sp;
    sp.addProperty("index", "*");
    GetAndPutSongsInList(&sp);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Egenskaper1Click(TObject *Sender)
{
    if(SongList->ItemIndex == -1)
        return;

    TListItem *pItem = SongList->Selected;
    SongProperty properties;
    int songindex = (int)pItem->Data;

    properties.addProperty(properties::FILENAME);
    properties.addProperty(properties::TITLE);
    properties.addProperty(properties::LEADARTIST);
    properties.addProperty(properties::ALBUM);
    properties.addProperty(properties::TRACKNO);
    properties.addProperty(properties::RECORDINGTIME);
    properties.addProperty(properties::CONTENTTYPE);
    properties.addProperty(properties::COMMENT);
    properties.addProperty(properties::SITUATION);
    properties.addProperty(properties::MOOD);
    properties.addProperty(properties::RATING);

    SONG->refreshSongTag(songindex);
    SONG->getSongProperties(songindex, &properties);
    
    SongPropertiesForm->Initialise(properties);
    if(SongPropertiesForm->ShowModal() == mrOk) {
        properties = SongPropertiesForm->GetNewProperties();

        try {
            SONG->setSongProperties(songindex, properties);
            UpdateSongList();
        }
        catch(FileNotFoundException &e) {
            Application->MessageBox("....", "Fil saknas", MB_ICONEXCLAMATION);
        }
        catch(FileNotWritableException &e) {

        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Om1Click(TObject *Sender)
{
    AboutForm->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TrayIconClick(TObject *Sender)
{
    Application->Restore();
    Application->BringToFront();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Arkiv1Click(TObject *Sender)
{
    SettingsForm->Initialise(m_settings);

    if(SettingsForm->ShowModal() == mrOk) {
        Application->MessageBox("Ändringarna börjar gälla nästa gång du startar programmet.",
            "Ändrade inställningar", MB_ICONINFORMATION);

        m_settings = SettingsForm->GetNewSettings();
        m_settings.save();
    }
}
//---------------------------------------------------------------------------


