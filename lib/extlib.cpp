/*----------------------------------------------------------------------
  extlib

  Bibliotek med diverse hjälpfunktioner

  Copyright 2003 Christian Davén
----------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <wtypes.h>
#include <winbase.h>
#include "extlib.h"

/*----------------------------------------------------------------------
  Funktion:  GetLastErrorMessage
  Datum:     23 jul 2003

  Uppgift:   Returnerar en sträng som beskriver felet som ges av GetLastError
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

// Måste fixa så att det inte körs i icke-debug-läge!!!
// Eller? Det kanske bara används i Test-enheter...
void Assert(bool a_expression, AnsiString a_description)
{
    if (!a_expression)
    {
        cout << "Assert misslyckades: " << a_description << "\n";
        Pause();
        exit(EXIT_FAILURE);
    }
}

// Endast för debug-syften i console-läge
void Pause()
{
    char c;
    cin >> c;
}

