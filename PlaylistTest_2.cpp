//---------------------------------------------------------------------------
#include <iostream>
#include <vcl.h>
#include "ConcretePlaylistFacade.h"
#include "PlaylistFacade.h"
#include "../Song/SongFacade.h"
#include "../Song/ConcreteSongFacade.h"
#include "../Song/SongProperty.h"
#include "../Song/FileManager.h"
#include "../Song/SongManager.h"
#include "../ImportExport/ImportExportFacade.h"
#include "../ImportExport/ConcreteImportExportFacade.h"
#include "../Player/ConcretePlayerFacade.h"
#include "../Player/PlayerFacade.h"
#include "../MediatorInterface.h"
#include "../Mediator.h"
#include "../lib/Exceptions.h"

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

    song->updatePath("e:\\mp3test");
    playlist->newSimplePlaylist("alfa");

    SongProperty sp;
    sp.addProperty("lead artist", "neWs*");
    playlist->newSmartPlaylist("beta", sp);

    playlist->addSongToPlaylist(1, "alfa");
    playlist->addSongToPlaylist(3, "alfa");
    playlist->addSongToPlaylist(5, "alfa");
    playlist->addSongToPlaylist(14, "alfa");

    playlist->playPlaylist("beta");

    // upprensning...
    delete mediator;
    delete song;
    delete playlist;
    delete importexport;
    delete player;

    cout << "klart!\n";
    char c;
    cin >> c;

    return 0;
}
//---------------------------------------------------------------------------
 