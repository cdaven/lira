#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <map>
#include "..\Song\SongProperty.h"
#include "..\Song\SongTag.h"
#include "..\Song\FileManager.h"
#include "..\Exceptions.h"
#include "SongTestCases.h"

//---------------------------------------------------------------------------
SongProperty_::SongProperty_() : TestCase(typeid(*this).name())
{
    count(); nextFunction();
    isEmptyButForIndex(); nextFunction();
    clear(); nextFunction();
    getPropertyLeftValue(); nextFunction();
    getPropertyRightValueInt(); nextFunction();
    getPropertyRightValueString(); nextFunction();
    setPropertyRightValue(); nextFunction();
    addProperty(); nextFunction();
}

void SongProperty_::count()
{
    // ett nytt objekt ska ha noll element
    SongProperty sp;
    assert(sp.count() == 0);

    // ett element läggs till
    sp.addProperty("x");
    assert(sp.count() == 1);

    // ännu ett element läggs till
    sp.addProperty("y");
    assert(sp.count() == 2);
}

void SongProperty_::isEmptyButForIndex()
{
    // ett nytt objekt ska vara tomt
    SongProperty sp;
    assert(sp.isEmptyButForIndex() == true);

    // lägger till ett index-attribut
    sp.addProperty("index", "1");
    assert(sp.isEmptyButForIndex() == true);

    // lägger till ett annat, tomt attribut
    sp.addProperty("x");
    assert(sp.isEmptyButForIndex() == true);

    // lägger in data i det tomma attributet
    sp.setPropertyRightValue("x", "1");
    assert(sp.isEmptyButForIndex() == false);
}

void SongProperty_::clear()
{
    // tömmer ett tomt objekt
    SongProperty sp;
    sp.clear();
    assert(sp.count() == 0);

    // lägger till ett tomt attribut och tömmer
    sp.addProperty("x");
    sp.clear();
    assert(sp.count() == 0);

    // lägger till attribut plus data och tömmer
    sp.addProperty("w", "x");
    sp.addProperty("y", "z");
    sp.clear();
    assert(sp.count() == 0);
}

void SongProperty_::getPropertyLeftValue()
{
    // ett tomt objekt ska returnera null
    SongProperty sp;
    assert(sp.getPropertyLeftValue(1) == "");

    // lägger till attribut och hämtar icke-existerande
    sp.addProperty("x");
    sp.addProperty("y");
    assert(sp.getPropertyLeftValue(20) == "");
    assert(sp.getPropertyLeftValue(1) == "y");
}

void SongProperty_::getPropertyRightValueInt()
{
    // ett tomt objekt ska returnera null
    SongProperty sp;
    assert(sp.getPropertyRightValue(1) == "");

    // lägger till attribut och hämtar data
    sp.addProperty("x");
    sp.addProperty("y", "123");
    assert(sp.getPropertyRightValue(20) == "");
    assert(sp.getPropertyRightValue(1) == "123");
    assert(sp.getPropertyRightValue(0) == "");
}

void SongProperty_::getPropertyRightValueString()
{
    // ett tomt objekt ska returnera null
    SongProperty sp;
    assert(sp.getPropertyRightValue("x") == "");

    // lägger till attribut och hämtar data
    sp.addProperty("x");
    sp.addProperty("y", "123");
    assert(sp.getPropertyRightValue("w") == "");
    assert(sp.getPropertyRightValue("y") == "123");
    assert(sp.getPropertyRightValue("x") == "");
}

void SongProperty_::setPropertyRightValue()
{
    SongProperty sp;
    bool success = false;

    // försöker sätta data på ett attribut som inte finns
    try {
        sp.setPropertyRightValue("x", "1");
    }
    catch(NotInContainerException &) {
        success = true;
    }

    assert(success);

    // ändrar data på ett attribut
    sp.addProperty("y", "23");
    sp.addProperty("z");
    sp.setPropertyRightValue("y", "w");
    assert(sp.getPropertyRightValue("y") == "w");
}

