//---------------------------------------------------------------------------

#ifndef welcome2H
#define welcome2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class Settings;

class TWelcome2Form : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label3;
    TButton *WinampButton;
    TButton *WMPButton;
    TLabel *PrePlayerTypeLabel;
    TLabel *PlayerTypeLabel;
    TLabel *PrePlayerPathLabel;
    TLabel *PlayerPathLabel;
    TButton *StartButton;
    TButton *CancelButton;
    TOpenDialog *OpenDialog;
    void __fastcall WinampButtonClick(TObject *Sender);
    void __fastcall CancelButtonClick(TObject *Sender);
    void __fastcall StartButtonClick(TObject *Sender);
    void __fastcall WMPButtonClick(TObject *Sender);
private:	// User declarations
    Settings *m_pSettings;

    AnsiString GetProgramFilesPath();
public:		// User declarations
    __fastcall TWelcome2Form(TComponent* Owner);
    __fastcall TWelcome2Form(Settings *);
};
//---------------------------------------------------------------------------
extern PACKAGE TWelcome2Form *Welcome2Form;
//---------------------------------------------------------------------------
#endif
