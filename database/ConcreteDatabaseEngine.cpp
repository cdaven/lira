#include "../Headers.h"
#pragma hdrstop

#include "ConcreteDatabaseEngine.h"
#include "../Song/SongProperty.h"
#include "../Song/Song.h"
#include "../Playlist/PlaylistTransfer.h"
#include "../Constants.h"

ConcreteDatabaseEngine::ConcreteDatabaseEngine()
{
//    char tempchars[7];
//    ifstream dbfile(database::FILENAME_SONGS, ios_base::in);
//
//    if(dbfile.is_open()) {
//        dbfile.getline(tempchars, 7);
//
//        if(strcmp(tempchars, database::VERSION) != 0)
//            throw BadFileFormatException("ConcreteDatabaseEngine::ConcreteDatabaseEngine");
//    }
//    else
//        throw EInOutError("ConcreteDatabaseEngine::ConcreteDatabaseEngine");
}

ConcreteDatabaseEngine::~ConcreteDatabaseEngine()
{
}

vector<SongProperty> ConcreteDatabaseEngine::getSongs() const
{
    SongProperty tempsong;
    vector<SongProperty> songs;
    vector<string> lines;
    string part;

    lines = readFileData(database::FILENAME_SONGS);

    for(unsigned int i = 0; i < lines.size(); i++) {
        tempsong.clear();

        // Hårdkodat antal attribut per låt
        for(int j = 1; j < 38; j++) {
            part = getFirstPart(lines[i]);

            lines[i].erase(0, part.length() + 1);
            AnsiString ap(part.c_str());

            switch(j) {
                case  1: if(!ap.IsEmpty()) tempsong.addProperty(properties::INDEX, ap); break;
                case  2: if(!ap.IsEmpty()) tempsong.addProperty(properties::FILENAME, ap); break;
                case  3: if(!ap.IsEmpty()) tempsong.addProperty(properties::FILESIZE, ap); break;
                case  4: if(!ap.IsEmpty()) tempsong.addProperty(properties::FILEAGE, ap); break;
                case  5: if(!ap.IsEmpty()) tempsong.addProperty(properties::ALBUM, ap); break;
                case  6: if(!ap.IsEmpty()) tempsong.addProperty(properties::BAND, ap); break;
                case  7: if(!ap.IsEmpty()) tempsong.addProperty(properties::COMMENT, ap); break;
                case  8: if(!ap.IsEmpty()) tempsong.addProperty(properties::COMPOSER, ap); break;
                case  9: if(!ap.IsEmpty()) tempsong.addProperty(properties::CONDUCTOR, ap); break;
                case 10: if(!ap.IsEmpty()) tempsong.addProperty(properties::CONTENTTYPE, ap); break;
                case 11: if(!ap.IsEmpty()) tempsong.addProperty(properties::ENCODER, ap); break;
                case 12: if(!ap.IsEmpty()) tempsong.addProperty(properties::INTERPRETER, ap); break;
                case 13: if(!ap.IsEmpty()) tempsong.addProperty(properties::KEY, ap); break;
                case 14: if(!ap.IsEmpty()) tempsong.addProperty(properties::LANGUAGES, ap); break;
                case 15: if(!ap.IsEmpty()) tempsong.addProperty(properties::LEADARTIST, ap); break;
                case 16: if(!ap.IsEmpty()) tempsong.addProperty(properties::LYRICIST, ap); break;
                case 17: if(!ap.IsEmpty()) tempsong.addProperty(properties::LYRICS, ap); break;
                case 18: if(!ap.IsEmpty()) tempsong.addProperty(properties::MOOD, ap); break;
                case 19: if(!ap.IsEmpty()) tempsong.addProperty(properties::ORIGINALALBUM, ap); break;
                case 20: if(!ap.IsEmpty()) tempsong.addProperty(properties::ORIGINALARTISTS, ap); break;
                case 21: if(!ap.IsEmpty()) tempsong.addProperty(properties::ORIGINALLYRICIST, ap); break;
                case 22: if(!ap.IsEmpty()) tempsong.addProperty(properties::ORIGINALRELEASETIME, ap); break;
                case 23: if(!ap.IsEmpty()) tempsong.addProperty(properties::PARTOFSET, ap); break;
                case 24: if(!ap.IsEmpty()) tempsong.addProperty(properties::PUBLISHER, ap); break;
                case 25: if(!ap.IsEmpty()) tempsong.addProperty(properties::RECORDINGTIME, ap); break;
                case 26: if(!ap.IsEmpty()) tempsong.addProperty(properties::RELEASETIME, ap); break;
                case 27: if(!ap.IsEmpty()) tempsong.addProperty(properties::SITUATION, ap); break;
                case 28: if(!ap.IsEmpty()) tempsong.addProperty(properties::SUBTITLE, ap); break;
                case 29: if(!ap.IsEmpty()) tempsong.addProperty(properties::TEMPO, ap); break;
                case 30: if(!ap.IsEmpty()) tempsong.addProperty(properties::TITLE, ap); break;
                case 31: if(!ap.IsEmpty()) tempsong.addProperty(properties::TRACKNO, ap); break;
                case 32: if(!ap.IsEmpty()) tempsong.addProperty(properties::BITRATE, ap); break;
                case 33: if(!ap.IsEmpty()) tempsong.addProperty(properties::BPM, ap); break;
                case 34: if(!ap.IsEmpty()) tempsong.addProperty(properties::LENGTH, ap); break;
                case 35: if(!ap.IsEmpty()) tempsong.addProperty(properties::RATING, ap); break;
                case 36: if(!ap.IsEmpty()) tempsong.addProperty(properties::COVER, ap); break;
                case 37: if(!ap.IsEmpty()) tempsong.addProperty(properties::REMIX, ap); break;
            }
        }

        songs.push_back(tempsong);
    }

    return songs;
}

