#include "../Headers.h"
#pragma hdrstop

#include "ConcreteSongFacade.h"
#include "FileManager.h"
#include "SongManager.h"
#include "SongProperty.h"
#include "../ImportExport/ImportExportFacade.h"
#include "../Exceptions.h"
#include "../MediatorInterface.h"
#include "../Constants.h"

ConcreteSongFacade::ConcreteSongFacade(const MediatorInterface *a_pMediator)
    : m_filemanager(this), m_songmanager(this)
{
    if(a_pMediator == NULL)
        throw NullPointerException("ConcreteSongFacade::ConcreteSongFacade");

    m_pMediator = a_pMediator;
}

ConcreteSongFacade::~ConcreteSongFacade()
{
}

intvector ConcreteSongFacade::getSongsMatchingProperties(const SongProperty &a_sp) const
{
    return m_songmanager.getSongsMatchingProperties(a_sp);
}

void ConcreteSongFacade::removeSongFile(int a_song)
{
    m_filemanager.removeFile(m_songmanager.getSongFilename(a_song));
    removeSong(a_song);
}

void ConcreteSongFacade::playSongInPlayer(const AnsiString &a_filename) const
{
    vector<string> songvector;
    songvector.push_back(string(a_filename.c_str()));
    m_pMediator->playSongs(songvector);
}

void ConcreteSongFacade::playMultipleSongsInPlayer(vector<AnsiString> a_songfilenames) const
{
    vector<string> songvector;

    for(unsigned int i = 0; i < a_songfilenames.size(); i++)
        songvector.push_back(string(a_songfilenames[i].c_str()));

    m_pMediator->playSongs(songvector);
}

const TagImpEx *ConcreteSongFacade::createTagImpEx(const AnsiString &a_type) const
{
    return m_pMediator->createTagImpEx(a_type);
}

AnsiString ConcreteSongFacade::getPlayedFilename() const
{
    return m_pMediator->getPlayedFilename();
}

vector<SongProperty> ConcreteSongFacade::getSongsFromDatabase() const
{
    return m_pMediator->getSongsFromDatabase();
}

void ConcreteSongFacade::updateDatabase(intvector a_songindexes) const
{
    vector<SongProperty>    songproperties;
    SongProperty            tempproperty;

    for(unsigned int i = 0; i < a_songindexes.size(); i++) {
        tempproperty.clear(); // onödig? getAll skriver ju över... eller?

        m_songmanager.getAllSongProperties(a_songindexes[i], &tempproperty);
        songproperties.push_back(tempproperty);
    }

    m_pMediator->updateSongDatabase(songproperties);
}

