//---------------------------------------------------------------------------
#include "../Headers.h"
#pragma hdrstop

#include "about.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAboutForm *AboutForm;
//---------------------------------------------------------------------------
__fastcall TAboutForm::TAboutForm(TComponent* Owner)
    : TForm(Owner)
{
    DWORD VersionHandle;
    DWORD VersionSize;
    bool  error = false;
    void *pBuffer;
    
    VersionSize = GetFileVersionInfoSize(Application->ExeName.c_str(), &VersionHandle);

    if(VersionSize)
    {
        pBuffer = new char[VersionSize];
        if(GetFileVersionInfo(Application->ExeName.c_str(), VersionHandle, VersionSize,
            pBuffer)) {

            char *b;
            UINT buflen;
            if(VerQueryValue(pBuffer, TEXT("\\StringFileInfo\\041D04E4\\FileVersion"),
               (void** )&b,&buflen)) {

                VersionLabel->Caption = "Version " + AnsiString(b);
            }
        }

        delete[] pBuffer;
    }
}
//---------------------------------------------------------------------------
