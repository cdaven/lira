#ifndef WINDOWSMEDIAPLAYER_H_HEADER_INCLUDED_C0E3BEBC
#define WINDOWSMEDIAPLAYER_H_HEADER_INCLUDED_C0E3BEBC

#include "Player.h"
#include "../Constants.h"

class WindowsMediaPlayer : public Player
{
public:
    WindowsMediaPlayer(const AnsiString &a_path);

    virtual void setPlayerpath(const AnsiString &a_path) { m_playerpath = a_path; }
    virtual void play(const AnsiString &) const;
    virtual void play() const;
    virtual void enqueue(const AnsiString &) const;
    virtual void playMultiple(const stringvector) const;
    virtual void pause() const;
    virtual void stop() const;
    virtual void nextTrack() const;
    virtual void previousTrack() const;
    virtual void saveAndStop();
    virtual void resumePlay();
    virtual int getStatus() const;
    virtual AnsiString getPlayedFile() const;
    virtual void close() const;

private:
    void startPlayerExecutable(const AnsiString &) const;

    AnsiString m_playerclass;
};

#endif
