#ifndef CONCRETEDATABASEENGINE_H_BLAHBLAH
#define CONCRETEDATABASEENGINE_H_BLAHBLAH

#include "DatabaseEngine.h"
#include "../Song/SongProperty.h"
#include "../Playlist/PlaylistTransfer.h"
#include "../Constants.h"

class BadFileFormatException : public Exception
{
public:
    BadFileFormatException(AnsiString);
};
inline BadFileFormatException::BadFileFormatException(AnsiString a_msg) : Exception(a_msg)
{
}


class ConcreteDatabaseEngine : public DatabaseEngine
{
public:
    ConcreteDatabaseEngine();
    virtual ~ConcreteDatabaseEngine();

    virtual std::vector<SongProperty>   getSongs() const;
    virtual void                        updateSong(int, const SongProperty &) const;
    virtual void                        updateSongs(std::vector<SongProperty>) const;

//    virtual vector<SmartPlaylistTransfer>   getSmartPlaylists() const;
//    virtual vector<SimplePlaylistTransfer>  getSimplePlaylists() const;
//
//    virtual void    updatePlaylist(const SmartPlaylistTransfer &) const;
//    virtual void    updatePlaylist(const SimplePlaylistTransfer &) const;

private:
    void encodeData(std::string *) const;
    void decodeData(std::string *) const;

    inline std::string   getFirstPart(const std::string &) const;
//    void            replaceString(string *, const string &, const string &) const;
    stringvector    readFileData(const char[]) const;
    std::string     getSongData(const SongProperty &) const;
};

#endif
