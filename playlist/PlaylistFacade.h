#ifndef PLAYLISTFACADE_H_HEADER_INCLUDED_C0E033B6
#define PLAYLISTFACADE_H_HEADER_INCLUDED_C0E033B6

#include "../song/SongProperty.h"
#include "../Constants.h"

class PlaylistManager;

class PlaylistFacade
{
public:
    virtual ~PlaylistFacade() = 0;

    virtual stringvector getAllPlaylistNames() const = 0;
    virtual void addSongToPlaylist(int, AnsiString) const = 0;
    virtual void removeSongFromPlaylist(int, AnsiString) const = 0;
    virtual void newSmartPlaylist(AnsiString, const SongProperty &) const = 0;
    virtual void newSimplePlaylist(AnsiString) const = 0;
    virtual void removePlaylist(AnsiString) const = 0;
    virtual void playPlaylist(AnsiString) const = 0;
    virtual void playPlaylistInPlayer(stringvector) const = 0;
    virtual intvector getSongsInPlaylist(AnsiString) const = 0;
    virtual void removeSongFromAllPlaylists(int) const = 0;
    virtual void getSongProperties(int, SongProperty *) const = 0; // ev. överflödig
    virtual intvector getSongsMatchingProperties(const SongProperty &) const = 0;
};

PlaylistFacade::~PlaylistFacade()
{
}

#endif /* PLAYLISTFACADE_H_HEADER_INCLUDED_C0E033B6 */
