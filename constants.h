#ifndef CONSTANTS_H_BLAHBLAH
#define CONSTANTS_H_BLAHBLAH

#include <string>
#include <vector>
#include <vcl/classes.hpp>

typedef std::vector<int>            intvector;
typedef std::vector<std::string>    stringvector;
typedef std::vector<AnsiString>     ansistringvector;

namespace misc {
    const AnsiString EMPTYSTRING = "";
}

namespace player {
    const int PLAYING = 100;
    const int PAUSED = 200;
    const int STOPPED = 300;
}

namespace database {
    const char VERSION[] = "DATA01";
    const char FILENAME_SONGS[] = "data_songs";
//    const char   smartplfilename[] = "data_smartpl";
//    const char   simpleplfilename[] = "data_simplepl";

    const std::string DELIMITER1 = "¯";
    const std::string DELIMITER2 = "\r\n";
//    const string s_delimiter1replacement = "-tLd+";
//    const string s_delimiter2replacement = "-nWl+";

    const int MAXLINELENGTH = 10000;
}

namespace wmp {
    const int PLAY = 18808;
    const int PAUSE = 18808;
    const int STOP = 18809;
    const int NEXTTRACK = 18810;
    const int PREVIOUSTRACK = 18811;
}

namespace wa2 {
    const int PLAY = 40045;
    const int PAUSE = 40046;
    const int STOP = 40047;
    const int NEXTTRACK = 40048;
    const int PREVIOUSTRACK = 40044;
    const int RAISEVOLUME = 40058;
    const int LOWERVOLUME = 40059;
    const int CLOSE = 40001;

    const int GETVERSION = 0;
    const int ENQUEUEFILE = 100;
    const int CLEARPLAYLIST = 101;
    const int ISPLAYING = 104;
    const int GETOUTPUTTIME = 105;
    const int JUMPTOTIME = 106;
    const int GETLISTPOS = 125;
    const int GETPLAYLISTFILE = 211;
    const int UPDTITLE = 243;
}

namespace properties {
    const AnsiString INDEX =                "index";
    const AnsiString FILENAME =             "file name";
    const AnsiString FILESIZE =             "file size";
    const AnsiString FILEAGE =              "file age";
    const AnsiString ALBUM =                "album";
    const AnsiString BAND =                 "band";
    const AnsiString COMMENT =              "comment";
    const AnsiString COMPOSER =             "composer";
    const AnsiString CONDUCTOR =            "conductor";
    const AnsiString CONTENTTYPE =          "content type";
    const AnsiString ENCODER =              "encoder";
    const AnsiString INTERPRETER =          "interpreter";
    const AnsiString KEY =                  "key";
    const AnsiString LANGUAGES =            "languages";
    const AnsiString LEADARTIST =           "lead artist";
    const AnsiString LYRICIST =             "lyricist";
    const AnsiString LYRICS =               "lyrics";
    const AnsiString MOOD =                 "mood";
    const AnsiString ORIGINALALBUM =        "original album";
    const AnsiString ORIGINALARTISTS =      "original artists";
    const AnsiString ORIGINALLYRICIST =     "original lyricist";
    const AnsiString ORIGINALRELEASETIME =  "original release time";
    const AnsiString PARTOFSET =            "part of set";
    const AnsiString PUBLISHER =            "publisher";
    const AnsiString RECORDINGTIME =        "recording time";
    const AnsiString RELEASETIME =          "release time";
    const AnsiString SITUATION =            "situation";
    const AnsiString SUBTITLE =             "subtitle";
    const AnsiString TEMPO =                "tempo";
    const AnsiString TITLE =                "title";
    const AnsiString TRACKNO =              "track no";
    const AnsiString BITRATE =              "bitrate";
    const AnsiString BPM =                  "bpm";
    const AnsiString LENGTH =               "length";
    const AnsiString RATING =               "rating";
    const AnsiString COVER =                "cover";
    const AnsiString REMIX =                "remix";
}

#endif
