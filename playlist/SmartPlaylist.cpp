#include "SmartPlaylist.h"
#include "PlaylistManager.h"

SmartPlaylist::SmartPlaylist()
{
    // map kräver att denna konstruerare finns
    m_pPlaylistmanager = 0;
}

SmartPlaylist::SmartPlaylist(AnsiString a_name, const SongProperty &a_properties,
    const PlaylistManager *a_pPlaylistmanager)
{
    SmartPlaylist();
    m_name = a_name;
    m_properties = a_properties;
    m_pPlaylistmanager = a_pPlaylistmanager;
}

vector<int> SmartPlaylist::getSongs() const
{
    if(m_pPlaylistmanager == 0)
        throw Exception("SmartPlaylist::getSongs");

    return m_pPlaylistmanager->getSongsMatchingProperties(m_properties);
}

