/*----------------------------------------------------------------------
  extlib

  Bibliotek med diverse hj�lpfunktioner

  Copyright 2003 Christian Dav�n
----------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <wtypes.h>
#include <winbase.h>
#include "extlib.h"

/*----------------------------------------------------------------------
  Funktion:  GetLastErrorMessage
  Datum:     23 jul 2003

  Uppgift:   Returnerar en str�ng som beskriver felet som ges av GetLastError
  Undantag:  --
----------------------------------------------------------------------*/
AnsiString GetLastErrorMessage() {
    void *pMessage;
    int success;
    AnsiString msg = "";

    success = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
            NULL, GetLastError(), 0, (char *)&pMessage, 0, NULL);

    if(success) {
        msg = AnsiString((char *)pMessage);
        LocalFree(pMessage);
    }

    return msg;
}

// M�ste fixa s� att det inte k�rs i icke-debug-l�ge!!!
// Eller? Det kanske bara anv�nds i Test-enheter...
void Assert(bool a_expression, AnsiString a_description)
{
    if (!a_expression)
    {
        cout << "Assert misslyckades: " << a_description << "\n";
        Pause();
        exit(EXIT_FAILURE);
    }
}

// Endast f�r debug-syften i console-l�ge
void Pause()
{
    char c;
    cin >> c;
}

