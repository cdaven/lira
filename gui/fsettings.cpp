//---------------------------------------------------------------------------
#include "../Headers.h"
#pragma hdrstop

#include "fsettings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSettingsForm *SettingsForm;
//---------------------------------------------------------------------------
__fastcall TSettingsForm::TSettingsForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
AnsiString TSettingsForm::BrowseForFolder()
{
    BROWSEINFO    info;
    char          szDir[MAX_PATH];
    char          szDisplayName[MAX_PATH];
    LPITEMIDLIST  pidl;
    LPMALLOC      pShellMalloc;
    AnsiString    folder = "";

    if(SHGetMalloc(&pShellMalloc) == NO_ERROR)
    {
        memset(&info, 0x00, sizeof(info));
        info.hwndOwner = Handle;
        info.pidlRoot  = 0;
        info.pszDisplayName = szDisplayName;
        info.lpszTitle = "Ange huvudmapp";
        info.ulFlags   = BIF_RETURNONLYFSDIRS;
        info.lpfn = 0;

        pidl = SHBrowseForFolder(&info);

        if(pidl)
        {
            if(SHGetPathFromIDList(pidl, szDir))
                folder = szDir;

            pShellMalloc->Free(pidl);
        }
        pShellMalloc->Release();
    }

    return folder;
}
//---------------------------------------------------------------------------
void TSettingsForm::Initialise(const Settings &a_settings)
{
    m_settings = a_settings;

    if(m_settings.getPlayerType() == "Winamp2")
        WinampRadioButton->Checked = true;
    else
        WMPRadioButton->Checked = true;

    PlayerPathLabel->Caption = m_settings.getPlayerPath();
    MainFolderLabel->Caption = m_settings.getMainFolderPath();
}
//---------------------------------------------------------------------------
AnsiString TSettingsForm::GetProgramFilesPath()
{
    TRegistry *registry = new TRegistry();
    AnsiString retval = "";

    registry->RootKey = HKEY_LOCAL_MACHINE;

    if(registry->OpenKey("\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion", false))
        retval = registry->ReadString("ProgramFilesDir");

    delete registry;
    return retval;
}
//---------------------------------------------------------------------------
void __fastcall TSettingsForm::WinampRadioButtonClick(TObject *Sender)
{
    AnsiString playerpath = GetProgramFilesPath() + "\\Winamp\\winamp.exe";

    if(!FileExists(playerpath)) {
        Application->MessageBox("Programmet kunde inte automatiskt hitta Winamp. Vänligen tala om var det finns.", "Söker winamp.exe", MB_ICONINFORMATION);
        OpenDialog->FileName = "winamp.exe";
        OpenDialog->InitialDir = GetProgramFilesPath();
        if(OpenDialog->Execute())
            playerpath = OpenDialog->FileName;
        else {
            WMPRadioButton->Checked = true;
            return;
        }
    }

    m_settings.setPlayerType("Winamp2");
    m_settings.setPlayerPath(playerpath);

    PlayerPathLabel->Caption = playerpath;
}
//---------------------------------------------------------------------------
Settings TSettingsForm::GetNewSettings()
{
    return m_settings;
}
//---------------------------------------------------------------------------
void __fastcall TSettingsForm::WMPRadioButtonClick(TObject *Sender)
{
    AnsiString playerpath = GetProgramFilesPath() + "\\Windows Media Player\\wmplayer.exe";

    if(!FileExists(playerpath)) {
        Application->MessageBox("Programmet kunde inte automatiskt hitta Windows Media Player. Vänligen tala om var det finns.", "Söker wmplayer.exe", MB_ICONINFORMATION);
        OpenDialog->FileName = "wmplayer.exe";
        OpenDialog->InitialDir = GetProgramFilesPath();
        if(OpenDialog->Execute())
            playerpath = OpenDialog->FileName;
        else {
            WinampRadioButton->Checked = true;
            return;
        }
    }

    m_settings.setPlayerType("WMP9");
    m_settings.setPlayerPath(playerpath);

    PlayerPathLabel->Caption = playerpath;
}
//---------------------------------------------------------------------------
void __fastcall TSettingsForm::MainFolderButtonClick(TObject *Sender)
{
    AnsiString folder = BrowseForFolder();

    if(folder != "") {
        m_settings.setMainFolderPath(folder);

        MainFolderLabel->Caption = folder;
    }
}
//---------------------------------------------------------------------------
