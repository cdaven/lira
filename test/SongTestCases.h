#ifndef TESTCASESH
#define TESTCASESH

#include "TestCase.h"
#include "..\Song\SongFacade.h"
#include "..\Song\SongProperty.h"
#include "..\Song\FileManager.h"
//---------------------------------------------------------------------------
class SongProperty_ : public TestCase
{
public:
    SongProperty_();

    void count();
    void isEmptyButForIndex();
    void clear();
    void getPropertyLeftValue();
    void getPropertyRightValueInt();
    void getPropertyRightValueString();
    void setPropertyRightValue();
    void addProperty();
};
//---------------------------------------------------------------------------
class SongTag_ : public TestCase
{
public:
    SongTag_();

    void getsetAlbum();
    void getsetBand();
    void getsetBitrate();
    void getsetBPM();
    void getsetComment();
    void getsetComposer();
    void getsetConductor();
    void getsetContentType();
    void getsetCover();
    void getsetEncoder();
    void getsetInterpreter();
    void getsetKey();
    void getsetLanguages();
    void getsetLeadArtist();
    void getsetLength();
    void getsetLyricist();
    void getsetLyrics();
    void getsetMood();
    void getsetOriginalAlbum();
    void getsetOriginalArtists();
    void getsetOriginalLyricist();
    void getsetOriginalReleaseTime();
    void getsetPartOfSet();
    void getsetPublisher();
    void getsetRating();
    void getsetRecordingTime();
    void getsetReleaseTime();
    void getsetRemix();
    void getsetSituation();
    void getsetSubtitle();
    void getsetTempo();
    void getsetTitle();
    void getsetTrackNo();
};
//---------------------------------------------------------------------------
//class FileManagerX : public FileManager
//{
//public:
//    FileManagerX() : FileManager((SongFacade *)&DummySongFacade()) {}
//};

class DummySongFacade : public SongFacade
{
public:
    DummySongFacade();

    virtual int addSong(const AnsiString &);
    virtual void removeSong(int);
    virtual vector<int> getSongsMatchingProperties(const SongProperty &) const;
    virtual void getSongProperties(int, SongProperty *) const;
    virtual void updateDatabase(vector<int>) const;

    virtual void readFromDatabase() {}
    virtual int countSongs() const {}
    virtual void refreshSongTag(int) {}
    virtual void setSongProperties(int, const SongProperty &) {}
    virtual void playSong(int) const {}
    virtual void playMultipleSongs(intvector) const {}
    virtual void copyFile(const AnsiString &, const AnsiString &) const {}
    virtual void moveFile(const AnsiString &, const AnsiString &) const {}
    virtual void removeSongFile(int) {}
    virtual void copyFolder(const AnsiString &, const AnsiString &) const {}
    virtual void moveFolder(const AnsiString &, const AnsiString &) const {}
    virtual void removeFolder(const AnsiString &) const {}
    virtual void updatePath(const AnsiString &) const {}
    virtual void removeSongFromPlaylists(int) const {}
    virtual void playSongInPlayer(const AnsiString &) const {}
    virtual void playMultipleSongsInPlayer(ansistringvector) const {}
    virtual AnsiString getPlayedFilename() const {}
    virtual void saveAndStop() const {}
    virtual void resumePlay() const {}
    virtual const TagImpEx *createTagImpEx(const AnsiString &) const {}
    virtual std::vector<SongProperty> getSongsFromDatabase() const {}
    virtual void updateDatabase(int, const SongProperty &) const {}

    AnsiString existingsong, changedsong, removedsong, newsong1, newsong2;
    AnsiString existingsongsize, changedsongsize, removedsongsize;
    int esong, csong, rsong, nsong1, nsong2, csong2;
    vector<AnsiString> addedsongs;
    vector<int> removedsongs;
    vector<int> database;
};

class FileManager_ : public TestCase
{
public:
    FileManager_();

    void moveFile();
    void copyFile();
    void removeFile();
    void renameFile();
    void copyFolder();
    void moveFolder();
    void removeFolder();

    void updatePath();
    void getFileFromList();
    void compareFiles();
    void traverseAndCheckPath();
    void removeSongsNotFound();
};

//---------------------------------------------------------------------------
#endif
