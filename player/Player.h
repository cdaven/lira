#ifndef PLAYER_H_HEADER_INCLUDED_C0E381B6
#define PLAYER_H_HEADER_INCLUDED_C0E381B6

#include <vcl/system.hpp>
#include <vector>
#include <string>

#include "../Constants.h"

class Player
{
public:
    virtual void play(const AnsiString &) const = 0;
    virtual void play() const = 0;
    virtual void playMultiple(const stringvector) const = 0;
    virtual void pause() const = 0;
    virtual void stop() const = 0;
    virtual void nextTrack() const = 0;
    virtual void previousTrack() const = 0;
    virtual void enqueue(const AnsiString &) const = 0;
    virtual int getStatus() const = 0;
    virtual AnsiString getPlayedFile() const = 0;
    virtual void saveAndStop() = 0;
    virtual void resumePlay() = 0;
    virtual void setPlayerpath(const AnsiString &) = 0;
    virtual void close() const = 0;

protected:
    int m_savedposition;
    AnsiString m_savedfilename; // behövs iaf inte för Winamp2
    AnsiString m_playerpath;
};

#endif /* PLAYER_H_HEADER_INCLUDED_C0E381B6 */
