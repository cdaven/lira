#include "../Headers.h"
#pragma hdrstop

#include "PlaylistManager.h"
#include "PlaylistFacade.h"
#include "SimplePlaylist.h"
#include "SmartPlaylist.h"
#include "../Exceptions.h"
#include "../Constants.h"

using namespace std;

PlaylistManager::PlaylistManager()
{
    m_pPlaylistfacade = 0;

    // läs in spellistorna från databas
}

PlaylistManager::~PlaylistManager()
{
    // spara spellistorna till databas
}

void PlaylistManager::setFacade(const PlaylistFacade *a_plfacade)
{
    m_pPlaylistfacade = a_plfacade;
}

void PlaylistManager::addSongToPlaylist(int a_song, AnsiString a_playlistname)
{
    // BUGGVARNING! Det görs ingen kontroll här om låten som ska läggas
    // till en spellista verkligen är en låt i databasen. Bör ordnas när
    // Song har implementerats.

    simpleplaylistmap::iterator iterator;
    iterator = m_simpleplaylists.find(a_playlistname.c_str());

    if(iterator == m_simpleplaylists.end())
        throw NotInContainerException("PlaylistManager::addSongToPlaylist");

    ((*iterator).second).addSong(a_song);
}

void PlaylistManager::removeSongFromPlaylist(int a_song, AnsiString a_playlistname)
{
    string playlistname = a_playlistname.c_str();

    simpleplaylistmap::iterator iterator;
    iterator = m_simpleplaylists.find(playlistname);

    if(iterator == m_simpleplaylists.end())
        throw NotInContainerException("PlaylistManager::removeSongFromPlaylist");

    ((*iterator).second).removeSong(a_song);
}

vector<string> PlaylistManager::getAllPlaylistNames() const
{
    vector<string> playlists;

    for(simpleplaylistmap::const_iterator i = m_simpleplaylists.begin(); i != m_simpleplaylists.end(); i++)
        playlists.push_back(
            string(((*i).second).getName().c_str())
        );
    for(smartplaylistmap::const_iterator i = m_smartplaylists.begin(); i != m_smartplaylists.end(); i++)
        playlists.push_back(
            string(((*i).second).getName().c_str())
        );

    return playlists;
}

intvector PlaylistManager::getSongsInPlaylist(AnsiString a_playlistname) const
{
    string playlistname = a_playlistname.c_str();

    simpleplaylistmap::const_iterator   simple_iterator;
    smartplaylistmap::const_iterator    smart_iterator;

    simple_iterator = m_simpleplaylists.find(playlistname);
    smart_iterator = m_smartplaylists.find(playlistname);

    if(simple_iterator == m_simpleplaylists.end())
        if(smart_iterator == m_smartplaylists.end())
            throw NotInContainerException("PlaylistManager::getSongsInPlaylist");
        else
            return ((*smart_iterator).second).getSongs();
    else
        return ((*simple_iterator).second).getSongs();
}

void PlaylistManager::getSongProperties() const
{
}

void PlaylistManager::newSmartPlaylist(AnsiString a_playlistname, const SongProperty &a_properties)
{
    string playlistname = a_playlistname.c_str();

    simpleplaylistmap::const_iterator   simple_iterator;
    smartplaylistmap::const_iterator    smart_iterator;

    simple_iterator = m_simpleplaylists.find(playlistname);
    smart_iterator = m_smartplaylists.find(playlistname);

    if(simple_iterator != m_simpleplaylists.end() ||
        smart_iterator != m_smartplaylists.end())
        throw AlreadyInContainerException("PlaylistManager::newSmartPlaylist");

    SmartPlaylist playlist(a_playlistname, a_properties, this);
    m_smartplaylists[playlistname] = playlist;
}

void PlaylistManager::getSmartPlaylistProperties(AnsiString a_playlist,
    SongProperty *a_properties) const
{
    string playlistname = a_playlist.c_str();

    smartplaylistmap::const_iterator iterator;
    iterator = m_smartplaylists.find(playlistname);

    if(iterator == m_smartplaylists.end())
        throw NotInContainerException("PlaylistManager::removeSongFromPlaylist");

    ((*iterator).second).getProperties(a_properties);
}

void PlaylistManager::setSmartPlaylistProperties(AnsiString a_playlist,
    const SongProperty &a_properties)
{
    string playlistname = a_playlist.c_str();

    smartplaylistmap::iterator iterator;
    iterator = m_smartplaylists.find(playlistname);

    if(iterator == m_smartplaylists.end())
        throw NotInContainerException("PlaylistManager::removeSongFromPlaylist");

    ((*iterator).second).setProperties(a_properties);
}


void PlaylistManager::newSimplePlaylist(AnsiString a_playlistname)
{
    string playlistname = a_playlistname.c_str();

    simpleplaylistmap::const_iterator   simple_iterator;
    smartplaylistmap::const_iterator    smart_iterator;

    simple_iterator = m_simpleplaylists.find(playlistname);
    smart_iterator = m_smartplaylists.find(playlistname);

    if(simple_iterator != m_simpleplaylists.end() ||
        smart_iterator != m_smartplaylists.end())
        throw AlreadyInContainerException("PlaylistManager::newSimplePlaylist");

    SimplePlaylist playlist(a_playlistname);
    m_simpleplaylists[playlistname] = playlist;
}

void PlaylistManager::removePlaylist(AnsiString a_playlistname)
{
    if(!m_simpleplaylists.erase(a_playlistname.c_str()) &&
        !m_smartplaylists.erase(a_playlistname.c_str()))
        throw NotInContainerException("PlaylistManager::removePlaylist");
}

void PlaylistManager::playPlaylist(AnsiString a_playlistname) const
{
    checkIntegrity();

    stringvector    songfilenames;
    intvector       songnumbers;
    SongProperty    songproperties;

    songnumbers = getSongsInPlaylist(a_playlistname);

    songproperties.addProperty("file name");

    for(int i = 0; i < songnumbers.size(); i++) {
        m_pPlaylistfacade->getSongProperties(songnumbers[i], &songproperties);
        songfilenames.push_back(
            string(songproperties.getPropertyRightValue("file name").c_str())
            );
    }

    m_pPlaylistfacade->playPlaylistInPlayer(songfilenames);
}

void PlaylistManager::removeSongFromAllPlaylists(int a_song)
{
    for(simpleplaylistmap::iterator i = m_simpleplaylists.begin(); i != m_simpleplaylists.end(); i++)
        ((*i).second).removeSong(a_song);
}

void PlaylistManager::exportPlaylist(const PlaylistImpEx *impex) const
{
}

Playlist *PlaylistManager::importPlaylist(const PlaylistImpEx *impex, AnsiString filename)
{
}

intvector PlaylistManager::getSongsMatchingProperties(const SongProperty &a_property) const
{
    checkIntegrity();
    return m_pPlaylistfacade->getSongsMatchingProperties(a_property);
}

void PlaylistManager::checkIntegrity() const
{
    if(m_pPlaylistfacade == NULL)
        throw Exception("PlaylistManager::checkIntegrity");
}