void ConcreteDatabaseEngine::updateSong(int a_songindex, const SongProperty &a_songproperties) const
{
    vector<string> lines;
    char songindex[5] = "";
    string lineindex;
    bool found = false;

    itoa(a_songindex, songindex, 10);

    // läs in hela filen
    lines = readFileData(database::FILENAME_SONGS);

    for(unsigned int i = 0; i < lines.size(); i++) {
        // identifiera rätt rad
        lineindex = getFirstPart(lines[i]);
        if(stricmp(songindex, lineindex.c_str()) == 0) {
            found = true;

            // ändra raden

            if(a_songproperties.isEmptyButForIndex()) {
                lines[i] = "";
                break;
            }

            lines[i] = getSongData(a_songproperties);
            break;
        }
    }

    if(!found)
        lines.push_back(getSongData(a_songproperties));

    // skriv hela filen

    ofstream dbfile(database::FILENAME_SONGS, ios_base::out);
    if(!dbfile.is_open())
        throw EInOutError("ConcreteDatabaseEngine::updateSong");

    dbfile << "DATA01\n";

    string templine;
    for(unsigned int i = 0; i < lines.size(); i++) {
        templine = lines[i];

        if(templine != "") {
            encodeData(&templine);
            dbfile << templine << "\n";
        }
    }
}

void ConcreteDatabaseEngine::updateSongs(vector<SongProperty> a_songs) const
{
    vector<string> lines;
    vector<SongProperty>::iterator iterator;
    string lineindex;
    AnsiString songindex;

    // läs in hela filen
    lines = readFileData(database::FILENAME_SONGS);

    for(unsigned int i = 0; i < lines.size(); i++) {
        lineindex = getFirstPart(lines[i]);

        for(iterator = a_songs.begin(); iterator != a_songs.end(); iterator++) {
            songindex = iterator->getPropertyRightValue(properties::INDEX);
            if(stricmp(songindex.c_str(), lineindex.c_str()) == 0) {
                if(iterator->isEmptyButForIndex())
                    lines[i] = "";
                else
                    lines[i] = getSongData(*iterator);

                a_songs.erase(iterator);
                break;
            }
        }
    }

    for(unsigned int i = 0; i < a_songs.size(); i++)
        lines.push_back(getSongData(a_songs[i]));

    ofstream dbfile(database::FILENAME_SONGS, ios_base::out);
    if(!dbfile.is_open())
        throw EInOutError("ConcreteDatabaseEngine::updateSongs");

    dbfile << "DATA01\n";

    string templine;
    for(unsigned int i = 0; i < lines.size(); i++) {
        templine = lines[i];

        if(templine != "") {
            encodeData(&templine);
            dbfile << templine << "\n";
        }
    }
}


