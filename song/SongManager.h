#ifndef SONGMANAGER_H_INCLUDE_BLAHBLAH
#define SONGMANAGER_H_INCLUDE_BLAHBLAH

#include "Song.h"
#include "../Constants.h"

class SongProperty;
class SongFacade;

using namespace std;

typedef map<int, Song> songmap;

class SongManager
{
public:
    SongManager() {}
    SongManager(const SongFacade *);

    void readFromDatabase();
    int  countSongs() const
        { return m_songs.size(); }

    int  addSong(const AnsiString &);
    void removeSong(int);

    void refreshSongTag(int);

    void getAllSongProperties(int, SongProperty *) const;
    void getSongProperties(int, SongProperty *) const;
    void setSongProperties(int, const SongProperty &);
    intvector getSongsMatchingProperties(const SongProperty &) const;

    AnsiString  getSongFilename(int) const;
    void        setSongFilename(int, const AnsiString &);

    void playSong(int) const;
    void playMultipleSongs(intvector) const;

private:
    int getFirstFreeIndex() const;
    songmap::const_iterator getConstSong(int) const;
    songmap::iterator getSong(int);
    bool wildCardMatch(const AnsiString &, const AnsiString &) const;
    void checkIntegrity() const;
    bool isGenreEqual(AnsiString, AnsiString) const;

    const SongFacade *m_pSongfacade;
    songmap m_songs;
};

#endif