void SongProperty_::addProperty()
{
    SongProperty sp;

    // lägger till ett attribut
    sp.addProperty("x");
    assert(sp.getPropertyLeftValue(0) == "x");

    // förändrar värdet på detta attribut
    sp.addProperty("x", "zzz");
    assert(sp.getPropertyRightValue("x") == "zzz");
}
//---------------------------------------------------------------------------
SongTag_::SongTag_() : TestCase(typeid(*this).name())
{
    getsetAlbum(); nextFunction();
    getsetBand(); nextFunction();
    getsetBitrate(); nextFunction();
    getsetBPM(); nextFunction();
    getsetComment(); nextFunction();
    getsetComposer(); nextFunction();
    getsetConductor(); nextFunction();
    getsetContentType(); nextFunction();
    getsetCover(); nextFunction();
    getsetEncoder(); nextFunction();
    getsetInterpreter(); nextFunction();
    getsetKey(); nextFunction();
    getsetLanguages(); nextFunction();
    getsetLeadArtist(); nextFunction();
    getsetLength(); nextFunction();
    getsetLyricist(); nextFunction();
    getsetLyrics(); nextFunction();
    getsetMood(); nextFunction();
    getsetOriginalAlbum(); nextFunction();
    getsetOriginalArtists(); nextFunction();
    getsetOriginalLyricist(); nextFunction();
    getsetOriginalReleaseTime(); nextFunction();
    getsetPartOfSet(); nextFunction();
    getsetPublisher(); nextFunction();
    getsetRating(); nextFunction();
    getsetRecordingTime(); nextFunction();
    getsetReleaseTime(); nextFunction();
    getsetRemix(); nextFunction();
    getsetSituation(); nextFunction();
    getsetSubtitle(); nextFunction();
    getsetTempo(); nextFunction();
    getsetTitle(); nextFunction();
    getsetTrackNo(); nextFunction();
}

void SongTag_::getsetAlbum()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getAlbum() == "");

    // sätter albumnamnet och hämtar det
    st.setAlbum("xyz");
    assert(st.getAlbum() == "xyz");
}

void SongTag_::getsetBand()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getBand() == "");

    // sätter bandnamnet och hämtar det
    st.setBand("xyz");
    assert(st.getBand() == "xyz");
}

void SongTag_::getsetBitrate()
{
    // en ny tagg ska inte ha någon bitrate
    SongTag st;
    assert(st.getBitrate() == -1);

    // sätter bitraten och hämtar den
    st.setBitrate(128);
    assert(st.getBitrate() == 128);
}

void SongTag_::getsetBPM()
{
    // en ny tagg ska inte ha någon BPM
    SongTag st;
    assert(st.getBPM() == -1);

    // sätter bpm och hämtar det
    st.setBPM(100);
    assert(st.getBPM() == 100);
}

void SongTag_::getsetComment()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getComment() == "");

    // sätter kommentaren och hämtar den
    st.setComment("xyz");
    assert(st.getComment() == "xyz");
}

void SongTag_::getsetComposer()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getComposer() == "");

    // sätter kompositören och hämtar den
    st.setComposer("xyz");
    assert(st.getComposer() == "xyz");
}

void SongTag_::getsetConductor()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getConductor() == "");

    // sätter dirigenten och hämtar den
    st.setConductor("xyz");
    assert(st.getConductor() == "xyz");
}

void SongTag_::getsetContentType()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getContentType() == "");

    // sätter genren och hämtar den
    st.setContentType("xyz");
    assert(st.getContentType() == "xyz");
}

void SongTag_::getsetCover()
{
    // en ny tagg ska inte vara en cover
    SongTag st;
    assert(st.getCover() == false);

    // sätter cover och hämtar det
    st.setCover(true);
    assert(st.getCover() == true);
}

void SongTag_::getsetEncoder()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getEncoder() == "");

    // sätter kodaren och hämtar den
    st.setEncoder("xyz");
    assert(st.getEncoder() == "xyz");
}

void SongTag_::getsetInterpreter()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getInterpreter() == "");

    // sätter "tolken" och hämtar den
    st.setInterpreter("xyz");
    assert(st.getInterpreter() == "xyz");
}

void SongTag_::getsetKey()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getKey() == "");

    // sätter tonarten och hämtar den
    st.setKey("xyz");
    assert(st.getKey() == "xyz");
}

void SongTag_::getsetLanguages()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getLanguages() == "");

    // sätter språk och hämtar det
    st.setLanguages("xyz");
    assert(st.getLanguages() == "xyz");
}

void SongTag_::getsetLeadArtist()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getLeadArtist() == "");

    // sätter artisten och hämtar den
    st.setLeadArtist("xyz");
    assert(st.getLeadArtist() == "xyz");
}

void SongTag_::getsetLength()
{
    // en ny tagg ska inte ha någon längd
    SongTag st;
    assert(st.getLength() == -1);

    // sätter längden och hämtar den
    st.setLength(600);
    assert(st.getLength() == 600);
}

