#ifndef SMARTPLAYLIST_H_HEADER_INCLUDED_C0E065D4
#define SMARTPLAYLIST_H_HEADER_INCLUDED_C0E065D4

#include "Playlist.h"
#include "../Song/SongProperty.h"
#include "../Constants.h"

class PlaylistManager;

class SmartPlaylist : public Playlist
{
public:
    SmartPlaylist();
    SmartPlaylist(AnsiString, const SongProperty &, const PlaylistManager *);

    virtual intvector getSongs() const;
    virtual AnsiString getName() const { return m_name; }

    void getProperties(SongProperty *a_properties) const { *a_properties = m_properties; }
    void setProperties(const SongProperty &a_properties) { m_properties = a_properties; }

private:
    SongProperty m_properties;
    const PlaylistManager *m_pPlaylistmanager;
};

#endif /* SMARTPLAYLIST_H_HEADER_INCLUDED_C0E065D4 */
