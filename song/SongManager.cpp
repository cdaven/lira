#include "../Headers.h"
#pragma hdrstop

#include "SongManager.h"
#include "Song.h"
#include "SongProperty.h"
#include "SongFacade.h"
#include "../Exceptions.h"
#include "../Constants.h"

SongManager::SongManager(const SongFacade *a_pSongfacade)
{
    if(a_pSongfacade == NULL)
        throw NullPointerException("SongManager::SongManager");

    m_pSongfacade = a_pSongfacade;
}

void SongManager::readFromDatabase()
{
    AnsiString tempindex;
    vector<SongProperty> songs;
    const TagImpEx *tie;
    int songindex;

    songs = m_pSongfacade->getSongsFromDatabase();
    tie = m_pSongfacade->createTagImpEx("ID3");

    for(unsigned int i = 0; i < songs.size(); i++) {
        tempindex = songs[i].getPropertyRightValue("index");

        if(tempindex == "")
            break;

        songindex = StrToInt(tempindex);
        m_songs[songindex] = Song(songs[i], tie);
    }
}

int SongManager::addSong(const AnsiString &a_filename)
{
    checkIntegrity();

    songmap::iterator iterator;
    for(iterator = m_songs.begin(); iterator != m_songs.end(); iterator++)
        if(stricmp(iterator->second.getFilename().c_str(), a_filename.c_str()) == 0) {
            iterator->second.importTag();
            return iterator->second.getIndex();
        }

    int songindex = getFirstFreeIndex();
    const TagImpEx *tie;

    AnsiString ext = a_filename.SubString(a_filename.LastDelimiter(".") + 1, 3);
    if(ext.LowerCase() == "mp3")
        tie = m_pSongfacade->createTagImpEx("ID3");
    else
        throw InvalidTagTypeException("SongManager::addSong");

    m_songs[songindex] = Song(a_filename, tie);
    m_songs[songindex].setProperty(properties::INDEX, songindex);

    return songindex;
}

void SongManager::removeSong(int a_song)
{
    checkIntegrity();

    m_songs.erase(a_song);
    m_pSongfacade->removeSongFromPlaylists(a_song);
}

void SongManager::refreshSongTag(int a_song)
{
    songmap::iterator iterator = getSong(a_song);

    iterator->second.importTag();
}

intvector SongManager::getSongsMatchingProperties(const SongProperty &a_property) const
{
    intvector songs;
    songmap::const_iterator iterator;
    int noproperties = a_property.count();
    AnsiString property, value;
    bool isahit;

    for(iterator = m_songs.begin(); iterator != m_songs.end(); iterator++) {
        isahit = true;

        for(int i = 0; i < noproperties; i++) {
            property = a_property.getPropertyLeftValue(i);
            value = a_property.getPropertyRightValue(i);

            // wildcards fungerar ej med genre!
            if(property == "content type")
                isahit = isGenreEqual(value, iterator->second.getProperty(property));
            else
                if(!wildCardMatch(value, iterator->second.getProperty(property)))
                    isahit = false;
        }

        if(isahit)
            songs.push_back(iterator->first);
    }

    return songs;
}

void SongManager::getAllSongProperties(int a_song, SongProperty *a_properties) const
{
    a_properties->clear();
    a_properties->addProperty(properties::INDEX, IntToStr(a_song));
    a_properties->addProperty(properties::FILENAME);
    a_properties->addProperty(properties::FILESIZE);
    a_properties->addProperty(properties::FILEAGE);
    a_properties->addProperty(properties::ALBUM);
    a_properties->addProperty(properties::BAND);
    a_properties->addProperty(properties::COMMENT);
    a_properties->addProperty(properties::COMPOSER);
    a_properties->addProperty(properties::CONDUCTOR);
    a_properties->addProperty(properties::CONTENTTYPE);
    a_properties->addProperty(properties::ENCODER);
    a_properties->addProperty(properties::INTERPRETER);
    a_properties->addProperty(properties::KEY);
    a_properties->addProperty(properties::LANGUAGES);
    a_properties->addProperty(properties::LEADARTIST);
    a_properties->addProperty(properties::LYRICIST);
    a_properties->addProperty(properties::LYRICS);
    a_properties->addProperty(properties::MOOD);
    a_properties->addProperty(properties::ORIGINALALBUM);
    a_properties->addProperty(properties::ORIGINALARTISTS);
    a_properties->addProperty(properties::ORIGINALLYRICIST);
    a_properties->addProperty(properties::ORIGINALRELEASETIME);
    a_properties->addProperty(properties::PARTOFSET);
    a_properties->addProperty(properties::PUBLISHER);
    a_properties->addProperty(properties::RECORDINGTIME);
    a_properties->addProperty(properties::RELEASETIME);
    a_properties->addProperty(properties::SITUATION);
    a_properties->addProperty(properties::SUBTITLE);
    a_properties->addProperty(properties::TEMPO);
    a_properties->addProperty(properties::TITLE);
    a_properties->addProperty(properties::TRACKNO);
    a_properties->addProperty(properties::BITRATE);
    a_properties->addProperty(properties::BPM);
    a_properties->addProperty(properties::LENGTH);
    a_properties->addProperty(properties::RATING);
    a_properties->addProperty(properties::COVER);
    a_properties->addProperty(properties::REMIX);

    getSongProperties(a_song, a_properties);
}

