//---------------------------------------------------------------------------
#include <iostream>
#include <vcl.h>

#include "ConcretePlaylistFacade.h"
#include "PlaylistFacade.h"
#include "../song/SongManager.h"
#include "../song/SongManagerInterface.h"
#include "../lib/Exceptions.h"
#include "../lib/extlib.h"

int songs[4] = { 7, 13, 2, 56 };
AnsiString playlists[2] = { "80-tal", "Elvis & The Beatles" };

PlaylistFacade *Test_prepare();
void Test_newSimplePlaylist(PlaylistFacade *);
void Test_addSongToPlaylist(PlaylistFacade *);
void Test_removeSongFromPlaylist(PlaylistFacade *);
void Test_removeSongFromAllPlaylists(PlaylistFacade *);
void Test_getAllPlaylistNames(PlaylistFacade *);
void Test_getSongsInPlaylist(PlaylistFacade *);
void Test_removeSimplePlaylist(PlaylistFacade *);

//void Test_playPlaylist(PlaylistFacade *);
//void Test_newSmartPlaylist(PlaylistFacade *);

bool fail;

SongManagerInterface *pSmi = 0;
PlaylistFacade *pPf = 0;

#pragma argsused
int main(int argc, char* argv[])
{
    cout << "Kör tester för Playlist...\n";

    try {
        Test_prepare();
        Test_newSimplePlaylist(pPf);
        Test_prepare();
        Test_addSongToPlaylist(pPf);
        Test_prepare();
        Test_removeSongFromPlaylist(pPf);
        Test_prepare();
        Test_removeSongFromAllPlaylists(pPf);
        Test_prepare();
        Test_getAllPlaylistNames(pPf);
        Test_prepare();
        Test_getSongsInPlaylist(pPf);
        Test_prepare();
        Test_removeSimplePlaylist(pPf);
    }
    catch(EAbort &e) {
        cout << "Ett oväntat undandtag inträffade: " << e.Message << "\n";
        Pause();
        exit(1);
    }

    delete pSmi;
    delete pPf;

    cout << "\nAlla tester kördes felfritt!\n";
    Pause();

    return 0;
}
//---------------------------------------------------------------------------
PlaylistFacade *Test_prepare()
{
    if(pSmi)
        delete pSmi;

    if(pPf)
        delete pPf;

    pPf = new ConcretePlaylistFacade(pSmi);

    fail = false;

    return pPf;
}

void Test_newSimplePlaylist(PlaylistFacade *pPf)
{
//    * Skapar ny spellista
//        - antal spellistor = 1
//        - spellista 1 = den nya
//    * Skapar ny spellista
//        - antal spellistor = 2
//        - spellista 1 = den nya eller den gamla
//        - spellista 2 = den nya eller den gamla
//    * Skapar ny spellista som redan finns

    pPf->newSimplePlaylist(playlists[0]);

    TStringList *pPnames = pPf->getAllPlaylistNames();
    Assert(pPnames->Count == 1, "Test_newSimplePlaylist 1a");
    Assert(pPnames->Strings[0] == playlists[0], "Test_newSimplePlaylist 1b");
    delete pPnames;

    pPf->newSimplePlaylist(playlists[1]);

    pPnames = pPf->getAllPlaylistNames();
    Assert(pPnames->Count == 2, "Test_newSimplePlaylist 2");
    Assert(pPnames->Strings[0] == playlists[0] || pPnames->Strings[0] == playlists[1], "Test_newSimplePlaylist 3a");
    Assert(pPnames->Strings[1] == playlists[0] || pPnames->Strings[1] == playlists[1], "Test_newSimplePlaylist 3b");
    delete pPnames;

    try {
        fail = true;
        pPf->newSimplePlaylist(playlists[0]);
    }
    catch(AlreadyInContainerException &) {
        fail = false;
    }
    Assert(fail == false, "Test_newSimplePlaylist 4");
}

