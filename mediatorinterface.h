#ifndef MEDIATOR_INTERFACE_HEADER_BLAHBLAH
#define MEDIATOR_INTERFACE_HEADER_BLAHBLAH

#include "../Song/SongProperty.h"
#include "../Constants.h"

class SongProperty;
class TagImpEx;

using namespace std;

class MediatorInterface {
public:
//    virtual ~MediatorInterface();

    virtual void playSongs(stringvector) const = 0;               // Playlist/Song -> Player
    virtual void getSongProperties(int, SongProperty *) const = 0;  // Playlist -> Song
    virtual intvector getSongsMatchingProperties(const SongProperty &) const = 0; // Playlist -> Song
    virtual void removeSongFromPlaylists(int) const = 0;            // Song -> Playlist
    virtual AnsiString getPlayedFilename() const = 0;               // Song -> Player
    virtual void saveAndStop() const = 0;                           // Song -> Player
    virtual void resumePlay() const = 0;                            // Song -> Player
    virtual const TagImpEx *createTagImpEx(AnsiString) const = 0;   // Song -> ImportExport
    virtual vector<SongProperty> getSongsFromDatabase() const = 0;           // Song -> Database
    virtual void updateSongDatabase(int, const SongProperty &) const = 0;
    virtual void updateSongDatabase(vector<SongProperty>) const = 0;
};

#endif
 