#ifndef PLAYLISTMANAGER_H_HEADER_INCLUDED_C0E0638B
#define PLAYLISTMANAGER_H_HEADER_INCLUDED_C0E0638B

#include "SimplePlaylist.h"
#include "SmartPlaylist.h"
#include "../song/SongProperty.h"
#include "../Constants.h"

typedef std::map<std::string, SmartPlaylist> smartplaylistmap;
typedef std::map<std::string, SimplePlaylist> simpleplaylistmap;

class PlaylistImpEx;
class PlaylistFacade;
class Playlist;

class PlaylistManager
{
public:
    PlaylistManager();
    ~PlaylistManager();

    void setFacade(const PlaylistFacade *);

    void newSimplePlaylist(AnsiString);
    void addSongToPlaylist(int, AnsiString);
    void removeSongFromPlaylist(int, AnsiString);
    void removeSongFromAllPlaylists(int);

    void newSmartPlaylist(AnsiString, const SongProperty &);
    void getSmartPlaylistProperties(AnsiString, SongProperty *) const;
    void setSmartPlaylistProperties(AnsiString, const SongProperty &);

    void removePlaylist(AnsiString);

    stringvector getAllPlaylistNames() const;
    intvector getSongsInPlaylist(AnsiString) const;
    void playPlaylist(AnsiString) const;

    void exportPlaylist(const PlaylistImpEx *) const;
    Playlist *importPlaylist(const PlaylistImpEx *, AnsiString);

    // utåt mot fasaden
    void getSongProperties() const; // ev. överflödig
    intvector getSongsMatchingProperties(const SongProperty &) const;

private:
    void savePlaylist(AnsiString) const;
    void checkIntegrity() const;

    simpleplaylistmap m_simpleplaylists;
    smartplaylistmap m_smartplaylists;

    // BUGGVARNING! om "någon" raderar (delete) dessa objekt
    // och jag vill komma åt dem blir det allvarligt fel!
    const PlaylistFacade *m_pPlaylistfacade;
};

#endif /* PLAYLISTMANAGER_H_HEADER_INCLUDED_C0E0638B */
