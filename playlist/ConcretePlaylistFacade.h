#ifndef CONCRETEPLAYLISTFACADE_H_HEADER_INCLUDED
#define CONCRETEPLAYLISTFACADE_H_HEADER_INCLUDED

#include "PlaylistFacade.h"
#include "PlaylistManager.h"
#include "../song/SongProperty.h"
#include "../Constants.h"

class MediatorInterface;

class ConcretePlaylistFacade : public PlaylistFacade
{
public:
    ConcretePlaylistFacade(const MediatorInterface *);
    virtual ~ConcretePlaylistFacade();

    virtual void newSmartPlaylist(AnsiString a_playlist, const SongProperty &a_properties) const
        { m_pPlaylistmanager.newSmartPlaylist(a_playlist, a_properties); }
    virtual void newSimplePlaylist(AnsiString a_playlist) const
        { m_pPlaylistmanager.newSimplePlaylist(a_playlist); }
    virtual void removePlaylist(AnsiString a_playlist) const
        { m_pPlaylistmanager.removePlaylist(a_playlist); }

    virtual void addSongToPlaylist(int a_song, AnsiString a_playlist) const
        { m_pPlaylistmanager.addSongToPlaylist(a_song, a_playlist); }
    virtual void removeSongFromPlaylist(int a_song, AnsiString a_playlist) const
        { m_pPlaylistmanager.removeSongFromPlaylist(a_song, a_playlist); }
    virtual void removeSongFromAllPlaylists(int a_song) const
        { m_pPlaylistmanager.removeSongFromAllPlaylists(a_song); }

    virtual void playPlaylist(AnsiString a_playlist) const
        { m_pPlaylistmanager.playPlaylist(a_playlist);}
    virtual stringvector getAllPlaylistNames() const;
    virtual intvector getSongsInPlaylist(AnsiString) const;

    // "Utåt" till andra paket
    virtual void playPlaylistInPlayer(stringvector) const;
    virtual void getSongProperties(int, SongProperty *) const;
    virtual intvector getSongsMatchingProperties(const SongProperty &) const;

private:
    const MediatorInterface *m_pMediator;
    PlaylistManager m_pPlaylistmanager;
};

#endif