/*-----------------------------------------------------------------------------
  Funktion:  getSongProperties
  Datum:     18 aug 2003
  Uppgift:   Hämtar värden på de attribut som anges i a_properties
-----------------------------------------------------------------------------*/
void SongManager::getSongProperties(int a_song, SongProperty *a_properties) const
{
    songmap::const_iterator iterator;

    try {
        iterator = getConstSong(a_song);
    }
    catch(NotInContainerException &) {
        return;
    }

    int noproperties = a_properties->count();
    AnsiString leftvalue, rightvalue;
    for(int i = 0; i < noproperties; i++) {
        leftvalue = a_properties->getPropertyLeftValue(i);
        rightvalue = iterator->second.getProperty(leftvalue);

        a_properties->setPropertyRightValue(leftvalue, rightvalue);
    }
}

void SongManager::setSongProperties(int a_song, const SongProperty &a_properties)
{
    songmap::iterator iterator = getSong(a_song);

    int noproperties = a_properties.count();
    AnsiString leftvalue, rightvalue;
    for(int i = 0; i < noproperties; i++) {
        leftvalue = a_properties.getPropertyLeftValue(i);
        rightvalue = a_properties.getPropertyRightValue(i);

        iterator->second.setProperty(leftvalue, rightvalue);
    }

    SongProperty properties;
    getAllSongProperties(a_song, &properties);

    AnsiString playing = m_pSongfacade->getPlayedFilename();
    if(stricmp(iterator->second.getFilename().c_str(), playing.c_str()) == 0)
        m_pSongfacade->saveAndStop();

    try {
        iterator->second.exportTag();
    }
    catch(...) {
        m_pSongfacade->resumePlay();
        throw;
    }

    m_pSongfacade->updateDatabase(a_song, properties);
    m_pSongfacade->resumePlay();
}

AnsiString SongManager::getSongFilename(int a_song) const
{
    songmap::const_iterator iterator = getConstSong(a_song);
    return iterator->second.getFilename();
}

void SongManager::setSongFilename(int a_song, const AnsiString &a_filename)
{
    SongProperty properties;
    getAllSongProperties(a_song, &properties);
    m_pSongfacade->updateDatabase(a_song, properties);

    songmap::iterator iterator = getSong(a_song);
    return iterator->second.setFilename(a_filename);
}

void SongManager::playSong(int a_song) const
{
    checkIntegrity();

    songmap::const_iterator iterator = getConstSong(a_song);
    m_pSongfacade->playSongInPlayer(iterator->second.getFilename());
}

void SongManager::playMultipleSongs(intvector a_songs) const
{
    checkIntegrity();

    vector<AnsiString> songfilenames;
    songmap::const_iterator iterator;

    for(unsigned int i = 0; i < a_songs.size(); i++) {
        iterator = getConstSong(a_songs[i]);
        songfilenames.push_back(iterator->second.getFilename());
    }

    m_pSongfacade->playMultipleSongsInPlayer(songfilenames);
}

int SongManager::getFirstFreeIndex() const
{
    for(int i = 0; ; i++)
        if(!m_songs.count(i))
            return i;
}

songmap::const_iterator SongManager::getConstSong(int a_song) const
{
    songmap::const_iterator iterator;
    iterator = m_songs.find(a_song);

    if(iterator == m_songs.end())
        throw NotInContainerException("SongManager::getSong");

    return iterator;
}

songmap::iterator SongManager::getSong(int a_song)
{
    songmap::iterator iterator;
    iterator = m_songs.find(a_song);

    if(iterator == m_songs.end())
        throw NotInContainerException("SongManager::getSong");

    return iterator;
}

bool SongManager::wildCardMatch(const AnsiString &a_pattern, const AnsiString &a_text) const
{
    bool matches = false;
    TMask *mask = new TMask(a_pattern);

    try {
        if(mask->Matches(a_text))
            matches = true;
    }
    catch(EMaskException &) {
        // antingen kasta undantag eller returnera falskt
    }

    delete mask;
    return matches;
}

void SongManager::checkIntegrity() const
{
    if(m_pSongfacade == NULL)
        throw NullPointerException("SongManager::checkIntegrity");
}

bool SongManager::isGenreEqual(AnsiString a_wanted, AnsiString a_got) const
{
//    // anges genre-strängen med "all x" kan flera genrer passa in
//
//    if(a_wanted.SubString(1, 4) != "all ")
        if(a_wanted.LowerCase() == a_got.LowerCase())
            return true;
        else
            return false;
//
//    string mothergenre = string(a_wanted.SubString(5, a_wanted.Length()).c_str());
//
//    if(stricmp(mothergenre.c_str(), a_got.c_str()) == 0)
//        return true;
//
//    if(a_got == "Alternative Rock" && mothergenre == "Rock")
//        return true;
//    if(a_got == "New Wave" && mothergenre == "Rock")
//        return true;
//
//    // SMARTASTE VORE EN SEPARAT KLASS MED MAP ÖVER GENRER (YTTERLIGARE KLASSER)
}

