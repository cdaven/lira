#include "../Headers.h"
#pragma hdrstop

#include "ID3TagImpEx.h"
#include "ID3GenreParser.h"
#include "../Song/SongTag.h"
#include "../Exceptions.h"

#ifndef ID3LIB_LINKOPTION
#define ID3LIB_LINKOPTION 1
#endif

#include <id3.h>

ID3TagImpEx::ID3TagImpEx()
{
    // "VANLIGASTE"
    m_languagecodes["deu"] = "tyska";
    m_languagecodes["ger"] = "tyska";
    m_languagecodes["eng"] = "engelska";
    m_languagecodes["esl"] = "spanska";
    m_languagecodes["fra"] = "franska";
    m_languagecodes["fre"] = "franska";
    m_languagecodes["nla"] = "holländska";
    m_languagecodes["dut"] = "holländska";
    m_languagecodes["rus"] = "ryska";
    m_languagecodes["por"] = "portugisiska";
    m_languagecodes["ara"] = "arabiska";
    m_languagecodes["spa"] = "spanska";
    m_languagecodes["sve"] = "svenska";
    m_languagecodes["swe"] = "svenska";

    // EUROPA
    m_languagecodes["baq"] = "baskiska";
    m_languagecodes["eus"] = "baskiska";
    m_languagecodes["bul"] = "bulgariska";
    m_languagecodes["cat"] = "katalanska";
    m_languagecodes["cel"] = "annat keltiskt språk";
    m_languagecodes["ces"] = "tjeckiska";
    m_languagecodes["cos"] = "korsikanska";
    m_languagecodes["hun"] = "ungerska";
    m_languagecodes["ice"] = "isländska";
    m_languagecodes["isl"] = "isländska";
    m_languagecodes["cym"] = "walesiska";
    m_languagecodes["wel"] = "walesiska";
    m_languagecodes["cze"] = "tjeckiska";
    m_languagecodes["dan"] = "danska";
    m_languagecodes["gre"] = "grekiska";
    m_languagecodes["ell"] = "grekiska";
    m_languagecodes["est"] = "estniska";
    m_languagecodes["fin"] = "finska";
    m_languagecodes["gae"] = "höglandsskotska";
    m_languagecodes["gdh"] = "höglandsskotska";
    m_languagecodes["gai"] = "iriska";
    m_languagecodes["iri"] = "iriska";
    m_languagecodes["ita"] = "italienska";
    m_languagecodes["lat"] = "latin";
    m_languagecodes["nno"] = "norska";
    m_languagecodes["nor"] = "norska";
    m_languagecodes["lav"] = "lettiska";
    m_languagecodes["lit"] = "litauiska";
    m_languagecodes["pol"] = "polska";
    m_languagecodes["ukr"] = "ukrainska";
    m_languagecodes["sco"] = "skotska";
    m_languagecodes["scr"] = "serbo-kroatiska";
    m_languagecodes["slk"] = "slovakiska";
    m_languagecodes["slo"] = "slovakiska";
    m_languagecodes["slv"] = "slovenska";
    m_languagecodes["smi"] = "samiska";
    m_languagecodes["rom"] = "romani";
    m_languagecodes["ron"] = "rumänska";
    m_languagecodes["rum"] = "rumänska";
    m_languagecodes["gem"] = "annat germanskt språk";
    m_languagecodes["roa"] = "annat romanskt språk";

    // AFRIKA
    m_languagecodes["afr"] = "afrikaans";
    m_languagecodes["bnt"] = "annat bantuspråk";
    m_languagecodes["zul"] = "zulu";
    m_languagecodes["xho"] = "xhosa";
    m_languagecodes["cop"] = "koptiska";
    m_languagecodes["ssw"] = "swazi";
    m_languagecodes["swa"] = "swahili";
    m_languagecodes["sun"] = "sudanesiska";

    // ASIEN
    m_languagecodes["ben"] = "bengali";
    m_languagecodes["bod"] = "tibetanska";
    m_languagecodes["tib"] = "tibetanska";
    m_languagecodes["bur"] = "burmanska";
    m_languagecodes["mya"] = "burmanska";
    m_languagecodes["chi"] = "kinesiska";
    m_languagecodes["zho"] = "kinesiska";
    m_languagecodes["heb"] = "hebreiska";
    m_languagecodes["hin"] = "hindi";
    m_languagecodes["tha"] = "thailändska";
    m_languagecodes["per"] = "persiska";
    m_languagecodes["fas"] = "persiska";
    m_languagecodes["jpn"] = "japanska";
    m_languagecodes["khm"] = "khmer";
    m_languagecodes["kor"] = "koreanska";
    m_languagecodes["kur"] = "kurdiska";
    m_languagecodes["mao"] = "maori";
    m_languagecodes["mri"] = "maori";
    m_languagecodes["inc"] = "annat indiskt språk";
    m_languagecodes["ind"] = "indonesiska";
    m_languagecodes["may"] = "malajiska";
    m_languagecodes["mon"] = "mongoliska";
    m_languagecodes["tam"] = "tamil";
    m_languagecodes["tgl"] = "tagalog";
    m_languagecodes["tur"] = "turkiska";
    m_languagecodes["urd"] = "urdu";
    m_languagecodes["vie"] = "vietnamesiska";
    m_languagecodes["map"] = "annat austronesiskt språk";

    // AMERIKA
    m_languagecodes["nai"] = "nordamerikanskt indianspråk";
    m_languagecodes["sai"] = "sydamerikanskt indianspråk";

    // "ÖVRIGT"
    m_languagecodes["art"] = "artificiellt språk";
    m_languagecodes["und"] = "okänt språk";
    m_languagecodes["yid"] = "yiddish";
    m_languagecodes["cau"] = "annat kaukasiskt språk";
    m_languagecodes["afa"] = "annat afro-asiatiskt språk";
    m_languagecodes["sem"] = "annat semitiskt språk";
    m_languagecodes["sla"] = "annat slaviskt språk";
}

