//---------------------------------------------------------------------------
#include "../Headers.h"
#pragma hdrstop

#include "songproperties.h"
#include "../Song/Song.h"
#include "../Constants.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSongPropertiesForm *SongPropertiesForm;
//---------------------------------------------------------------------------
__fastcall TSongPropertiesForm::TSongPropertiesForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TSongPropertiesForm::Initialise(const SongProperty &a_properties)
{
    FileNameLabel->Caption = a_properties.getPropertyRightValue(properties::FILENAME);
    TitleEdit->Text = a_properties.getPropertyRightValue(properties::TITLE);
    ArtistEdit->Text = a_properties.getPropertyRightValue(properties::LEADARTIST);
    AlbumEdit->Text = a_properties.getPropertyRightValue(properties::ALBUM);
    TrackEdit->Text = a_properties.getPropertyRightValue(properties::TRACKNO);
    YearEdit->Text = a_properties.getPropertyRightValue(properties::RECORDINGTIME);
    GenreComboBox->Text = a_properties.getPropertyRightValue(properties::CONTENTTYPE);
    CommentMemo->Lines->Text = a_properties.getPropertyRightValue(properties::COMMENT);
    SituationComboBox->Text = a_properties.getPropertyRightValue(properties::SITUATION);
    MoodComboBox->Text = a_properties.getPropertyRightValue(properties::MOOD);

    AnsiString ratingtext = a_properties.getPropertyRightValue(properties::RATING);

    if(ratingtext != "" && ratingtext != "-1") {
        int rating = StrToInt(ratingtext);
        
        if(rating < 80)
            RatingComboBox->ItemIndex = 4;
        else if(rating < 130)
            RatingComboBox->ItemIndex = 3;
        else if(rating < 170)
            RatingComboBox->ItemIndex = 2;
        else if(rating < 210)
            RatingComboBox->ItemIndex = 1;
        else
            RatingComboBox->ItemIndex = 0;
    }
    else
        RatingComboBox->ItemIndex = -1;

    m_songproperties = a_properties;
}
//---------------------------------------------------------------------------
SongProperty TSongPropertiesForm::GetNewProperties()
{
    return m_songproperties;
}
//---------------------------------------------------------------------------
void __fastcall TSongPropertiesForm::OKButtonClick(TObject *Sender)
{
    if(GenreComboBox->Text == "--------") {
        Application->MessageBox("Du har valt ett alternativ i genre-listan som är felaktigt.", "Felaktig genre", MB_ICONWARNING);
        return;
    }

    try {
        if(YearEdit->Text != "")
            StrToInt(YearEdit->Text);
    }
    catch(EConvertError &) {
        Application->MessageBox("Du har angett ett felaktigt datumformat.\n\nRätt format är ÅÅÅÅMMDD, eller ÅÅÅÅ eller ÅÅÅÅMM.", "Felaktigt datum", MB_ICONWARNING);
        return;
    }

    m_songproperties.setPropertyRightValue(properties::TITLE, TitleEdit->Text);
    m_songproperties.setPropertyRightValue(properties::LEADARTIST, ArtistEdit->Text);
    m_songproperties.setPropertyRightValue(properties::ALBUM, AlbumEdit->Text);
    m_songproperties.setPropertyRightValue(properties::TRACKNO, TrackEdit->Text);
    m_songproperties.setPropertyRightValue(properties::RECORDINGTIME, YearEdit->Text);
    m_songproperties.setPropertyRightValue(properties::CONTENTTYPE, GenreComboBox->Text);
    m_songproperties.setPropertyRightValue(properties::COMMENT, CommentMemo->Lines->Text);
    m_songproperties.setPropertyRightValue(properties::SITUATION, SituationComboBox->Text);
    m_songproperties.setPropertyRightValue(properties::MOOD, MoodComboBox->Text);

    AnsiString ratingtext = "";

    if(RatingComboBox->ItemIndex == 4)
        ratingtext = "60";
    else if(RatingComboBox->ItemIndex == 3)
        ratingtext = "110";
    else if(RatingComboBox->ItemIndex == 2)
        ratingtext = "150";
    else if(RatingComboBox->ItemIndex == 1)
        ratingtext = "190";
    else if(RatingComboBox->ItemIndex == 0)
        ratingtext = "230";

    m_songproperties.setPropertyRightValue(properties::RATING, ratingtext);

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
