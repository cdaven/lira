#ifndef PLAYERCONTROLLER_H_HEADER_INCLUDED_C0E39A40
#define PLAYERCONTROLLER_H_HEADER_INCLUDED_C0E39A40

#include <string>
#include <vector>
#include <vcl/system.hpp> // AnsiString
#include "PlayerFacade.h"
#include "Player.h"
#include "../Constants.h"

// Skapar och tillhandahåller en spelare.
class ConcretePlayerFacade : public PlayerFacade
{
public:
    ConcretePlayerFacade();
    virtual ~ConcretePlayerFacade();

    virtual void setPlayer(AnsiString, AnsiString);
    virtual void play(AnsiString) const;
    virtual void play() const { m_player->play(); }
    virtual void playMultiple(const stringvector) const;
    virtual void enqueue(AnsiString) const;
    virtual void pause() const { m_player->pause(); }
    virtual void stop() const { m_player->stop(); }
    virtual void nextTrack() const { m_player->nextTrack(); }
    virtual void previousTrack() const { m_player->previousTrack(); }
    virtual int getStatus() const;
    virtual AnsiString getPlayedFile() const { return m_player->getPlayedFile(); }
    virtual void saveAndStop() const { m_player->saveAndStop(); }
    virtual void resumePlay() const { m_player->resumePlay(); }
    virtual void close() const { m_player->close(); }

private:
    void deletePlayer();
    void integrityCheck() const;

    Player *m_player;
};

#endif /* PLAYERCONTROLLER_H_HEADER_INCLUDED_C0E39A40 */