ID3TagImpEx::~ID3TagImpEx()
{
}

void ID3TagImpEx::exportTag(const AnsiString &a_filename, const SongTag &a_songdata) const
{
    if(!FileExists(a_filename))
        throw FileNotFoundException("ID3TagImpEx::exportTag");

    if(FileIsReadOnly(a_filename))
        throw FileNotWritableException("ID3TagImpEx::exportTag");

    ID3Tag *pTag = ID3Tag_New();
    ID3Tag_Link(pTag, a_filename.c_str());

    createNewTag(pTag, a_songdata);

    // hur vet jag om det verkligen skrevs till fil?
    ID3Tag_Update(pTag);
    ID3Tag_Delete(pTag);
    return;
}

void ID3TagImpEx::importTag(const AnsiString &a_filename, SongTag *const a_pSongtag) const
{
    if(!FileExists(a_filename))
        throw FileNotFoundException("ID3TagImpEx::importTag");

    ID3Tag *pTag = ID3Tag_New();
    ID3TagIterator *pFrameiterator = 0;
    ID3Frame *pFrame = 0;

    ID3Tag_Link(pTag, a_filename.c_str());

    if(!ID3Tag_NumFrames(pTag)) {
        ID3Tag_Delete(pTag);
        a_pSongtag->setTitle(string(a_filename.c_str()));
        return;
    }

    pFrameiterator = ID3Tag_CreateIterator(pTag);
    while((pFrame = ID3TagIterator_GetNext(pFrameiterator)) != 0) {
        try {
            parseFrame(pFrame, a_pSongtag);
        }
        catch(FrameDuplicateException &e) {
            // ta bort frame!
        }
    }

    // Läs in inspelningstillfälle
    string rectime;

    pFrame = ID3Tag_FindFrameWithID(pTag, ID3FID_YEAR);
    if(pFrame) {
        rectime = getString(pFrame);

        pFrame = ID3Tag_FindFrameWithID(pTag, ID3FID_DATE);
        if(pFrame) {
            string monthdate = getString(pFrame);

            if(monthdate.length() == 4) {
                rectime += "-" + monthdate.substr(2);
                rectime += "-" + monthdate.substr(0, 2);
            }
        }

        a_pSongtag->setRecordingTime(rectime);
    }

    pFrame = ID3Tag_FindFrameWithID(pTag, ID3FID_ORIGYEAR);
    if(pFrame)
        a_pSongtag->setOriginalReleaseTime(getString(pFrame));

    ID3Tag_Delete(pTag);
    ID3TagIterator_Delete(pFrameiterator);
}

