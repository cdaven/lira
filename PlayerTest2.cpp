//---------------------------------------------------------------------------
#include <vector>
#include <string>

#include <vcl.h>
#include <winbase.h>

#include "Player.h"
#include "WindowsMediaPlayer.h"
#include "ConcretePlayerFacade.h"
#include "PlayerFacade.h"
//---------------------------------------------------------------------------
#pragma argsused
int main(int argc, char* argv[])
{
    PlayerFacade *pf = new ConcretePlayerFacade();
    pf->setPlayer("WMP9", "C:\\Program Files\\Windows Media Player\\wmplayer.exe");

    std::vector<std::string> songlist;
    std::string song;

    song = "E:\\MP3\\Klassiskt\\Johann Strauss - The Blue Danube.mp3";
    songlist.push_back(song);

    song = "E:\\MP3\\Klassiskt\\Carl Orff - Fortuna Imperatix Mundi.mp3";
    songlist.push_back(song);

    song = "E:\\MP3\\Folkmusik\\Orsa spelmän - Brudmarsch från Delsbo.mp3";
    songlist.push_back(song);

    song = "E:\\MP3\\Reggae\\UB40 - Can't Help Falling in Love.mp3";
    songlist.push_back(song);

    pf->playMultiple(songlist);

    delete pf;

    return 0;
}
//---------------------------------------------------------------------------
 