#include "../Headers.h"
#pragma hdrstop

#include "ConcretePlaylistFacade.h"
#include "PlaylistManager.h"
#include "../MediatorInterface.h"
#include "../Exceptions.h"
#include "../Constants.h"

ConcretePlaylistFacade::ConcretePlaylistFacade(const MediatorInterface *a_pMediator)
{
    if(a_pMediator == NULL)
        throw NullPointerException("ConcreteSongFacade::ConcreteSongFacade");

    m_pMediator = a_pMediator;
    m_pPlaylistmanager.setFacade(this);
}

ConcretePlaylistFacade::~ConcretePlaylistFacade()
{
//    if(m_pPlaylistmanager)
//        delete m_pPlaylistmanager;
}

vector<string> ConcretePlaylistFacade::getAllPlaylistNames() const
{
    return m_pPlaylistmanager.getAllPlaylistNames();
}

void ConcretePlaylistFacade::getSongProperties(int a_song, SongProperty *a_properties) const
{
    m_pMediator->getSongProperties(a_song, a_properties);
}

void ConcretePlaylistFacade::playPlaylistInPlayer(vector<string> a_songs) const
{
    m_pMediator->playSongs(a_songs);
}

intvector ConcretePlaylistFacade::getSongsInPlaylist(AnsiString a_playlist) const
{
    return m_pPlaylistmanager.getSongsInPlaylist(a_playlist);
}

intvector ConcretePlaylistFacade::getSongsMatchingProperties(const SongProperty &a_properties) const
{
    return m_pMediator->getSongsMatchingProperties(a_properties);
}

