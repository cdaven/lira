#ifndef MEDIATOR_HEADER_BLAHBLAH
#define MEDIATOR_HEADER_BLAHBLAH

#include "MediatorInterface.h"
#include "../Constants.h"

class ImportExportFacade;
class PlayerFacade;
class PlaylistFacade;
class SongFacade;
class DatabaseEngine;

// Som en 'eter' mellan fasaderna för kontrollerad kommunikation

class Mediator : public MediatorInterface
{
public:
//    virtual ~Mediator();
    Mediator();

    virtual void playSongs(stringvector) const;     // Playlist/Song -> Player
    virtual void getSongProperties(int, SongProperty *) const;  // Playlist -> Song
    virtual intvector getSongsMatchingProperties(const SongProperty &) const; // Playlist -> Song

    virtual void removeSongFromPlaylists(int) const;            // Song -> Playlist
    virtual AnsiString getPlayedFilename() const;               // Song -> Player
    virtual void saveAndStop() const;                           // Song -> Player
    virtual void resumePlay() const;                            // Song -> Player
    virtual const TagImpEx *createTagImpEx(AnsiString) const;   // Song -> ImportExport
    virtual vector<SongProperty> getSongsFromDatabase() const;  // Song -> Database
    virtual void updateSongDatabase(int, const SongProperty &) const;
    virtual void updateSongDatabase(vector<SongProperty>) const;

    void setImportExportFacade(ImportExportFacade *const a) { m_pImportexportfacade = a; }
    void setPlayerFacade(PlayerFacade *const a)             { m_pPlayerfacade = a; }
    void setPlaylistFacade(PlaylistFacade *const a)         { m_pPlaylistfacade = a; }
    void setSongFacade(SongFacade *const a)                 { m_pSongfacade = a; }
    void setDatabaseEngine(DatabaseEngine *const a)         { m_pDatabaseengine = a; }

private:
    ImportExportFacade  *m_pImportexportfacade;
    PlayerFacade        *m_pPlayerfacade;
    PlaylistFacade      *m_pPlaylistfacade;
    SongFacade          *m_pSongfacade;
    DatabaseEngine      *m_pDatabaseengine;
};

#endif