void ID3TagImpEx::parseFrame(ID3Frame *a_pFrame, SongTag *const a_pSongtag) const
{
    ID3_FrameID frameid = ID3Frame_GetID(a_pFrame);
    string tempstring;
    ID3Field *pTempfield = 0;
    GenreRemixCover tempgenre;

    switch(frameid) {
        case ID3FID_ALBUM:
            a_pSongtag->setAlbum(getString(a_pFrame));
            break;

        case ID3FID_COMPOSER:
            a_pSongtag->setComposer(getString(a_pFrame));
            break;

        case ID3FID_CONTENTTYPE:
            tempstring = getString(a_pFrame);
            tempgenre = m_genreparser.parseFromTag(tempstring);
            a_pSongtag->setContentType(tempgenre.genre);
            a_pSongtag->setRemix(tempgenre.remix);
            a_pSongtag->setCover(tempgenre.cover);
            break;

        // Alla MusicMatch-taggar är av typen ID3FID_COMMENT
        case ID3FID_COMMENT:
            tempstring = getDescription(a_pFrame);

            // Varning: Winamp skriver ID3v2-kommentaren i första COMM-framen,
            // oavsett om den har någon MusicMatch-beskrivning -- då försvinner
            // alltså lagrad data... Bör kontrolleras.

            if(tempstring == "ID3v1 Comment") {
                if(a_pSongtag->getComment() == "")
                    a_pSongtag->setComment(getString(a_pFrame));
            }
            else if(tempstring == "")
                a_pSongtag->setComment(getString(a_pFrame));

            else if(tempstring == "MusicMatch_Tempo") {
                // Om Tempo inte redan är satt av TXXX-framen
                if(a_pSongtag->getTempo() == "") {
                    tempstring = getString(a_pFrame);
                    tempstring = getTempoFromMusicMatch(tempstring);
                    a_pSongtag->setTempo(tempstring);
                }
            }

            else if(tempstring == "MusicMatch_Mood") {
                // Om Mood inte redan är satt av TXXX-framen
                if(a_pSongtag->getMood() == "") {
                    tempstring = getString(a_pFrame);
                    tempstring = getMoodFromMusicMatch(tempstring);
                    a_pSongtag->setMood(tempstring);
                }
            }

            else if(tempstring == "MusicMatch_Situation") {
                // Om Situation inte redan är satt av TXXX-framen
                if(a_pSongtag->getSituation() == "") {
                    tempstring = getString(a_pFrame);
                    tempstring = getSituationFromMusicMatch(tempstring);
                    a_pSongtag->setSituation(tempstring);
                }
            }

            else if(tempstring == "MusicMatch_Preference") {
                // Om Rating inte redan är satt av ID3v2.3-framen
                if(a_pSongtag->getRating() == -1) {
                    tempstring = getString(a_pFrame);
                    a_pSongtag->setRating(getRatingFromMusicMatch(tempstring));
                }
            }

            break;

        case ID3FID_ENCODEDBY:
            a_pSongtag->setEncoder(getString(a_pFrame));
            break;

        case ID3FID_LYRICIST:
            a_pSongtag->setLyricist(getString(a_pFrame));
            break;

        case ID3FID_UNSYNCEDLYRICS:
            a_pSongtag->setLyrics(getString(a_pFrame));
            break;

        case ID3FID_TITLE:
            a_pSongtag->setTitle(getString(a_pFrame));
            break;

        case ID3FID_SUBTITLE:
            a_pSongtag->setSubtitle(getString(a_pFrame));
            break;

//        case ID3FID_INITIALKEY:
//            // ska tolkas!
//            a_pSongtag->setKey(getString(a_pFrame));
//            break;

        case ID3FID_LANGUAGE:
            tempstring = getString(a_pFrame);
            if(tempstring.length() >= 3)
                a_pSongtag->setLanguages(getLanguageFromCode(tempstring.substr(0, 3))); // osäker om 0,3 är rätt

            break;

        case ID3FID_ORIGALBUM:
            a_pSongtag->setOriginalAlbum(getString(a_pFrame));
            break;

        case ID3FID_ORIGLYRICIST:
            a_pSongtag->setOriginalLyricist(getString(a_pFrame));
            break;

        case ID3FID_ORIGARTIST:
            a_pSongtag->setOriginalArtists(getString(a_pFrame));
            break;

        case ID3FID_LEADARTIST:
            a_pSongtag->setLeadArtist(getString(a_pFrame));
            break;

        case ID3FID_BAND:
            a_pSongtag->setBand(getString(a_pFrame));
            break;

        case ID3FID_CONDUCTOR:
            a_pSongtag->setConductor(getString(a_pFrame));
            break;

        case ID3FID_MIXARTIST:
            a_pSongtag->setInterpreter(getString(a_pFrame));
            break;

        case ID3FID_PARTINSET:
            a_pSongtag->setPartOfSet(getString(a_pFrame));
            break;

        case ID3FID_PUBLISHER:
            a_pSongtag->setPublisher(getString(a_pFrame));
            break;

        case ID3FID_POPULARIMETER:
            pTempfield = ID3Frame_GetField(a_pFrame, ID3FN_RATING);
            if(pTempfield)
                a_pSongtag->setRating(ID3Field_GetINT(pTempfield));

            break;

        case ID3FID_TRACKNUM:
            a_pSongtag->setTrackNo(getString(a_pFrame));
            break;

        case ID3FID_SONGLEN:
            try {
                // string -> AnsiString -> int
                tempstring = getString(a_pFrame);
                a_pSongtag->setLength(StrToInt(AnsiString(tempstring.c_str())));
            }
            catch(EConvertError &) { }
            break;

        case ID3FID_BPM:
            try {
                // string -> AnsiString -> int
                tempstring = getString(a_pFrame);
                a_pSongtag->setBPM(StrToInt(AnsiString(tempstring.c_str())));
            }
            catch(EConvertError &) { }
            break;

        case ID3FID_USERTEXT:
            tempstring = getDescription(a_pFrame);
            if(tempstring == "Tempo")
                a_pSongtag->setTempo(getString(a_pFrame));
            else if(tempstring == "Situation")
                a_pSongtag->setSituation(getString(a_pFrame));
            else if(tempstring == "Mood")
                a_pSongtag->setMood(getString(a_pFrame));

            break;

        // saknas: bitrate, key

        default:
            break;
    }
}

