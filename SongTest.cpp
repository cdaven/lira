//---------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <vcl.h>
#include <wtypes.h>
#include <winbase.h>

#include "../lib/Exceptions.h"
#include "../lib/extlib.h"
#include "SongFacade.h"
#include "ConcreteSongFacade.h"
#include "SongProperty.h"
#include "FileManager.h"
#include "SongManager.h"
#include "../ImportExport/ImportExportFacade.h"
#include "../ImportExport/ConcreteImportExportFacade.h"
#include "../Playlist/ConcretePlaylistFacade.h"
#include "../Playlist/PlaylistFacade.h"
#include "../Player/ConcretePlayerFacade.h"
#include "../Player/PlayerFacade.h"
#include "../MediatorInterface.h"
#include "../Mediator.h"
//---------------------------------------------------------------------------
#pragma argsused
int main(int argc, char* argv[])
{
    // initialisering...
    MediatorInterface *mediator = new Mediator();
    SongFacade *song = new ConcreteSongFacade(mediator);
    PlaylistFacade *playlist = new ConcretePlaylistFacade(mediator);
    ImportExportFacade *importexport = new ConcreteImportExportFacade();
    PlayerFacade *player = new ConcretePlayerFacade();

    ((Mediator*)mediator)->setSongFacade(song);
    ((Mediator*)mediator)->setPlaylistFacade(playlist);
    ((Mediator*)mediator)->setImportExportFacade(importexport);
    ((Mediator*)mediator)->setPlayerFacade(player);

    player->setPlayer("Winamp2", "C:\\Program Files\\Winamp\\Winamp.exe");
    // ----

//    int start = GetTickCount();
//    song->updatePath("E:\\mp3test");
//    int stop = GetTickCount();
//
//    cout << (stop - start) << "\n\n";
//
//    vector<int> songs;
//    SongProperty property;
//    property.addProperty("title", "*");
//
//    song->getSongsMatchingProperty(&songs, property);
//
//    for(int i = 0; i < songs.size(); i++) {
//        song->getSongProperties(i, &property);
//        cout << property.getPropertyRightValue("title") << "\n";
//    }

    // upprensning...
    delete mediator;
    delete song;
    delete playlist;
    delete importexport;
    delete player;

    cout << "klart!\n";
    Pause();

    return 0;
}
//---------------------------------------------------------------------------
 