//---------------------------------------------------------------------------
#include "../Headers.h"
#pragma hdrstop
#pragma warn -8057

#include "welcome1.h"
#include "welcome2.h"
#include "Settings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWelcome1Form *Welcome1Form;
//---------------------------------------------------------------------------
__fastcall TWelcome1Form::TWelcome1Form(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall TWelcome1Form::TWelcome1Form(Settings *a_settings)
    : TForm((TComponent *)0)
{
    m_pSettings = a_settings;
}
//---------------------------------------------------------------------------
bool TWelcome1Form::BrowseForFolder()
{
    BROWSEINFO    info;
    char          szDir[MAX_PATH];
    char          szDisplayName[MAX_PATH];
    LPITEMIDLIST  pidl;
    LPMALLOC      pShellMalloc;
    bool          done = false;

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
            if(SHGetPathFromIDList(pidl, szDir)) {
                MainFolderLabel->Caption = szDir;
                done = true;
            }

            pShellMalloc->Free(pidl);
        }
        pShellMalloc->Release();
    }

    return done;
}
//---------------------------------------------------------------------------
void __fastcall TWelcome1Form::MainFolderButtonClick(TObject *Sender)
{
    if(BrowseForFolder()) {
        m_pSettings->setMainFolderPath(MainFolderLabel->Caption);

        PreMainFolderLabel->Visible = true;
        NextButton->Enabled = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TWelcome1Form::CancelButtonClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TWelcome1Form::NextButtonClick(TObject *Sender)
{
    Hide();

    Welcome2Form = new TWelcome2Form(m_pSettings);
    ModalResult = Welcome2Form->ShowModal();
    delete Welcome2Form;
}
//---------------------------------------------------------------------------