string ID3TagImpEx::getString(ID3Frame *a_pFrame) const
{
    char buffer[513] = "";
    string data;

    ID3Field *pField = ID3Frame_GetField(a_pFrame, ID3FN_TEXT);
    if(pField) {
        ID3Field_GetASCII(pField, buffer, 512);
        data.assign(buffer);
    }

    return data;
}

std::string ID3TagImpEx::getDescription(ID3Frame *a_pFrame) const
{
    char buffer[513] = "";
    string data;

    ID3Field *pField = ID3Frame_GetField(a_pFrame, ID3FN_DESCRIPTION);
    if(pField) {
        ID3Field_GetASCII(pField, buffer, 512);
        data.assign(buffer);
    }

    return data;
}

std::string ID3TagImpEx::getLanguageFromCode(const string &a_languagecode) const
{
    // Använder ISO 639-2

    if(a_languagecode == "") return a_languagecode;

    stringmap::const_iterator iterator;
    iterator = m_languagecodes.find(a_languagecode);

    if(iterator == m_languagecodes.end())
        return "";

    return iterator->second;
}

std::string ID3TagImpEx::getCodeFromLanguage(const string &a_language) const
{
    // Använder ISO 639-2

    if(a_language == "") return a_language;

    stringmap::const_iterator iterator;
    for(iterator = m_languagecodes.begin(); iterator != m_languagecodes.end(); iterator++)
        if(stricmp(iterator->second.c_str(), a_language.c_str()) == 0)
            return iterator->first;

    return "";
}