void Test_addSongToPlaylist(PlaylistFacade *pPf)
{
//    * Lägg till låt till icke-existerande spellista då antal spellistor = 0
//    * Lägg till låt till icke-existerande spellista då antal spellistor = 1 (onödigt?)
//    * Lägg till 2 låtar till spellista
//        - antal låtar = 2
//        - låt 1 = tillagd låt 1
//        - låt 2 = tillagd låt 2
//    * Lägg till låt som redan finns i spellista

    try {
        fail = true;
        pPf->addSongToPlaylist(songs[0], playlists[0]);
    }
    catch(NotInContainerException &) {
        fail = false;
    }
    Assert(fail == false, "Test_addSongToPlaylist 1");

    pPf->newSimplePlaylist(playlists[0]);
    try {
        fail = true;
        pPf->addSongToPlaylist(songs[0], playlists[1]);
    }
    catch(NotInContainerException &) {
        fail = false;
    }
    Assert(fail == false, "Test_addSongToPlaylist 2");

    pPf->addSongToPlaylist(songs[0], playlists[0]);
    pPf->addSongToPlaylist(songs[1], playlists[0]);

    int no_songs = 0;
    int *pSongs = pPf->getSongsInPlaylist(playlists[0], &no_songs);
    Assert(no_songs == 2, "Test_addSongToPlaylist 3");
    for(int i = 0; i < no_songs; i++)
        Assert(pSongs[i] == songs[i], "Test_addSongToPlaylist 4." + IntToStr(i));
    delete[] pSongs;

    try {
        fail = true;
        pPf->addSongToPlaylist(songs[0], playlists[0]);
    }
    catch(AlreadyInContainerException &) {
        fail = false;
    }
    Assert(fail == false, "Test_addSongToPlaylist 5");

// Testa också (senare) att lägga till en låt som inte
// finns i SongManagers databas.

    cout << "Ännu ej implementerat test i Test_addSongToPlaylist\n";
}

void Test_removeSongFromPlaylist(PlaylistFacade *pPf)
{
//    * Ta bort låt från spellista som inte finns
//    * Ta bort låt som inte finns i spellista
//    * Ta bort låt som finns i spellista då antal låtar = 2
//        - antal låtar = 1
//        - låt 1 = 'den som inte togs bort'

    try {
        fail = true;
        pPf->removeSongFromPlaylist(songs[0], playlists[0]);
    }
    catch(NotInContainerException &) {
        fail = false;
    }
    Assert(fail == false, "Test_removeSongFromPlaylist 1");

    pPf->newSimplePlaylist(playlists[0]);

    try {
        fail = true;
        pPf->removeSongFromPlaylist(songs[0], playlists[0]);
    }
    catch(NotInContainerException &) {
        fail = false;
    }
    Assert(fail == false, "Test_removeSongFromPlaylist 2");

    pPf->addSongToPlaylist(songs[0], playlists[0]);
    pPf->addSongToPlaylist(songs[1], playlists[0]);

    pPf->removeSongFromPlaylist(songs[0], playlists[0]);

    int no_songs = 0;
    int *pSongs = pPf->getSongsInPlaylist(playlists[0], &no_songs);
    Assert(no_songs == 1, "Test_removeSongFromPlaylist 3");
    Assert(pSongs[0] == songs[1], "Test_removeSongFromPlaylist 4");
    delete[] pSongs;
}