//vector<SmartPlaylistTransfer> ConcreteDatabaseEngine::getSmartPlaylists() const
//{
//    SmartPlaylistTransfer           tempspt;
//    SongProperty                    tempplaylist;
//    string                          tempname;
//
//    vector<SmartPlaylistTransfer>   playlists;
//    vector<string>                  lines;
//    string                          part;
//
//    lines = readFileData(database::smartplfilename);
//
//    for(unsigned int i = 0; i < lines.size(); i++) {
//        tempplaylist.clear();
//
//        // Hårdkodat antal attribut per låt
//        for(int j = 0; j < 38; j++) {
//            part = getFirstPart(lines[i]);
//            lines[i].erase(0, part.length() + 1);
//            AnsiString ap(part.c_str());
//
//            switch(j) {
//                case  0: tempname = part; break;
//                case  1: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::INDEX, ap); break;
//                case  2: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::FILENAME, ap); break;
//                case  3: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::FILESIZE, ap); break;
//                case  4: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::FILEAGE, ap); break;
//                case  5: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::ALBUM, ap); break;
//                case  6: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::BAND, ap); break;
//                case  7: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::COMMENT, ap); break;
//                case  8: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::COMPOSER, ap); break;
//                case  9: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::CONDUCTOR, ap); break;
//                case 10: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::CONTENTTYPE, ap); break;
//                case 11: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::ENCODER, ap); break;
//                case 12: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::INTERPRETER, ap); break;
//                case 13: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::KEY, ap); break;
//                case 14: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::LANGUAGES, ap); break;
//                case 15: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::LEADARTIST, ap); break;
//                case 16: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::LYRICIST, ap); break;
//                case 17: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::LYRICS, ap); break;
//                case 18: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::MOOD, ap); break;
//                case 19: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::ORIGINALALBUM, ap); break;
//                case 20: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::ORIGINALARTISTS, ap); break;
//                case 21: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::ORIGINALLYRICIST, ap); break;
//                case 22: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::ORIGINALRELEASETIME, ap); break;
//                case 23: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::PARTOFSET, ap); break;
//                case 24: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::PUBLISHER, ap); break;
//                case 25: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::RECORDINGTIME, ap); break;
//                case 26: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::RELEASETIME, ap); break;
//                case 27: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::SITUATION, ap); break;
//                case 28: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::SUBTITLE, ap); break;
//                case 29: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::TEMPO, ap); break;
//                case 30: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::TITLE, ap); break;
//                case 31: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::TRACKNO, ap); break;
//                case 32: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::BITRATE, ap); break;
//                case 33: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::BPM, ap); break;
//                case 34: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::LENGTH, ap); break;
//                case 35: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::RATING, ap); break;
//                case 36: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::COVER, ap); break;
//                case 37: if(!ap.IsEmpty()) tempplaylist.addProperty(properties::REMIX, ap); break;
//            }
//        }
//
//        tempspt.name = tempname;
//        tempspt.properties = tempplaylist;
//
//        playlists.push_back(tempspt);
//    }
//
//    return playlists;
//}
//
//vector<SimplePlaylistTransfer> ConcreteDatabaseEngine::getSimplePlaylists() const
//{
//    SimplePlaylistTransfer          tempspt;
//    vector<int>                     tempplaylist;
//    string                          tempname;
//    vector<SimplePlaylistTransfer>  playlists;
//    vector<string>                  lines;
//    string                          part;
//    int                             tempsong;
//
//    lines = readFileData(database::simpleplfilename);
//
//    for(unsigned int i = 0; i < lines.size(); i++) {
//        tempplaylist.clear();
//
//        part = getFirstPart(lines[i]);
//        lines[i].erase(0, part.length() + 1);
//
//        if(!part.empty())
//            tempname = part;
//        else
//            continue;
//
//        part = getFirstPart(lines[i]);
//        while(!part.empty()) {
//            lines[i].erase(0, part.length() + 1);
//
//            try {
//                tempsong = StrToInt(AnsiString(part.c_str()));
//            }
//            catch(EConvertError &) {
//                break;
//            }
//
//            tempplaylist.push_back(tempsong);
//
//            part = getFirstPart(lines[i]);
//        }
//
//        tempspt.name = tempname;
//        tempspt.songs = tempplaylist;
//
//        playlists.push_back(tempspt);
//    }
//
//    return playlists;
//}
//
//void ConcreteDatabaseEngine::updatePlaylist(const SmartPlaylistTransfer &a_playlisttransfer) const
//{
//    SongProperty    playlist = a_playlisttransfer.properties;
//    vector<string>  lines;
//    string          playlistname = a_playlisttransfer.name;
//    string          tempname;
//    bool            found = false;
//
//    // läs in hela filen
//    lines = readFileData(database::smartplfilename);
//
//    for(unsigned int i = 0; i < lines.size(); i++) {
//        // identifiera rätt rad
//        tempname = getFirstPart(lines[i]);
//        if(stricmp(tempname.c_str(), playlistname.c_str()) == 0) {
//            found = true;
//
//            // ändra raden
//
//            if(playlist.isEmpty()) {
//                lines[i] = "";
//                break;
//            }
//
//            lines[i] = playlistname + database::DELIMITER1 + getSongData(playlist);
//            break;
//        }
//    }
//
//    if(!found)
//        lines.push_back(playlistname + database::DELIMITER1 + getSongData(playlist));
//
//    // skriv hela filen
//
//    ofstream dbfile(database::smartplfilename, ios_base::out);
//    if(!dbfile.is_open())
//        throw EInOutError("ConcreteDatabaseEngine::updatePlaylist");
//
//    dbfile << "DATA01\n";
//
//    string templine;
//    for(unsigned int i = 0; i < lines.size(); i++) {
//        templine = lines[i];
//
//        if(templine != "") {
//            encodeData(&templine);
//            dbfile << templine << "\n";
//        }
//    }
//}
//
//void ConcreteDatabaseEngine::updatePlaylist(const SimplePlaylistTransfer &a_playlisttransfer) const
//{
//    vector<int>     playlist = a_playlisttransfer.songs;
//    vector<string>  lines;
//    string          playlistname = a_playlisttransfer.name;
//    string          tempname;
//    string          tempsongs;
//    bool            found = false;
//
//    // läs in hela filen
//    lines = readFileData(database::simpleplfilename);
//
//    for(unsigned int i = 0; i < lines.size(); i++) {
//        // identifiera rätt rad
//        tempname = getFirstPart(lines[i]);
//
//        if(stricmp(tempname.c_str(), playlistname.c_str()) == 0) {
//            found = true;
//
//            // ändra raden
//
//            if(playlist.empty()) {
//                lines[i] = "";
//                break;
//            }
//
//            tempsongs = "";
//            for(unsigned int j = 0; j < playlist.size(); j++)
//                tempsongs += string(IntToStr(playlist[j]).c_str()) + database::DELIMITER1;
//
//            lines[i] = playlistname + database::DELIMITER1 + tempsongs;
//            break;
//        }
//    }
//
//    if(!found) {
//        tempsongs = "";
//        for(unsigned int j = 0; j < playlist.size(); j++)
//            tempsongs += string(IntToStr(playlist[j]).c_str()) + database::DELIMITER1;
//
//        lines.push_back(playlistname + database::DELIMITER1 + tempsongs);
//    }
//
//    // skriv hela filen
//
//    ofstream dbfile(database::simpleplfilename, ios_base::out);
//    if(!dbfile.is_open())
//        throw EInOutError("ConcreteDatabaseEngine::updatePlaylist");
//
//    dbfile << "DATA01\n";
//
//    string templine;
//    for(unsigned int i = 0; i < lines.size(); i++) {
//        templine = lines[i];
//
//        if(templine != "") {
//            encodeData(&templine);
//            dbfile << templine << "\n";
//        }
//    }
//}


