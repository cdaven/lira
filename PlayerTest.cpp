//---------------------------------------------------------------------------
#include "../lib/Exceptions.h"
#pragma hdrstop

#include <iostream.h>
#include <vcl.h>
#include "../lib/Constants.h"
#include "../lib/extlib.h"
#include "PlayerFacade.h"
#include "ConcretePlayerFacade.h"
#include "Player.h"
//---------------------------------------------------------------------------
const AnsiString song1 = "E:\\MP3\\Klassiskt\\Arméns musikpluton - Under blågul fana.mp3";
const AnsiString song2 = "E:\\MP3\\Hårdrock\\ACDC - TNT.mp3";
const AnsiString song3 = "E:\\MP3\\(album)\\Absolute Relaxed 2002\\cd2\\07 - Michael Nyman - The heart asks pleasure first the piano.mp3";
const AnsiString song4 = "E:\\MP3\\Folkmusik\\Orsa spelmän - Brudmarsch från Delsbo.mp3";

void testCreation();
void testWithExternalPlayerShutdown(PlayerFacade *);
void testBasicFunctions(PlayerFacade *);

#pragma argsused
int main(int argc, char* argv[])
{
    bool failed;
    PlayerFacade *pPlayerFacade;
    pPlayerFacade = new ConcretePlayerFacade();
    pPlayerFacade->setPlayer("Winamp2", "C:\\Program Files\\Winamp\\Winamp.exe");

    try {
        testCreation();
        testWithExternalPlayerShutdown(pPlayerFacade);
        testBasicFunctions(pPlayerFacade);
    }
    catch(Exception &) {
        cout << "Ett oväntat undantag inträffade!";
    }

    char c;

    cout << "done.\n";
    cin >> c;

    delete pPlayerFacade;
    pPlayerFacade = 0;
    return 0;
}
//---------------------------------------------------------------------------
void testCreation()
{
    bool fail;
    PlayerFacade *pPlayerFacade = 0;

    try {
        fail = true;
        pPlayerFacade = new ConcretePlayerFacade();
        pPlayerFacade->setPlayer("k", "C:\\Program Files\\Winamp\\Winamp.exe");
    }
    catch(InvalidPlayerTypeException &) {
        fail = false;
    }

    Assert(fail != true, "testCreation 1");

    try {
        fail = true;
        pPlayerFacade = new ConcretePlayerFacade();
        pPlayerFacade->setPlayer("Winamp2", "?åäö\\\\\\§..//+~");
    }
    catch(FileNotFoundException &) {
        fail = false;
    }

    Assert(fail != true, "testCreation 2");

    if(pPlayerFacade)
        delete pPlayerFacade;
}
//---------------------------------------------------------------------------
void testWithExternalPlayerShutdown(PlayerFacade *pPf)
{
    bool fail;
    pPf->close();
    Sleep(1000);

    try {
        fail = true;
        pPf->getStatus();
    }
    catch(PlayerNotAvailableException &) {
        fail = false;
    }

    Assert(fail != true, "testWithExternalPlayerShutdown 1");

    try {
        fail = true;
        pPf->play();
    }
    catch(PlayerNotAvailableException &) {
        fail = false;
    }

    Assert(fail != true, "testWithExternalPlayerShutdown 2");

    try {
        fail = true;
        pPf->getPlayedFile();
    }
    catch(PlayerNotAvailableException &) {
        fail = false;
    }

    Assert(fail != true, "testWithExternalPlayerShutdown 3");
}
//---------------------------------------------------------------------------
void testBasicFunctions(PlayerFacade *pPf)
{
    bool fail;

    pPf->play(song1);
    Sleep(2000);
    Assert(pPf->getStatus() == PLAYER_PLAYING, "testBasicFunctions 1");
    Assert(pPf->getPlayedFile() == song1, "testBasicFunctions 2");

    pPf->enqueue(song2);
    Sleep(500);
    Assert(pPf->getStatus() == PLAYER_PLAYING, "testBasicFunctions 3");
    Assert(pPf->getPlayedFile() == song1, "testBasicFunctions 4");

    pPf->pause();
    Sleep(100);
    Assert(pPf->getStatus() == PLAYER_PAUSED, "testBasicFunctions 5");

    pPf->pause();
    Sleep(100);
    Assert(pPf->getStatus() == PLAYER_PLAYING, "testBasicFunctions 6");

    pPf->stop();
    Sleep(100);
    Assert(pPf->getStatus() == PLAYER_STOPPED, "testBasicFunctions 7");

    pPf->nextTrack();
    Sleep(100);
    Assert(pPf->getPlayedFile() == song2, "testBasicFunctions 8");

    pPf->previousTrack();
    pPf->play();
    Sleep(200);
    Assert(pPf->getPlayedFile() == song1, "testBasicFunctions 9");
    Assert(pPf->getStatus() == PLAYER_PLAYING, "testBasicFunctions 10");

    pPf->saveAndStop();
    Sleep(100);
    Assert(pPf->getStatus() == PLAYER_STOPPED, "testBasicFunctions 11");

    pPf->resumePlay();
    Sleep(100);
    Assert(pPf->getStatus() == PLAYER_PLAYING, "testBasicFunctions 12");
    Assert(pPf->getPlayedFile() == song1, "testBasicFunctions 13");

//    TStringList *list = new TStringList;
//    list->Add(song4);
//    list->Add(song3);
//    list->Add(song2);
//    list->Add(song1);
//
//    pPf->playMultiple(list);
//    delete list;
//    Sleep(100);
//    Assert(pPf->getPlayedFile() == song4, "testBasicFunctions 14");
//    Assert(pPf->getStatus() == PLAYER_PLAYING, "testBasicFunctions 15");
}

