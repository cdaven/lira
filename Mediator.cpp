#include "../Headers.h"
#pragma hdrstop

#include "Mediator.h"
#include "../Player/PlayerFacade.h"
#include "../ImportExport/ImportExportFacade.h"
#include "../ImportExport/TagImpEx.h"
#include "../Playlist/PlaylistFacade.h"
#include "../Song/SongFacade.h"
#include "../Song/SongProperty.h"
#include "../Database/DatabaseEngine.h"
#include "../Exceptions.h"
#include "../Constants.h"

using namespace std;

Mediator::Mediator()
{
    m_pImportexportfacade   = 0;
    m_pPlayerfacade         = 0;
    m_pPlaylistfacade       = 0;
    m_pSongfacade           = 0;
    m_pDatabaseengine       = 0;
}

void Mediator::playSongs(vector<string> a_songfilenames) const
{
    if(m_pPlayerfacade == 0)
        throw Exception("Mediator::playSongs");

    m_pPlayerfacade->playMultiple(a_songfilenames);
}

void Mediator::getSongProperties(int a_song, SongProperty *a_property) const
{
    if(m_pSongfacade == 0)
        throw Exception("Mediator::getSongProperties");

    m_pSongfacade->getSongProperties(a_song, a_property);
}

intvector Mediator::getSongsMatchingProperties(const SongProperty &a_properties) const
{
    if(m_pSongfacade == 0)
        throw Exception("Mediator::getSongProperties");

    return m_pSongfacade->getSongsMatchingProperties(a_properties);
}

void Mediator::removeSongFromPlaylists(int a_song) const
{
//    if(m_pPlaylistfacade == 0)
//        throw Exception("Mediator::removeSongFromPlaylists");
//
//    m_pPlaylistfacade->removeSongFromAllPlaylists(a_song);
}

AnsiString Mediator::getPlayedFilename() const
{
    if(m_pPlayerfacade == 0)
        throw Exception("Mediator::getPlayedFilename");

    return m_pPlayerfacade->getPlayedFile();
}

void Mediator::saveAndStop() const
{
    if(m_pPlayerfacade == 0)
        throw Exception("Mediator::saveAndStop");

    m_pPlayerfacade->saveAndStop();
}

void Mediator::resumePlay() const
{
    if(m_pPlayerfacade == 0)
        throw Exception("Mediator::resumePlay");

    m_pPlayerfacade->resumePlay();
}

const TagImpEx *Mediator::createTagImpEx(AnsiString a_tagtype) const
{
    if(m_pImportexportfacade == 0)
        throw Exception("Mediator::createTagImpEx");

    return m_pImportexportfacade->createTagImpEx(a_tagtype);
}

vector<SongProperty> Mediator::getSongsFromDatabase() const
{
    if(m_pDatabaseengine == 0)
        throw Exception("Mediator::getSongsFromDatabase");

    return m_pDatabaseengine->getSongs();
}

void Mediator::updateSongDatabase(int a_song, const SongProperty &a_properties) const
{
    if(m_pDatabaseengine == 0)
        throw Exception("Mediator::updateSongDatabase");

    m_pDatabaseengine->updateSong(a_song, a_properties);
}

void Mediator::updateSongDatabase(vector<SongProperty> a_songs) const
{
    if(m_pDatabaseengine == 0)
        throw Exception("Mediator::updateSongDatabase");

    m_pDatabaseengine->updateSongs(a_songs);
}