void ConcreteDatabaseEngine::encodeData(string *a_data) const
{
    for(unsigned int i = 0; i < a_data->length(); i++)
        (*a_data)[i] += (char)73;

//    replaceString(a_data, database::DELIMITER1, database::DELIMITER1replacement);
//    replaceString(a_data, database::DELIMITER2, database::DELIMITER2replacement);
}

void ConcreteDatabaseEngine::decodeData(string *a_data) const
{
//    int position;
//
//    position = a_data->find(database::DELIMITER1);
//    a_data->replace(position, database::DELIMITER1.length(), database::DELIMITER1replacement);
//
//    position = a_data->find(database::DELIMITER2);
//    a_data->replace(position, database::DELIMITER2.length(), database::DELIMITER2replacement);

    for(unsigned int i = 0; i < a_data->length(); i++)
        (*a_data)[i] -= (char)73;
}

//void ConcreteDatabaseEngine::replaceString(string *a_src, const string &a_oldstr, const string &a_newstr) const
//{
//    int length = a_oldstr.length();
//    string::size_type pos = 0;
//
//    while((pos = a_src->find(a_oldstr, pos)) != string::npos) {
//        a_src->replace(pos++, length, a_newstr);
//    }
//}

inline string ConcreteDatabaseEngine::getFirstPart(const string &a_str) const
{
    return a_str.substr(0, a_str.find(database::DELIMITER1));
}

