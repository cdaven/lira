#ifndef CONCRETESONGFACADE_H_HEADER_INCLUDED_
#define CONCRETESONGFACADE_H_HEADER_INCLUDED_

#include "SongFacade.h"
#include "FileManager.h"
#include "SongManager.h"
#include "../ImportExport/ImportExportFacade.h"
#include "../Playlist/PlaylistFacade.h"
#include "../Player/PlayerFacade.h"
#include "../MediatorInterface.h"
#include "../Constants.h"

class ConcreteSongFacade : public SongFacade
{
public:
    ConcreteSongFacade(const MediatorInterface *);
    virtual ~ConcreteSongFacade();

    virtual void readFromDatabase()
        { m_songmanager.readFromDatabase(); }

    virtual int countSongs() const
        { return m_songmanager.countSongs(); }

    virtual int addSong(const AnsiString &a_filename)
        { return m_songmanager.addSong(a_filename); }
    virtual void removeSong(int a_song)
        { m_songmanager.removeSong(a_song); }

    virtual void refreshSongTag(int a_song)
        { m_songmanager.refreshSongTag(a_song); }

    virtual void getSongProperties(int a_song, SongProperty *a_properties) const
        { m_songmanager.getSongProperties(a_song, a_properties); }
    virtual void setSongProperties(int a_song, const SongProperty &a_properties)
        { m_songmanager.setSongProperties(a_song, a_properties); }

    virtual intvector getSongsMatchingProperties(const SongProperty &a_sp) const;
    virtual void playSong(int a_song) const
        { m_songmanager.playSong(a_song); }
    virtual void playMultipleSongs(intvector a_songs) const
        { m_songmanager.playMultipleSongs(a_songs); }

    virtual void copyFile(const AnsiString &a_source, const AnsiString &a_destination) const
        { m_filemanager.copyFile(a_source, a_destination); }
    virtual void moveFile(const AnsiString &a_source, const AnsiString &a_destination) const
        { m_filemanager.copyFile(a_source, a_destination); }
    virtual void removeSongFile(int);

    virtual void copyFolder(const AnsiString &a_source, const AnsiString &a_destination) const
        { m_filemanager.copyFolder(a_source, a_destination); }
    virtual void moveFolder(const AnsiString &a_source, const AnsiString &a_destination) const
        { m_filemanager.moveFolder(a_source, a_destination); }
    virtual void removeFolder(const AnsiString &a_folder) const
        { m_filemanager.removeFolder(a_folder); }

    virtual void updatePath(const AnsiString &a_path)
        { m_filemanager.updatePath(a_path); }

    virtual void removeSongFromPlaylists(int a_song) const
        { m_pMediator->removeSongFromPlaylists(a_song); }
    virtual void playSongInPlayer(const AnsiString &) const;
    virtual void playMultipleSongsInPlayer(ansistringvector) const;
    virtual AnsiString getPlayedFilename() const;
    virtual void saveAndStop() const
        { m_pMediator->saveAndStop(); }
    virtual void resumePlay() const
        { m_pMediator->resumePlay(); }
    virtual const TagImpEx *createTagImpEx(const AnsiString &) const;

    virtual vector<SongProperty> getSongsFromDatabase() const;
    virtual void updateDatabase(int a_song, const SongProperty &a_properties) const
        { m_pMediator->updateSongDatabase(a_song, a_properties); }
    virtual void updateDatabase(intvector) const;

private:
    FileManager m_filemanager;
    SongManager m_songmanager;

    const MediatorInterface *m_pMediator;
};

#endif