void SongTag_::getsetLyricist()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getLyricist() == "");

    // sätter textförfattaren och hämtar den
    st.setLyricist("xyz");
    assert(st.getLyricist() == "xyz");
}

void SongTag_::getsetLyrics()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getLyrics() == "");

    // sätter sångtexten och hämtar den
    st.setLyrics("xyz");
    assert(st.getLyrics() == "xyz");
}

void SongTag_::getsetMood()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getMood() == "");

    // sätter humöret och hämtar det
    st.setMood("xyz");
    assert(st.getMood() == "xyz");
}

void SongTag_::getsetOriginalAlbum()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getOriginalAlbum() == "");

    // sätter ursprungligt albumnamn och hämtar det
    st.setOriginalAlbum("xyz");
    assert(st.getOriginalAlbum() == "xyz");
}

void SongTag_::getsetOriginalArtists()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getOriginalArtists() == "");

    // sätter ursprungliga artister och hämtar dem
    st.setOriginalArtists("xyz");
    assert(st.getOriginalArtists() == "xyz");
}

void SongTag_::getsetOriginalLyricist()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getOriginalLyricist() == "");

    // sätter ursprunglig textförfattare och hämtar den
    st.setOriginalLyricist("xyz");
    assert(st.getOriginalLyricist() == "xyz");
}

void SongTag_::getsetOriginalReleaseTime()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getOriginalReleaseTime() == "");

    // sätter ursprungligt utgivningsdatum och hämtar det
    st.setOriginalReleaseTime("1931");
    assert(st.getOriginalReleaseTime() == "1931");

    st.setOriginalReleaseTime("1945-08");
    assert(st.getOriginalReleaseTime() == "1945-08");

    st.setOriginalReleaseTime("1972-07-11");
    assert(st.getOriginalReleaseTime() == "1972-07-11");

    // nollställer datumet och kontrollerar
    st.setOriginalReleaseTime("");
    assert(st.getOriginalReleaseTime() == "");

    // allmänna datum-tester som gäller för alla *time-fkner

    // sätter felaktigt datum och hämtar det
    st.setOriginalReleaseTime("0325");
    assert(st.getOriginalReleaseTime() == "");

    st.setOriginalReleaseTime("1997-00");
    assert(st.getOriginalReleaseTime() == "");

    st.setOriginalReleaseTime("1997-28");
    assert(st.getOriginalReleaseTime() == "");

    st.setOriginalReleaseTime("1997-13");
    assert(st.getOriginalReleaseTime() == "");

    st.setOriginalReleaseTime("1971-12-00");
    assert(st.getOriginalReleaseTime() == "");

    st.setOriginalReleaseTime("1971-12-86");
    assert(st.getOriginalReleaseTime() == "");

    st.setOriginalReleaseTime("1971-12-33");
    assert(st.getOriginalReleaseTime() == "");

    st.setOriginalReleaseTime("a");
    assert(st.getOriginalReleaseTime() == "");

    st.setOriginalReleaseTime("abcd");
    assert(st.getOriginalReleaseTime() == "");

    st.setOriginalReleaseTime("abcdefg");
    assert(st.getOriginalReleaseTime() == "");

    st.setOriginalReleaseTime("1234efg");
    assert(st.getOriginalReleaseTime() == "");

    st.setOriginalReleaseTime("1234e67");
    assert(st.getOriginalReleaseTime() == "");

    st.setOriginalReleaseTime("abcdefghij");
    assert(st.getOriginalReleaseTime() == "");

    st.setOriginalReleaseTime("1234efghij");
    assert(st.getOriginalReleaseTime() == "");

    st.setOriginalReleaseTime("1234e67hij");
    assert(st.getOriginalReleaseTime() == "");

    st.setOriginalReleaseTime("1234e67h90");
    assert(st.getOriginalReleaseTime() == "");
}

void SongTag_::getsetPartOfSet()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getPartOfSet() == "");

    // sätter "del i set" och hämtar det
    st.setPartOfSet("xyz");
    assert(st.getPartOfSet() == "xyz");
}

void SongTag_::getsetPublisher()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getPublisher() == "");

    // sätter utgivaren och hämtar den
    st.setPublisher("xyz");
    assert(st.getPublisher() == "xyz");
}

void SongTag_::getsetRating()
{
    // en ny tagg ska inte ha någon längd
    SongTag st;
    assert(st.getRating() == -1);

    // sätter betyget och hämtar det
    st.setRating(50);
    assert(st.getRating() == 50);
}