string ID3TagImpEx::getTempoFromMusicMatch(const std::string &a_mmstring) const
{
//  The Tempo entry is intended to describe the general tempo of the song.  The
//  Jukebox application provided the following defaults: None, Fast, Pretty
//  fast, Moderate, Pretty slow, and Slow.

    if(a_mmstring == "Fast")
        return "Snabb";
    else if(a_mmstring == "Pretty fast")
        return "Ganska snabb";
    else if(a_mmstring == "Moderate")
        return "Lagom";
    else if(a_mmstring == "Pretty slow")
        return "Ganska långsam";
    else if(a_mmstring == "Slow")
        return "Långsam";

    return "";
}

string ID3TagImpEx::getMoodFromMusicMatch(const std::string &a_mmstring) const
{
//  The Mood entry describes what type of mood the audio establishes: Typical
//  values include the following: None, Wild, Upbeat, Morose, Mellow, Tranquil,
//  and Comatose.

    if(a_mmstring == "Wild")
        return "Vild";
    else if(a_mmstring == "Upbeat")
        return "Glad";
    else if(a_mmstring == "Morose")
        return "Surmulen";
    else if(a_mmstring == "Mellow")
        return "Lätt";
    else if(a_mmstring == "Tranquil")
        return "Stillsam";
    else if(a_mmstring == "Comatose")
        return "Dåsig";

    return "";
}

string ID3TagImpEx::getSituationFromMusicMatch(const std::string &a_mmstring) const
{
//  The Situation entry describes in which situation this music is best played.
//  Expect the following: None, Dance, Party, Romantic, Dinner, Background,
//  Seasonal, Rave, and Drunken Brawl.

    if(a_mmstring == "Dance")
        return "Dans";
    else if(a_mmstring == "Party")
        return "Fest";
    else if(a_mmstring == "Romantic")
        return "Romantik";
    else if(a_mmstring == "Dinner")
        return "Middag";
    else if(a_mmstring == "Background")
        return "Bakgrund";
    else if(a_mmstring == "Seasonal")
        return "Säsongsmässig";
    else if(a_mmstring == "Rave")
        return "Raseri";
    else if(a_mmstring == "Drunken Brawl")
        return "Fylleslagsmål";

    return "";

    /*
        BRA SITUATIONER:

        juletid
        middag
        avslappning
        fest
        dans
        romantik
    */
}

int ID3TagImpEx::getRatingFromMusicMatch(const std::string &a_mmstring) const
{
//  The Preference entry allows the user to rate the song.  Possible values
//  include the following: None, Excellent, Very Good, Good, Fair, Poor, and
//  Bad Taste.

    if(a_mmstring == "Bad Taste")
        return 20;
    else if(a_mmstring == "Poor")
        return 60;
    else if(a_mmstring == "Fair")
        return 110;
    else if(a_mmstring == "Good")
        return 150;
    else if(a_mmstring == "Very Good")
        return 190;
    else if(a_mmstring == "Excellent")
        return 230;

    return -1; // För None eller okänt värde
}

