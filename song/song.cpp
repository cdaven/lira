#include "../Headers.h"
#pragma hdrstop

#include "Song.h"
#include "SongTag.h"
#include "../ImportExport/TagImpEx.h"
#include "../Exceptions.h"
#include "../Constants.h"

Song::Song()
{
    m_filename = "";
    m_index = -1;
    m_filesize = -1;
    m_fileage = -1;
    m_pTagimportexport = 0;
}

Song::Song(const SongProperty &a_properties, const TagImpEx *a_pTagimpex)
{
    if(a_pTagimpex == NULL)
        throw NullPointerException("Song::Song");

    Song();

    int noproperties = a_properties.count();
    AnsiString leftvalue, rightvalue;

    for(int i = 0; i < noproperties; i++) {
        leftvalue = a_properties.getPropertyLeftValue(i);
        rightvalue = a_properties.getPropertyRightValue(i);

        setProperty(leftvalue, rightvalue);
    }

    m_pTagimportexport = a_pTagimpex;
}

Song::Song(const AnsiString &a_filename, const TagImpEx *a_pTagimpex)
{
    if(!FileExists(a_filename))
        throw FileNotFoundException("Song::Song");
    if(a_pTagimpex == NULL)
        throw NullPointerException("Song::Song");

    Song();

    m_filename = a_filename;
    m_fileage = FileAge(a_filename);

    TFileStream *fs;

    try {
        fs = new TFileStream(a_filename, fmOpenRead | fmShareDenyNone);
    }
    catch(EFOpenError &) {
        delete fs;
        throw;
    }

    m_filesize = (unsigned int)fs->Size;
    delete fs;

    m_pTagimportexport = a_pTagimpex;
    m_pTagimportexport->importTag(m_filename, &m_tag);
}

Song::~Song()
{
}

AnsiString Song::getProperty(const AnsiString &a_property) const
{
    if(properties::INDEX == a_property)
        return IntToStr(m_index);

    if(properties::FILENAME == a_property)
        return m_filename;

    if(properties::FILESIZE == a_property)
        return IntToStr(m_filesize);

    if(properties::FILEAGE == a_property)
        return IntToStr(m_fileage);

    if(properties::ALBUM == a_property)
        return AnsiString(m_tag.getAlbum().c_str());

    if(properties::BAND == a_property)
        return AnsiString(m_tag.getBand().c_str());

    if(properties::COMMENT == a_property)
        return AnsiString(m_tag.getComment().c_str());

    if(properties::COMPOSER == a_property)
        return AnsiString(m_tag.getComposer().c_str());

    if(properties::CONDUCTOR == a_property)
        return AnsiString(m_tag.getConductor().c_str());

    if(properties::CONTENTTYPE == a_property)
        return AnsiString(m_tag.getContentType().c_str());

    if(properties::ENCODER == a_property)
        return AnsiString(m_tag.getEncoder().c_str());

    if(properties::INTERPRETER == a_property)
        return AnsiString(m_tag.getInterpreter().c_str());

    if(properties::KEY == a_property)
        return AnsiString(m_tag.getKey().c_str());

    if(properties::LANGUAGES == a_property)
        return AnsiString(m_tag.getLanguages().c_str());

    if(properties::LEADARTIST == a_property)
        return AnsiString(m_tag.getLeadArtist().c_str());

    if(properties::LYRICIST == a_property)
        return AnsiString(m_tag.getLyricist().c_str());

    if(properties::LYRICS == a_property)
        return AnsiString(m_tag.getLyrics().c_str());

    if(properties::MOOD == a_property)
        return AnsiString(m_tag.getMood().c_str());

    if(properties::ORIGINALALBUM == a_property)
        return AnsiString(m_tag.getOriginalAlbum().c_str());

    if(properties::ORIGINALARTISTS == a_property)
        return AnsiString(m_tag.getOriginalArtists().c_str());

    if(properties::ORIGINALLYRICIST == a_property)
        return AnsiString(m_tag.getOriginalLyricist().c_str());

    if(properties::ORIGINALRELEASETIME == a_property)
        return AnsiString(m_tag.getOriginalReleaseTime().c_str());

    if(properties::PARTOFSET == a_property)
        return AnsiString(m_tag.getPartOfSet().c_str());

    if(properties::PUBLISHER == a_property)
        return AnsiString(m_tag.getPublisher().c_str());

    if(properties::RECORDINGTIME == a_property)
        return AnsiString(m_tag.getRecordingTime().c_str());

    if(properties::RELEASETIME == a_property)
        return AnsiString(m_tag.getReleaseTime().c_str());

    if(properties::SITUATION == a_property)
        return AnsiString(m_tag.getSituation().c_str());

    if(properties::SUBTITLE == a_property)
        return AnsiString(m_tag.getSubtitle().c_str());

    if(properties::TEMPO == a_property)
        return AnsiString(m_tag.getTempo().c_str());

    if(properties::TITLE == a_property)
        return AnsiString(m_tag.getTitle().c_str());

    if(properties::TRACKNO == a_property)
        return AnsiString(m_tag.getTrackNo().c_str());

    if(properties::BITRATE == a_property)
        return IntToStr(m_tag.getBitrate());

    if(properties::BPM == a_property)
        return IntToStr(m_tag.getBPM());

    if(properties::LENGTH == a_property)
        return IntToStr(m_tag.getLength());

    if(properties::RATING == a_property)
        return IntToStr(m_tag.getRating());

    if(properties::COVER == a_property)
        return m_tag.getCover() ? "1" : "0";

    if(properties::REMIX == a_property)
        return m_tag.getRemix() ? "1" : "0";

    return "";
}

