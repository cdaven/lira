#include "../Headers.h"
#pragma hdrstop

#include "ConcretePlayerFacade.h"
#include "Winamp2Player.h"
#include "WindowsMediaPlayer.h"
#include "../Exceptions.h"

using namespace std;

ConcretePlayerFacade::ConcretePlayerFacade()
{
    m_player = 0;
}

ConcretePlayerFacade::~ConcretePlayerFacade()
{
    deletePlayer();
}

void ConcretePlayerFacade::setPlayer(AnsiString a_playertype, AnsiString a_playerpath)
{
    if(!FileExists(a_playerpath))
        throw FileNotFoundException(a_playerpath);

    // BUGGVARNING! Om en felaktig spelare eller sökväg läggs in
    // -- ska det fortfarande finnas en spelare, eller ska det
    // vara tomt?

    if(a_playertype == "Winamp2") {
        deletePlayer();
        m_player = new Winamp2Player(a_playerpath);
    }
    if(a_playertype == "WMP9") {
        deletePlayer();
        m_player = new WindowsMediaPlayer(a_playerpath);
    }

    if(m_player == 0)
        throw InvalidPlayerTypeException(a_playertype);
}

void ConcretePlayerFacade::play(AnsiString a_song) const
{
    integrityCheck();
    if(!FileExists(a_song))
        throw FileNotFoundException("ConcretePlayerFacade::play");

    m_player->play(a_song);
}

void ConcretePlayerFacade::playMultiple(const vector<string> a_songs) const
{
    integrityCheck();
    AnsiString tempfile;

    for(unsigned int i = 0; i < a_songs.size(); i++) {
        tempfile = AnsiString(a_songs[i].c_str());

        if(!FileExists(tempfile))
            throw FileNotFoundException(tempfile);
    }

    m_player->playMultiple(a_songs);
}

void ConcretePlayerFacade::enqueue(AnsiString a_song) const
{
    integrityCheck();
    if(!FileExists(a_song))
        throw FileNotFoundException("ConcretePlayerFacade::enqueue");

    m_player->enqueue(a_song);
}

int ConcretePlayerFacade::getStatus() const
{
    integrityCheck();
    return m_player->getStatus();
}

void ConcretePlayerFacade::deletePlayer()
{
    if(m_player) {
        delete m_player;
        m_player = 0;
    }
}

void ConcretePlayerFacade::integrityCheck() const
{
    if(m_player == NULL)
        throw NoPlayerException("ConcretePlayerFacade::integrityCheck");
}

