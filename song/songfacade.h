#ifndef SONGFACADE_H_HEADER_INCLUDED_C0C8F240
#define SONGFACADE_H_HEADER_INCLUDED_C0C8F240

#include "SongProperty.h"
#include "../ImportExport/TagImpEx.h"
#include "../Constants.h"

class PlaylistFacade;

class SongFacade
{
public:
    virtual ~SongFacade();

    virtual void readFromDatabase() = 0;

    virtual int countSongs() const = 0;

    virtual int addSong(const AnsiString &) = 0;
    virtual void removeSong(int) = 0;

    virtual void refreshSongTag(int) = 0;

    virtual void getSongProperties(int, SongProperty *) const = 0;
    virtual void setSongProperties(int, const SongProperty &) = 0;

    virtual intvector getSongsMatchingProperties(const SongProperty &) const = 0;
    virtual void playSong(int) const = 0;
    virtual void playMultipleSongs(intvector) const = 0;

    virtual void copyFile(const AnsiString &, const AnsiString &) const = 0;
    virtual void moveFile(const AnsiString &, const AnsiString &) const = 0;
    virtual void removeSongFile(int) = 0;

    // xxxFolder är ännu ej fullt implementerade 
    virtual void copyFolder(const AnsiString &, const AnsiString &) const = 0;
    virtual void moveFolder(const AnsiString &, const AnsiString &) const = 0;
    virtual void removeFolder(const AnsiString &) const = 0;

    virtual void updatePath(const AnsiString &) const = 0;

    virtual void removeSongFromPlaylists(int) const = 0;
    virtual void playSongInPlayer(const AnsiString &) const = 0;
    virtual void playMultipleSongsInPlayer(ansistringvector) const = 0;
    virtual AnsiString getPlayedFilename() const = 0;
    virtual void saveAndStop() const = 0;
    virtual void resumePlay() const = 0;
    virtual const TagImpEx *createTagImpEx(const AnsiString &) const = 0;

    virtual std::vector<SongProperty> getSongsFromDatabase() const = 0;
    virtual void updateDatabase(int, const SongProperty &) const = 0;
    virtual void updateDatabase(intvector) const = 0;
};

SongFacade::~SongFacade()
{
}

#endif /* SONGFACADE_H_HEADER_INCLUDED_C0C8F240 */
