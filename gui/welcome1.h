//---------------------------------------------------------------------------

#ifndef welcome1H
#define welcome1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Settings;

class TWelcome1Form : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label2;
    TLabel *Label4;
    TButton *MainFolderButton;
    TLabel *PreMainFolderLabel;
    TLabel *MainFolderLabel;
    TButton *NextButton;
    TButton *CancelButton;
    void __fastcall MainFolderButtonClick(TObject *Sender);
    void __fastcall CancelButtonClick(TObject *Sender);
    void __fastcall NextButtonClick(TObject *Sender);
private:	// User declarations
    Settings *m_pSettings;

    bool BrowseForFolder();
public:		// User declarations
    __fastcall TWelcome1Form(TComponent* Owner);
    __fastcall TWelcome1Form(Settings *);
};
//---------------------------------------------------------------------------
extern PACKAGE TWelcome1Form *Welcome1Form;
//---------------------------------------------------------------------------
#endif