void ID3TagImpEx::createNewTag(ID3Tag *const a_pTag, const SongTag &a_songdata) const
{
    updateOrAdd(a_pTag, ID3FID_ALBUM, a_songdata.getAlbum());
    updateOrAdd(a_pTag, ID3FID_BAND, a_songdata.getBand());
    updateOrAdd(a_pTag, ID3FID_COMPOSER, a_songdata.getComposer());
    updateOrAdd(a_pTag, ID3FID_CONDUCTOR, a_songdata.getConductor());
    updateOrAdd(a_pTag, ID3FID_ENCODEDBY, a_songdata.getEncoder());
    updateOrAdd(a_pTag, ID3FID_MIXARTIST, a_songdata.getInterpreter());
    updateOrAdd(a_pTag, ID3FID_LEADARTIST, a_songdata.getLeadArtist());
    updateOrAdd(a_pTag, ID3FID_LYRICIST, a_songdata.getLyricist());
    updateOrAdd(a_pTag, ID3FID_UNSYNCEDLYRICS, a_songdata.getLyrics());
    updateOrAdd(a_pTag, ID3FID_ORIGALBUM, a_songdata.getOriginalAlbum());
    updateOrAdd(a_pTag, ID3FID_ORIGARTIST, a_songdata.getOriginalArtists());
    updateOrAdd(a_pTag, ID3FID_ORIGLYRICIST, a_songdata.getOriginalLyricist());
    updateOrAdd(a_pTag, ID3FID_PARTINSET, a_songdata.getPartOfSet());
    updateOrAdd(a_pTag, ID3FID_PUBLISHER, a_songdata.getPublisher());
    updateOrAdd(a_pTag, ID3FID_SUBTITLE, a_songdata.getSubtitle());
    updateOrAdd(a_pTag, ID3FID_TITLE, a_songdata.getTitle());
    updateOrAdd(a_pTag, ID3FID_TRACKNUM, a_songdata.getTrackNo());

    updateOrAdd(a_pTag, ID3FID_LANGUAGE, getCodeFromLanguage(a_songdata.getLanguages()));

    string bpm = string(IntToStr(a_songdata.getBPM()).c_str());
    if(bpm != "-1")
        updateOrAdd(a_pTag, ID3FID_BPM, bpm);

    ID3Frame *pFrame = 0;

    int rating = a_songdata.getRating();
    if(rating != -1) {
        pFrame = ID3Tag_FindFrameWithID(a_pTag, ID3FID_POPULARIMETER);
        if(pFrame) {
            ID3Field *pField = ID3Frame_GetField(pFrame, ID3FN_RATING);
            ID3Field_SetINT(pField, rating);
        }
        else {
            pFrame = ID3Frame_NewID(ID3FID_POPULARIMETER);
            if(pFrame) {
                ID3Field *pField = ID3Frame_GetField(pFrame, ID3FN_RATING);
                ID3Field_SetINT(pField, rating);
                ID3Tag_AttachFrame(a_pTag, pFrame);
                ID3Frame_Delete(pFrame);
            }
        }
    }

    pFrame = findFrameWithDescription(a_pTag, ID3FID_COMMENT, "ID3v1 Comment");
    if(pFrame)
        ID3Tag_RemoveFrame(a_pTag, pFrame);

    pFrame = findFrameWithDescription(a_pTag, ID3FID_COMMENT, "");
    if(pFrame)
        setString(pFrame, a_songdata.getComment());
    else {
        pFrame = ID3Frame_NewID(ID3FID_COMMENT);
        setString(pFrame, a_songdata.getComment());
        ID3Tag_AttachFrame(a_pTag, pFrame);
    }

    GenreRemixCover grc;
    grc.genre = a_songdata.getContentType();
    grc.remix = a_songdata.getRemix();
    grc.cover = a_songdata.getCover();

    updateOrAdd(a_pTag, ID3FID_CONTENTTYPE, m_genreparser.parseToTag(grc));

    updateOrAddUserText(a_pTag, "Tempo", a_songdata.getTempo());
    updateOrAddUserText(a_pTag, "Mood", a_songdata.getMood());
    updateOrAddUserText(a_pTag, "Situation", a_songdata.getSituation());

    string rectime = a_songdata.getRecordingTime();
    if(rectime != "") {
        string year, date;

        year = rectime.substr(0, 4);
        updateOrAdd(a_pTag, ID3FID_YEAR, year);

        if(rectime.length() == 10) {
            date = rectime.substr(8) + rectime.substr(5, 2);
            updateOrAdd(a_pTag, ID3FID_DATE, date);
        }
    }

    string oyear = a_songdata.getOriginalReleaseTime();
    if(oyear != "")
        updateOrAdd(a_pTag, ID3FID_ORIGYEAR, oyear);

//    återstår: key
}