void SongTag_::getsetRecordingTime()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getRecordingTime() == "");

    // sätter inspelningsdatum och hämtar det
    st.setRecordingTime("1931");
    assert(st.getRecordingTime() == "1931");

    st.setRecordingTime("1945-08");
    assert(st.getRecordingTime() == "1945-08");

    st.setRecordingTime("1972-07-11");
    assert(st.getRecordingTime() == "1972-07-11");
}

void SongTag_::getsetReleaseTime()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getReleaseTime() == "");

    // sätter utgivningsdatum och hämtar det
    st.setReleaseTime("1931");
    assert(st.getReleaseTime() == "1931");

    st.setReleaseTime("1945-08");
    assert(st.getReleaseTime() == "1945-08");

    st.setReleaseTime("1972-07-11");
    assert(st.getReleaseTime() == "1972-07-11");
}

void SongTag_::getsetRemix()
{
    // en ny tagg ska inte vara en remix
    SongTag st;
    assert(st.getRemix() == false);

    // sätter remix och hämtar det
    st.setRemix(true);
    assert(st.getRemix() == true);
}

void SongTag_::getsetSituation()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getSituation() == "");

    // sätter tillfället och hämtar det
    st.setSituation("xyz");
    assert(st.getSituation() == "xyz");
}

void SongTag_::getsetSubtitle()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getSubtitle() == "");

    // sätter undertiteln och hämtar den
    st.setSubtitle("xyz");
    assert(st.getSubtitle() == "xyz");
}

void SongTag_::getsetTempo()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getTempo() == "");

    // sätter tempot och hämtar det
    st.setTempo("xyz");
    assert(st.getTempo() == "xyz");
}

void SongTag_::getsetTitle()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getTitle() == "");

    // sätter titeln och hämtar den
    st.setTitle("xyz");
    assert(st.getTitle() == "xyz");
}

void SongTag_::getsetTrackNo()
{
    // en ny tagg ska inte ha någon sträng
    SongTag st;
    assert(st.getTrackNo() == "");

    // sätter spårnumret och hämtar det
    st.setTrackNo("xyz");
    assert(st.getTrackNo() == "xyz");
}
//---------------------------------------------------------------------------
DummySongFacade::DummySongFacade()
{
    esong = 0;
    csong = 1;
    rsong = 2;
    nsong1 = 3;
    nsong2 = 4;
    csong2 = 5;

    existingsong = "D:\\programming\\projects\\mp3org\\mp3test\\folder 2\\Bette Midler - The Rose (live).mp3";
    existingsongsize = "3104768";

    changedsong = "D:\\programming\\projects\\mp3org\\mp3test\\Elvis Presley - Rubberneckin' (Paul Oakenfold Remix Radio Edit).mp3";
    changedsongsize = "1234567";

    removedsong = "D:\\programming\\projects\\mp3org\\mp3test\\Blaha blaha.mp3";
    removedsongsize = "564321";

    newsong1 = "D:\\programming\\projects\\mp3org\\mp3test\\folder 1\\Annie Lennox - A Whiter Shade of Pale.mp3";
    newsong2 = "D:\\programming\\projects\\mp3org\\mp3test\\folder 1\\folder 1-1\\Björn Skifs - No Particular Place to Go.mp3";
}

int DummySongFacade::addSong(const AnsiString &a_song)
{
    addedsongs.push_back(a_song);

    if(a_song == newsong1)
        return nsong1;
    if(a_song == newsong2)
        return nsong2;
    if(a_song == changedsong)
        return csong2;

    throw new Exception("");
}

void DummySongFacade::removeSong(int a_song)
{
    removedsongs.push_back(a_song);
}

vector<int> DummySongFacade::getSongsMatchingProperties(const SongProperty &a_sp) const
{
    vector<int> vs;
    int s;

    if(a_sp.getPropertyRightValue(properties::INDEX) == "*") {
        s = esong;
        vs.push_back(s);
        s = csong;
        vs.push_back(s);
        s = rsong;
        vs.push_back(s);
    }
    if(a_sp.getPropertyRightValue(properties::FILENAME) == existingsong) {
        s = esong;
        vs.push_back(s);
    }
    if(a_sp.getPropertyRightValue(properties::FILENAME) == changedsong) {
        s = csong;
        vs.push_back(s);
    }
    if(a_sp.getPropertyRightValue(properties::FILENAME) == removedsong) {
        s = rsong;
        vs.push_back(s);
    }

    return vs;
}

