#ifndef PLAYERINTERFACE_H_HEADER_INCLUDED_C0E3A1D8
#define PLAYERINTERFACE_H_HEADER_INCLUDED_C0E3A1D8

#include "../Constants.h"

class NoPlayerException : public Exception
{
public:
    NoPlayerException(AnsiString);
};
inline NoPlayerException::NoPlayerException(AnsiString a_msg) : Exception(a_msg) {}

class Player;

class PlayerFacade
{
public:
    virtual ~PlayerFacade() = 0;

    virtual void setPlayer(AnsiString, AnsiString) = 0;
    virtual void play(AnsiString) const = 0;
    virtual void play() const = 0;
    virtual void playMultiple(const stringvector) const = 0;
    virtual void pause() const = 0;
    virtual void stop() const = 0;
    virtual void nextTrack() const = 0;
    virtual void previousTrack() const = 0;
    virtual void enqueue(AnsiString) const = 0;
    virtual int getStatus() const = 0;
    virtual AnsiString getPlayedFile() const = 0;
    virtual void saveAndStop() const = 0;
    virtual void resumePlay() const = 0;
    virtual void close() const = 0;
};

PlayerFacade::~PlayerFacade()
{
}

#endif /* PLAYERINTERFACE_H_HEADER_INCLUDED_C0E3A1D8 */