void ID3TagImpEx::updateOrAdd(ID3Tag *const a_pTag, const ID3_FrameID &a_frameid,
    const string &a_data) const
{
    ID3Frame *pFrame = ID3Tag_FindFrameWithID(a_pTag, a_frameid);

    // Ska ta bort radbrytningar från enradiga fält

    if(pFrame) {
        if(a_data == "")
            ID3Tag_RemoveFrame(a_pTag, pFrame);
        else
            setString(pFrame, a_data);
    }
    else {
        if(a_data == "")
            return;

        pFrame = ID3Frame_NewID(a_frameid);
        if(pFrame) {
            setString(pFrame, a_data);
            ID3Tag_AttachFrame(a_pTag, pFrame);
        }
    }
}

void ID3TagImpEx::setString(ID3Frame *a_pFrame, const string &a_data) const
{
    ID3Field *pField = ID3Frame_GetField(a_pFrame, ID3FN_TEXT);
    ID3Field_SetASCII(pField, a_data.c_str());
}

void ID3TagImpEx::setDescription(ID3Frame *a_pFrame, const string &a_data) const
{
    ID3Field *pField = ID3Frame_GetField(a_pFrame, ID3FN_DESCRIPTION);
    ID3Field_SetASCII(pField, a_data.c_str());
}

void ID3TagImpEx::updateOrAddUserText(ID3Tag *const a_pTag, const string &a_description,
    const string &a_data) const
{
    ID3Frame *pFrame = findFrameWithDescription(a_pTag, ID3FID_USERTEXT, a_description);
    if(pFrame) {
        if(a_data == "")
            ID3Tag_RemoveFrame(a_pTag, pFrame);
        else {
            setDescription(pFrame, a_description);
            setString(pFrame, a_data);
        }
    }
    else {
        if(a_data == "")
            return;

        pFrame = ID3Frame_NewID(ID3FID_USERTEXT);
        setDescription(pFrame, a_description);
        setString(pFrame, a_data);
        ID3Tag_AttachFrame(a_pTag, pFrame);
    }
}

ID3Frame *ID3TagImpEx::findFrameWithDescription(ID3Tag *const a_pTag,
    const ID3_FrameID &a_frameid, const string &a_description) const
{
    vector<string> descriptions;
    string thisdescription;
    bool foundone = false;

    ID3Frame *pFrame = ID3Tag_FindFrameWithID(a_pTag, a_frameid);
    while(pFrame) {
        thisdescription = getDescription(pFrame);

        if(thisdescription == a_description) {
            foundone = true;
            break;
        }

        if(count(descriptions.begin(), descriptions.end(), thisdescription) == 0)
            descriptions.push_back(thisdescription);
        else
            break;

        pFrame = ID3Tag_FindFrameWithID(a_pTag, a_frameid);
    }

    if(!foundone)
        return NULL;

    return pFrame;
}

