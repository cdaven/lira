#ifndef ID3GENREPARSER_H_HEADER_INCLUDED
#define ID3GENREPARSER_H_HEADER_INCLUDED

//#include <vector>
//#include <string>

using namespace std;

enum genretype {
    GTYPE_ID3V1,    // ingår i ID3v1-standarden
    GTYPE_WA,       // Winamps utökningar av ID3v1-standarden
    GTYPE_CD        // mina egna genres
};

struct Genre {
    string name;
    genretype type;
    int number;
};

struct GenreRemixCover {
    string genre;
    bool remix;
    bool cover;
};

typedef vector<Genre> genrevector;

class ID3GenreParser {
public:
    ID3GenreParser();

    GenreRemixCover parseFromTag    (const string &) const;
    string parseToTag               (const GenreRemixCover &) const;

private:
    void convertFromOriginalGenreName   (string *) const;
    void convertToOriginalGenreName     (string *) const;
    int getMyGenreNumber                (const string &) const;
    int getOriginalGenreNumber          (const string &) const;
    int getGenreNumber                  (const string &) const;

    genrevector m_genres;
};
const string ID3V1GENRES[148] = { "Blues", "Klassisk rock", "Country", "Dance",
    "Disco", "Funk", "Grunge", "Hip-hop", "Jazz", "Metal", "New Age", "Oldies", "Annat",
    "Pop", "R&B", "Rap", "Reggae", "Rock", "Techno", "Industrial", "Alternative", "Ska",
    "Death Metal", "Spratt", "Soundtrack", "Euro-Techno", "Ambient", "Trip-Hop", "Vokal",
    "Jazz-Funk", "Fusion", "Trance", "Klassiskt", "Instrumental", "Acid", "House", "Dataspel",
    "Ljudklipp", "Gospel", "Noise", "Alternative Rock", "Bass", "Soul", "Punk", "Space", "Meditativ",
    "Instrumental pop", "Instrumental rock", "Etnisk", "Gothic", "Darkwave", "Techno-Industrial",
    "Electronica", "Folk-Pop", "Eurodance", "Dream-Pop", "Southern Rock", "Komedi", "Kult", "Gangsta",
    "Topp 40", "Christian Rap", "Pop/Funk", "Jungle", "Amerikansk indian", "Kabaré", "New Wave",
    "Psykedelisk", "Rave", "Showtunes", "Trailer", "Lo-Fi", "Tribal", "Acid Punk", "Acid Jazz",
    "Polka", "Retro", "Musikal", "Rock & Roll", "Hårdrock", "Folkmusik", "Folk-Rock", "National Folk",
    "Swing", "Fast Fusion", "Bebop", "Latin", "Revival", "Keltisk", "Bluegrass", "Avant-garde",
    "Gothic Rock", "Progressiv rock", "Psykedelisk rock", "Symfonisk rock", "Slow Rock",
    "Storband", "Körsång", "Lättlyssnat", "Akustisk", "Humor", "Tal", "Chanson", "Opera",
    "Kammarmusic", "Sonat", "Symfoni", "Miami Bass", "Primus", "Porn Groove", "Satir",
    "Slow Jam", "Club", "Tango", "Samba", "Folklore", "Ballad", "Power Ballad", "Rhythmic Soul",
    "Freestyle", "Duett", "Punk Rock", "Trumsolo", "A cappella", "Euro-House", "Dance Hall", "Goa",
    "Drum & Bass", "Club-House", "Hardcore", "Terrorcore", "Indierock", "Brit-Pop", "N-punk",
    "Polsk punk", "Merseybeat", "Christian Gangsta Rap", "Heavy Metal", "Black Metal", "Crossover",
    "Contemporary Christian", "Christian Rock", "Merengue", "Salsa", "Thrash Metal", "Anime", "Japansk pop",
    "Synt-pop" };

const string ORIGINALID3GENRES[148] = { "Blues", "Classic Rock", "Country", "Dance", "Disco", "Funk",
    "Grunge", "Hip-Hop", "Jazz", "Metal", "New Age", "Oldies", "Other", "Pop", "R&B", "Rap", "Reggae",
    "Rock", "Techno", "Industrial", "Alternative", "Ska", "Death Metal", "Pranks", "Soundtrack",
    "Euro-Techno", "Ambient", "Trip-Hop", "Vocal", "Jazz+Funk", "Fusion", "Trance", "Classical",
    "Instrumental", "Acid", "House", "Game", "Sound Clip", "Gospel", "Noise", "Alt. Rock", "Bass", // AlternRock i ID3v1, men Alt. Rock i ID3v2 (i Winamp/Sonique)
    "Soul", "Punk", "Space", "Meditative", "Instrumental Pop", "Instrumental Rock", "Ethnic", "Gothic",
    "Darkwave", "Techno-Industrial", "Electronic", "Pop-Folk", "Eurodance", "Dream", "Southern Rock",
    "Comedy", "Cult", "Gangsta", "Top 40", "Christian Rap", "Pop/Funk", "Jungle", "Native American",
    "Cabaret", "New Wave", "Psychadelic", "Rave", "Showtunes", "Trailer", "Lo-Fi", "Tribal",
    "Acid Punk", "Acid Jazz", "Polka", "Retro", "Musical", "Rock & Roll", "Hard Rock", "Folk",
    "Folk-Rock", "National Folk", "Swing", "Fast Fusion", "Bebob", "Latin", "Revival", "Celtic",
    "Bluegrass", "Avantgarde", "Gothic Rock", "Progressive Rock", "Psychedelic Rock", "Symphonic Rock",
    "Slow Rock", "Big Band", "Chorus", "Easy Listening", "Acoustic", "Humour", "Speech", "Chanson",
    "Opera", "Chamber Music", "Sonata", "Symphony", "Booty Bass", "Primus", "Porn Groove", "Satire",
    "Slow Jam", "Club", "Tango", "Samba", "Folklore", "Ballad", "Power Ballad", "Rhythmic Soul",
    "Freestyle", "Duet", "Punk Rock", "Drum Solo", "A capella", "Euro-House", "Dance Hall", "Goa",
    "Drum & Bass", "Club-House", "Hardcore", "Terror", "Indie", "Britpop", "Negerpunk", "Polsk Punk",
    "Beat", "Christian Gangsta Rap", "Heavy Metal", "Black Metal", "Crossover", "Contemporary Christian",
    "Christian Rock", "Merengue", "Salsa", "Thrash Metal", "Anime", "JPop", "Synthpop" };

#endif
