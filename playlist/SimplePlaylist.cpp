#include <vector>
#include <algorith> // count, find
#include "SimplePlaylist.h"
#include "../lib/Exceptions.h"

using namespace std;

SimplePlaylist::SimplePlaylist()
{ // map anropar tomma konstrueraren av ngn anledning
    m_songs.reserve(100);
}

SimplePlaylist::SimplePlaylist(AnsiString a_name)
{
    SimplePlaylist();
    m_name = a_name;
}

vector<int> SimplePlaylist::getSongs() const
{
    vector<int> songs;

    for(unsigned int i = 0; i < m_songs.size(); i++)
        songs.push_back(m_songs[i]);

    return songs;
}

void SimplePlaylist::addSong(int a_song)
{
    if(getPositionOfSong(a_song) != m_songs.end())
        throw AlreadyInContainerException("SimplePlaylist::addSong");

    m_songs.push_back(a_song);
}

void SimplePlaylist::removeSong(int a_song)
{
    intvector::iterator position = getPositionOfSong(a_song);

    if(position == m_songs.end())
        throw NotInContainerException("SimplePlaylist::removeSong");

    m_songs.erase(position);
}

intvector::iterator SimplePlaylist::getPositionOfSong(int a_song)
{
    return std::find(m_songs.begin(), m_songs.end(), a_song);
}