void DummySongFacade::getSongProperties(int a_song, SongProperty *a_sp) const
{
    if(a_song == esong) {
        a_sp->setPropertyRightValue(properties::FILENAME, existingsong);
        a_sp->setPropertyRightValue(properties::FILESIZE, existingsongsize);
    }
    if(a_song == csong) {
        a_sp->setPropertyRightValue(properties::FILENAME, changedsong);
        a_sp->setPropertyRightValue(properties::FILESIZE, changedsongsize);
    }
    if(a_song == rsong) {
        a_sp->setPropertyRightValue(properties::FILENAME, removedsong);
        a_sp->setPropertyRightValue(properties::FILESIZE, removedsongsize);
    }
}

void DummySongFacade::updateDatabase(vector<int> a_db) const
{
    #pragma warn -8037
    database.assign(a_db.begin(), a_db.end());
    #pragma warn .8037
}

FileManager_::FileManager_() : TestCase(typeid(*this).name())
{
    updatePath(); nextFunction();
    getFileFromList(); nextFunction();
    compareFiles(); nextFunction();
    traverseAndCheckPath(); nextFunction();
    removeSongsNotFound(); nextFunction();
}

void FileManager_::updatePath()
{
    DummySongFacade d;
    FileManager fm((SongFacade*)&d);

    fm.updatePath("D:\\programming\\projects\\mp3org\\mp3test");

    assert(isInVector(d.newsong1, d.addedsongs));
    assert(isInVector(d.newsong2, d.addedsongs));
    assert(isInVector(d.changedsong, d.addedsongs));
    assert(d.addedsongs.size() == 3);

    assert(isInVector(2, d.removedsongs));
    assert(d.removedsongs.size() == 1);

    assert(isInVector(d.esong, d.database) == false);
    assert(d.database.size() == 4);
}

void FileManager_::getFileFromList()
{
    Dummy d;
    FileManager fm((SongFacade*)&d);

    map<string, File> files;

    File ftemp;
    ftemp.name = "ett";
    files["ett"] = ftemp;

    ftemp.name = "två";
    files["två"] = ftemp;

    assert((fm.getFileFromList("två", &files)).name == "två");
    assert((fm.getFileFromList("tre", &files)).name == "");
}

void FileManager_::compareFiles()
{
    Dummy d;
    FileManager fm((SongFacade*)&d);

    File one;
    one.name = "one";
    one.size = 100;
    one.time = 50;

    File two;
    two.name = "two";
    two.size = 100;
    two.time = 50;

    File three;
    three.name = "three";
    three.size = 150;
    three.time = 100;

    assert(fm.compareFiles(one, two) == true);
    assert(fm.compareFiles(one, three) == false);
}

void FileManager_::traverseAndCheckPath()
{
    DummySongFacade d;
    FileManager fm((SongFacade*)&d);

    map<string, File> files;
    vector<int> songs;

    File tempfile;

    tempfile.name = string(d.existingsong.c_str());
    tempfile.size = d.existingsongsize.ToInt();
    files[string(d.existingsong.c_str())] = tempfile;

    tempfile.name = string(d.changedsong.c_str());
    tempfile.size = d.changedsongsize.ToInt();
    files[string(d.changedsong.c_str())] = tempfile;

    tempfile.name = string(d.removedsong.c_str());
    tempfile.size = d.removedsongsize.ToInt();
    files[string(d.removedsong.c_str())] = tempfile;

    fm.traverseAndCheckPath("D:\\programming\\projects\\mp3org\\mp3test", &files, &songs);

    assert(isInVector(d.csong2, songs));
    assert(isInVector(d.nsong1, songs));
    assert(isInVector(d.nsong2, songs));
    assert(songs.size() == 3);

    assert(isInVector(d.newsong1, d.addedsongs));
    assert(isInVector(d.newsong2, d.addedsongs));
    assert(isInVector(d.changedsong, d.addedsongs));
    assert(d.addedsongs.size() == 3);

    assert(files[string(d.removedsong.c_str())].name == d.removedsong.c_str());
    assert(files.size() == 1);
}

void FileManager_::removeSongsNotFound()
{
    DummySongFacade d;
    FileManager fm((SongFacade*)&d);

    map<string, File> files;
    vector<int> songs;

    File tempfile;
    tempfile.name = string(d.removedsong.c_str());
    files[string(d.removedsong.c_str())] = tempfile;

    songs.push_back(d.csong);
    songs.push_back(d.nsong1);
    songs.push_back(d.nsong2);

    fm.removeSongsNotFound(files, &songs);

    assert(isInVector(d.rsong, d.removedsongs));
    assert(d.removedsongs.size() == 1);

    assert(isInVector(d.rsong, songs));
    assert(songs.size() == 4);
}

