//---------------------------------------------------------------------------
#ifndef fsettingsH
#define fsettingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "Settings.h"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TSettingsForm : public TForm
{
__published:	// IDE-managed Components
    TButton *MainFolderButton;
    TLabel *Label1;
    TLabel *MainFolderLabel;
    TRadioButton *WinampRadioButton;
    TRadioButton *WMPRadioButton;
    TLabel *Label2;
    TLabel *PlayerPathLabel;
    TButton *CancelButton;
    TButton *OkButton;
    TOpenDialog *OpenDialog;
    void __fastcall WinampRadioButtonClick(TObject *Sender);
    void __fastcall WMPRadioButtonClick(TObject *Sender);
    void __fastcall MainFolderButtonClick(TObject *Sender);
private:	// User declarations
    Settings m_settings;

    AnsiString BrowseForFolder();
    AnsiString GetProgramFilesPath();
public:		// User declarations
    __fastcall TSettingsForm(TComponent* Owner);

    void Initialise(const Settings &);
    Settings GetNewSettings();
};
//---------------------------------------------------------------------------
extern PACKAGE TSettingsForm *SettingsForm;
//---------------------------------------------------------------------------
#endif
