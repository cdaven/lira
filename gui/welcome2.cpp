//---------------------------------------------------------------------------
#include "../Headers.h"
#pragma hdrstop
#pragma warn -8057

#include "welcome2.h"
#include "Settings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWelcome2Form *Welcome2Form;
//---------------------------------------------------------------------------
__fastcall TWelcome2Form::TWelcome2Form(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall TWelcome2Form::TWelcome2Form(Settings *a_settings)
    : TForm((TComponent *)0)
{
    m_pSettings = a_settings;
}
//---------------------------------------------------------------------------
AnsiString TWelcome2Form::GetProgramFilesPath()
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
void __fastcall TWelcome2Form::WinampButtonClick(TObject *Sender)
{
    AnsiString playerpath = GetProgramFilesPath() + "\\Winamp\\winamp.exe";

    if(!FileExists(playerpath)) {
        Application->MessageBox("Programmet kunde inte automatiskt hitta Winamp. Vänligen tala om var det finns.", "Söker winamp.exe", MB_ICONINFORMATION);
        OpenDialog->FileName = "winamp.exe";
        OpenDialog->InitialDir = GetProgramFilesPath();
        if(OpenDialog->Execute())
            playerpath = OpenDialog->FileName;
        else
            return;
    }

    m_pSettings->setPlayerType("Winamp2");
    m_pSettings->setPlayerPath(playerpath);

    PrePlayerTypeLabel->Visible = true;
    PrePlayerPathLabel->Visible = true;
    PlayerTypeLabel->Caption = "Winamp";
    PlayerPathLabel->Caption = playerpath;
    StartButton->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TWelcome2Form::CancelButtonClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TWelcome2Form::StartButtonClick(TObject *Sender)
{
    ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TWelcome2Form::WMPButtonClick(TObject *Sender)
{
    AnsiString playerpath = GetProgramFilesPath() + "\\Windows Media Player\\wmplayer.exe";

    if(!FileExists(playerpath)) {
        Application->MessageBox("Programmet kunde inte automatiskt hitta Windows Media Player. Vänligen tala om var det finns.", "Söker wmplayer.exe", MB_ICONINFORMATION);
        OpenDialog->FileName = "wmplayer.exe";
        OpenDialog->InitialDir = GetProgramFilesPath();
        if(OpenDialog->Execute())
            playerpath = OpenDialog->FileName;
        else
            return;
    }

    m_pSettings->setPlayerType("WMP9");
    m_pSettings->setPlayerPath(playerpath);

    PrePlayerTypeLabel->Visible = true;
    PrePlayerPathLabel->Visible = true;
    PlayerTypeLabel->Caption = "Windows Media Player";
    PlayerPathLabel->Caption = playerpath;
    StartButton->Enabled = true;
}
//---------------------------------------------------------------------------

