#ifndef SONGTAG_H_HEADER_INCLUDED_C0DB79D4
#define SONGTAG_H_HEADER_INCLUDED_C0DB79D4

#include <string>

//  Senare kanske SongTag ska förminskas så att allt som hålls i minne är det
//  som kan göras smarta spellistor av och inget annat. Resten hämtas när
//  man vill ändra informationen ... Hur blir det då med musik lagrad på ej
//  tillgänglig media?

using namespace std;

// Innehåller den interna låtinformationen. Skrivs och läses till/från fil med
// en TagImpEx.
class SongTag
{
public:
    SongTag();

    void setAlbum               (const string &a) { m_album = a; }
    void setBand                (const string &a) { m_band = a; }
    void setBitrate             (int a)           { m_bitrate = a; }
    void setBPM                 (int a)           { m_bpm = a; }
    void setComment             (const string &a) { m_comment = a; }
    void setComposer            (const string &a) { m_composer = a; }
    void setConductor           (const string &a) { m_conductor = a; }
    void setContentType         (const string &a) { m_contenttype = a; }
    void setCover               (bool a)          { m_cover = a; }
    void setEncoder             (const string &a) { m_encoder = a; } // Person, ej program
    void setInterpreter         (const string &a) { m_interpreter = a; }
    void setKey                 (const string &a) { m_key = a; }
    void setLanguages           (const string &a) { m_languages = a; }
    void setLeadArtist          (const string &a) { m_leadartist = a; }
    void setLength              (int a)           { m_length = a; }
    void setLyricist            (const string &a) { m_lyricist = a; }
    void setLyrics              (const string &a) { m_lyrics = a; }
    void setMood                (const string &a) { m_mood = a; }
    void setOriginalAlbum       (const string &a) { m_originalalbum = a; }
    void setOriginalArtists     (const string &a) { m_originalartists = a; }
    void setOriginalLyricist    (const string &a) { m_originallyricist = a; }
    void setOriginalReleaseTime (const string &);
    void setPartOfSet           (const string &a) { m_partofset = a; }
    void setPublisher           (const string &a) { m_publisher = a; }
    void setRating              (int a)           { m_rating = a; }
    void setRecordingTime       (const string &);
    void setReleaseTime         (const string &);
    void setRemix               (bool a)          { m_remix = a; }
    void setSituation           (const string &a) { m_situation = a; }
    void setSubtitle            (const string &a) { m_subtitle = a; }
    void setTempo               (const string &a) { m_tempo = a; }
    void setTitle               (const string &a) { m_title = a; }
    void setTrackNo             (const string &a) { m_trackno = a; }

    string getAlbum()               const { return m_album; }
    string getBand()                const { return m_band; }
    string getComment()             const { return m_comment; }
    string getComposer()            const { return m_composer; }
    string getConductor()           const { return m_conductor; }
    string getContentType()         const { return m_contenttype; }
    string getEncoder()             const { return m_encoder; }
    string getInterpreter()         const { return m_interpreter; }
    string getKey()                 const { return m_key; }
    string getLanguages()           const { return m_languages; }
    string getLeadArtist()          const { return m_leadartist; }
    string getLyricist()            const { return m_lyricist; }
    string getLyrics()              const { return m_lyrics; }
    string getMood()                const { return m_mood; }
    string getOriginalAlbum()       const { return m_originalalbum; }
    string getOriginalArtists()     const { return m_originalartists; }
    string getOriginalLyricist()    const { return m_originallyricist; }
    string getOriginalReleaseTime() const { return m_originalreleasetime; }
    string getPartOfSet()           const { return m_partofset; }
    string getPublisher()           const { return m_publisher; }
    string getRecordingTime()       const { return m_recordingtime; }
    string getReleaseTime()         const { return m_releasetime; }
    string getSituation()           const { return m_situation; }
    string getSubtitle()            const { return m_subtitle; }
    string getTempo()               const { return m_tempo; }
    string getTitle()               const { return m_title; }
    string getTrackNo()             const { return m_trackno; }

    int getBitrate()                const { return m_bitrate; }
    int getBPM()                    const { return m_bpm; }
    int getLength()                 const { return m_length; }
    int getRating()                 const { return m_rating; }

    bool getCover()                 const { return m_cover; }
    bool getRemix()                 const { return m_remix; }

private:
    bool isStringOkDate(const string &) const;
    bool isNumber(const char &) const;
    bool isYear(const string &) const;
    bool isMonth(const string &) const;
    bool isDay(const string &) const;

    string m_album;
    string m_band;
    string m_comment;
    string m_composer;
    string m_conductor;
    string m_contenttype;
    string m_encoder;
    string m_interpreter;
    string m_key;
    string m_languages;
    string m_leadartist;
    string m_lyricist;
    string m_lyrics;
    string m_mood;
    string m_originalalbum;
    string m_originalartists;
    string m_originallyricist;
    string m_originalreleasetime;
    string m_partofset; // kan vara "1/2"
    string m_publisher;
    string m_recordingtime;
    string m_releasetime;
    string m_situation;
    string m_subtitle;
    string m_tempo;
    string m_title;
    string m_trackno; // kan vara "3/12"

    int m_bitrate;
    int m_bpm;
    int m_length;
    int m_rating;

    bool m_cover;
    bool m_remix;
};

#endif /* TAG_H_HEADER_INCLUDED_C0DB79D4 */