void Test_removeSongFromAllPlaylists(PlaylistFacade *pPf)
{
//    (* Ta bort låt från alla spellistor då antal spellistor = 0) -- överflödigt
//    * Ta bort låt som inte finns från alla spellistor
//    * Ta bort låt från alla spellistor då antal spellistor = 1, antal låtar = 1
//        - antal låtar = 0
//    * Ta bort låt från alla spellistor då antal spellistor = 2, antal låtar = 2
//        - antal låtar = 1 (x2)
//        - låt 1 = 'den som inte togs bort' (x2)

    pPf->newSimplePlaylist(playlists[1]);

    try {
        fail = true;
        pPf->removeSongFromAllPlaylists(songs[0]);
    }
    catch(NotInContainerException &) {
        fail = false;
    }
    Assert(fail == false, "Test_removeSongFromAllPlaylists 1");

    pPf->addSongToPlaylist(songs[3], playlists[1]);
    pPf->removeSongFromAllPlaylists(songs[3]);

    int no_songs = 0;
    int *pSongs = pPf->getSongsInPlaylist(playlists[1], &no_songs);
    Assert(no_songs == 0, "Test_removeSongFromAllPlaylists 2");
    delete[] pSongs;

    pPf->newSimplePlaylist(playlists[0]);
    pPf->addSongToPlaylist(songs[1], playlists[0]);
    pPf->addSongToPlaylist(songs[2], playlists[0]);
    pPf->addSongToPlaylist(songs[2], playlists[1]);
    pPf->addSongToPlaylist(songs[4], playlists[1]);

    pPf->removeSongFromAllPlaylists(songs[2]);

    pSongs = pPf->getSongsInPlaylist(playlists[0], &no_songs);
    Assert(no_songs == 1, "Test_removeSongFromAllPlaylists 3a");
    Assert(pSongs[0] == songs[1], "Test_removeSongFromPlaylist 3b");
    delete[] pSongs;
    pSongs = pPf->getSongsInPlaylist(playlists[1], &no_songs);
    Assert(no_songs == 1, "Test_removeSongFromAllPlaylists 4a");
    Assert(pSongs[0] == songs[4], "Test_removeSongFromPlaylist 4b");
    delete[] pSongs;
}

void Test_getAllPlaylistNames(PlaylistFacade *pPf)
{
//    * Hämta alla spellistenamn då antal spellistor = 0
//        - antal spellistenamn = 0
//    * Hämta alla spellistenamn då antal spellistor = 1
//        - antal spellistenamn = 1
//        - spellistenamn 1 = spellista 1->namn

    TStringList *pPnames = pPf->getAllPlaylistNames();
    Assert(pPnames->Count == 0, "Test_getAllPlaylistNames 1");
    delete pPnames;

    pPf->newSimplePlaylist(playlists[0]);

    pPnames = pPf->getAllPlaylistNames();
    Assert(pPnames->Count == 1, "Test_getAllPlaylistNames 2a");
    Assert(pPnames->Strings[0] == playlists[0], "Test_getAllPlaylistNames 2b");
    delete pPnames;
}

void Test_getSongsInPlaylist(PlaylistFacade *pPf)
{
//    * Hämta låtar ur spellista som inte finns
//    * Hämta låtar ur spellista då antal låtar = 2
//        - antal hämtade låtar = 2
//        - hämtade låt 1 = låt 1
//        - hämtade låt 2 = låt 2

    try {
        fail = true;
        int songsize = 0;
        int *pSongs = pPf->getSongsInPlaylist(playlists[0], &songsize);
        delete pSongs;
    }
    catch(NotInContainerException &) {
        fail = false;
    }
    Assert(fail == false, "Test_getSongsInPlaylist 1");

    pPf->newSimplePlaylist(playlists[0]);
    pPf->addSongToPlaylist(songs[2], playlists[0]);
    pPf->addSongToPlaylist(songs[4], playlists[0]);

    int songsize = 0;
    int *pSongs = pPf->getSongsInPlaylist(playlists[0], &songsize);

    Assert(songsize == 2, "Test_getSongsInPlaylist 2");
    Assert(pSongs[0] == songs[2], "Test_getSongsInPlaylist 3a");
    Assert(pSongs[1] == songs[4], "Test_getSongsInPlaylist 3b");

    delete[] pSongs;
}

void Test_removeSimplePlaylist(PlaylistFacade *pPf)
{
//    * Ta bort en spellista som inte finns
//    * Ta bort en spellista som finns då antal spellistor = 2
//        - antal spellistor = 1
//        - spellista 1 = 'den som inte raderades'

    try {
        fail = true;
        pPf->removeSimplePlaylist(playlists[0]);
    }
    catch(NotInContainerException &) {
        fail = false;
    }
    Assert(fail == false, "Test_removeSimplePlaylist 1");

    pPf->newSimplePlaylist(playlists[0]);
    pPf->newSimplePlaylist(playlists[1]);

    pPf->removeSimplePlaylist(playlists[0]);

    TStringList *pPnames = pPf->getAllPlaylistNames();
    Assert(pPnames->Count == 1, "Test_removeSimplePlaylist 2a");
    Assert(pPnames->Strings[0] == playlists[1], "Test_removeSimplePlaylist 2b");
    delete pPnames;
}