void Song::setProperty(const AnsiString &a_property, const AnsiString &a_value)
{
// index, filename, filesize, fileage, length ska inte kunna sättas
// manuellt av användaren, däremot från värden hämtade ur databasen vid uppstart

    if(properties::INDEX == a_property)
        m_index = stringToInt(a_value);

    if(properties::FILENAME == a_property)
        m_filename = a_value;

    if(properties::FILESIZE == a_property)
        m_filesize = stringToInt(a_value);

    if(properties::FILEAGE == a_property)
        m_fileage = stringToInt(a_value);

    if(properties::ALBUM == a_property)
        m_tag.setAlbum(string(a_value.c_str()));

    if(properties::BAND == a_property)
        m_tag.setBand(string(a_value.c_str()));

    if(properties::COMMENT == a_property)
        m_tag.setComment(string(a_value.c_str()));

    if(properties::COMPOSER == a_property)
        m_tag.setComposer(string(a_value.c_str()));

    if(properties::CONDUCTOR == a_property)
        m_tag.setConductor(string(a_value.c_str()));

    if(properties::CONTENTTYPE == a_property)
        m_tag.setContentType(string(a_value.c_str()));

    if(properties::ENCODER == a_property)
        m_tag.setEncoder(string(a_value.c_str()));

    if(properties::INTERPRETER == a_property)
        m_tag.setInterpreter(string(a_value.c_str()));

    if(properties::KEY == a_property)
        m_tag.setKey(string(a_value.c_str()));

    if(properties::LANGUAGES == a_property)
        m_tag.setLanguages(string(a_value.c_str()));

    if(properties::LEADARTIST == a_property)
        m_tag.setLeadArtist(string(a_value.c_str()));

    if(properties::LYRICIST == a_property)
        m_tag.setLyricist(string(a_value.c_str()));

    if(properties::LYRICS == a_property)
        m_tag.setLyrics(string(a_value.c_str()));

    if(properties::MOOD == a_property)
        m_tag.setMood(string(a_value.c_str()));

    if(properties::ORIGINALALBUM == a_property)
        m_tag.setOriginalAlbum(string(a_value.c_str()));

    if(properties::ORIGINALARTISTS == a_property)
        m_tag.setOriginalArtists(string(a_value.c_str()));

    if(properties::ORIGINALLYRICIST == a_property)
        m_tag.setOriginalLyricist(string(a_value.c_str()));

    if(properties::ORIGINALRELEASETIME == a_property)
        m_tag.setOriginalReleaseTime(string(a_value.c_str()));

    if(properties::PARTOFSET == a_property)
        m_tag.setPartOfSet(string(a_value.c_str()));

    if(properties::PUBLISHER == a_property)
        m_tag.setPublisher(string(a_value.c_str()));

    if(properties::RECORDINGTIME == a_property)
        m_tag.setRecordingTime(string(a_value.c_str()));

    if(properties::RELEASETIME == a_property)
        m_tag.setReleaseTime(string(a_value.c_str()));

    if(properties::SITUATION == a_property)
        m_tag.setSituation(string(a_value.c_str()));

    if(properties::SUBTITLE == a_property)
        m_tag.setSubtitle(string(a_value.c_str()));

    if(properties::TEMPO == a_property)
        m_tag.setTempo(string(a_value.c_str()));

    if(properties::TITLE == a_property)
        m_tag.setTitle(string(a_value.c_str()));

    if(properties::TRACKNO == a_property)
        m_tag.setTrackNo(string(a_value.c_str()));

    if(properties::BITRATE == a_property)
        m_tag.setBitrate(stringToInt(a_value));

    if(properties::BPM == a_property)
        m_tag.setBPM(stringToInt(a_value));

    if(properties::LENGTH == a_property)
        m_tag.setLength(stringToInt(a_value));

    if(properties::RATING == a_property)
        m_tag.setRating(stringToInt(a_value));

    if(properties::COVER == a_property)
        if(a_value == "1")
            m_tag.setCover(true);
        else
            m_tag.setCover(false);

    if(properties::REMIX == a_property)
        if(a_value == "1")
            m_tag.setRemix(true);
        else
            m_tag.setRemix(false);
}

AnsiString Song::getFilename() const
{
    return m_filename;
}

void Song::importTag()
{
    if(m_pTagimportexport)
        m_pTagimportexport->importTag(m_filename, &m_tag);
}

void Song::exportTag() const
{
    if(m_pTagimportexport)
        m_pTagimportexport->exportTag(m_filename, m_tag);
}

int Song::stringToInt(AnsiString a_str) const
{
    try {
        return a_str.ToInt();
    }
    catch(EConvertError &) {
        return -1;
    }
}

