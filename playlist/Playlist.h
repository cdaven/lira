#ifndef PLAYLIST_H_HEADER_INCLUDED_C0E00CBE
#define PLAYLIST_H_HEADER_INCLUDED_C0E00CBE

#include "../Constants.h"

class Playlist
{
public:
    virtual intvector getSongs() const = 0;
    virtual AnsiString getName() const = 0;

protected:
    AnsiString m_name;
};

#endif /* PLAYLIST_H_HEADER_INCLUDED_C0E00CBE */
