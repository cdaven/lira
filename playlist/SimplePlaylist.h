#ifndef SIMPLEPLAYLIST_H_HEADER_INCLUDED_C0E04E09
#define SIMPLEPLAYLIST_H_HEADER_INCLUDED_C0E04E09

#include "Playlist.h"
#include "../Constants.h"

// Inneh�ller en lista med index-v�rden �ver l�tar
class SimplePlaylist : public Playlist
{
public:
    SimplePlaylist();
    SimplePlaylist(AnsiString);

    virtual intvector getSongs() const;
    virtual AnsiString getName() const { return m_name; }

    void addSong(int);
    void removeSong(int);

private:
    intvector::iterator getPositionOfSong(int);

    intvector m_songs;
};

#endif /* SIMPLEPLAYLIST_H_HEADER_INCLUDED_C0E04E09 */
