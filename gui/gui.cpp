//---------------------------------------------------------------------------
#include "../Headers.h"
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("guimain.cpp", MainForm);
USEFORM("welcome1.cpp", Welcome1Form);
USEFORM("welcome2.cpp", Welcome2Form);
USEFORM("songproperties.cpp", SongPropertiesForm);
USEFORM("about.cpp", AboutForm);
USEFORM("fsettings.cpp", SettingsForm);
USEFORM("splash.cpp", SplashForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    HANDLE hInstanceMutex = ::CreateMutex(NULL, true, "LiraMutex_");
    if(GetLastError() == ERROR_ALREADY_EXISTS)
    {
        if(hInstanceMutex)
            CloseHandle(hInstanceMutex);

        Application->MessageBox("Det körs redan en instans av programmet. Du kan inte köra flera samtidigt.", "Programmet redan startat", MB_ICONSTOP);
        return 1;
    }

    try
    {
        Application->Initialize();
        Application->Title = "Lira!";
        Application->CreateForm(__classid(TMainForm), &MainForm);
         Application->CreateForm(__classid(TSongPropertiesForm), &SongPropertiesForm);
         Application->CreateForm(__classid(TAboutForm), &AboutForm);
         Application->CreateForm(__classid(TSettingsForm), &SettingsForm);
         Application->Run();
    }
    catch (Exception &exception)
    {
        AnsiString msg;

        msg = "Ett fel har inträffat och programmet kommer nu att avslutas. Rapportera gärna\ntill christian@daven.name under vilka omständigheter detta fel inträffat.\n\nFelmeddelande: " + exception.Message;

        Application->MessageBox(msg.c_str(), "Fel", MB_ICONSTOP);

        ReleaseMutex(hInstanceMutex);
        CloseHandle(hInstanceMutex);
        return 1;
    }
    catch (...)
    {
         try
         {
             throw Exception("");
         }
         catch (Exception &exception)
         {
            AnsiString msg;

            msg = "Ett fel har inträffat och programmet kommer nu att avslutas. Rapportera gärna\ntill christian@daven.name under vilka omständigheter detta fel inträffat.\n\nFelmeddelande: " + exception.Message;

            Application->MessageBox(msg.c_str(), "Fel", MB_ICONSTOP);

            ReleaseMutex(hInstanceMutex);
            CloseHandle(hInstanceMutex);
            return 1;
         }
    }

    ReleaseMutex(hInstanceMutex);
    CloseHandle(hInstanceMutex);

    return 0;
}
//---------------------------------------------------------------------------
