#ifndef DATABASEENGINE_H_HEADER_INCLUDED_C0C8D470
#define DATABASEENGINE_H_HEADER_INCLUDED_C0C8D470

#include <vector>
#include "../Song/SongProperty.h"
#include "../Playlist/PlaylistTransfer.h"

class DatabaseEngine
{
public:
    virtual ~DatabaseEngine();

    virtual std::vector<SongProperty>   getSongs() const = 0;
    virtual void                        updateSong(int, const SongProperty &) const = 0;
    virtual void                        updateSongs(std::vector<SongProperty>) const = 0;

//    virtual vector<SmartPlaylistTransfer>   getSmartPlaylists() const = 0;
//    virtual vector<SimplePlaylistTransfer>  getSimplePlaylists() const = 0;
//
//    virtual void    updatePlaylist(const SmartPlaylistTransfer &) const = 0;
//    virtual void    updatePlaylist(const SimplePlaylistTransfer &) const = 0;
};

DatabaseEngine::~DatabaseEngine()
{
}

#endif /* DATABASEENGINE_H_HEADER_INCLUDED_C0C8D470 */