vector<string> ConcreteDatabaseEngine::readFileData(const char a_filename[]) const
{
    vector<string> lines;
    char line[database::MAXLINELENGTH + 1];
    char version[7];
    string linestr;

    ifstream dbfile(a_filename, ios_base::in);
    if(!dbfile.is_open() && FileExists(AnsiString(a_filename)))
        throw EInOutError("ConcreteDatabaseEngine::readFileData");

    if(!dbfile.is_open())
        return lines;

    dbfile.getline(version, 7);

    if(strcmp(version, database::VERSION) != 0)
        throw BadFileFormatException("ConcreteDatabaseEngine::readFileData");

    while(dbfile.getline(line, database::MAXLINELENGTH)) {
        linestr = line;
        decodeData(&linestr);
        lines.push_back(linestr);
    }

    return lines;
}

string ConcreteDatabaseEngine::getSongData(const SongProperty &a_properties) const
{
    AnsiString songdata;

    songdata += a_properties.getPropertyRightValue(properties::INDEX) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::FILENAME) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::FILESIZE) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::FILEAGE) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::ALBUM) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::BAND) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::COMMENT) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::COMPOSER) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::CONDUCTOR) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::CONTENTTYPE) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::ENCODER) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::INTERPRETER) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::KEY) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::LANGUAGES) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::LEADARTIST) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::LYRICIST) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::LYRICS) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::MOOD) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::ORIGINALALBUM) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::ORIGINALARTISTS) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::ORIGINALLYRICIST) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::ORIGINALRELEASETIME) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::PARTOFSET) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::PUBLISHER) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::RECORDINGTIME) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::RELEASETIME) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::SITUATION) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::SUBTITLE) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::TEMPO) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::TITLE) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::TRACKNO) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::BITRATE) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::BPM) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::LENGTH) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::RATING) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::COVER) + database::DELIMITER1.c_str();
    songdata += a_properties.getPropertyRightValue(properties::REMIX) + database::DELIMITER1.c_str();

    return string(songdata.c_str());
}

