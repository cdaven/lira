#include "../Headers.h"
#pragma hdrstop

#include "ID3GenreParser.h"

ID3GenreParser::ID3GenreParser()
{
    Genre tempgenre;
    m_genres.reserve(200);

    for(int i = 0; i < 80; i++) {
        tempgenre.name = ID3V1GENRES[i];
        tempgenre.type = GTYPE_ID3V1;
        tempgenre.number = i;
        m_genres.push_back(tempgenre);
    }
    for(int i = 80; i < 148; i++) {
        tempgenre.name = ID3V1GENRES[i];
        tempgenre.type = GTYPE_WA;
        tempgenre.number = i;
        m_genres.push_back(tempgenre);
    }

    // Mina egendefinierade genres:
    tempgenre.type = GTYPE_CD;

    tempgenre.number = 40; // Alternative Rock
    tempgenre.name = "College Rock";
    m_genres.push_back(tempgenre);

    tempgenre.number = 78; // Rock & Roll
    tempgenre.name = "Rockabilly";
    m_genres.push_back(tempgenre);

    tempgenre.number = 93; // Psychedelic Rock
    tempgenre.name = "Garage Rock";
    m_genres.push_back(tempgenre);

    tempgenre.number = 13; // Pop
    tempgenre.name = "Europop";
    m_genres.push_back(tempgenre);

    tempgenre.number = 17; // Rock
    tempgenre.name = "Soft Rock";
    m_genres.push_back(tempgenre);

    tempgenre.number = 0; // Blues
    tempgenre.name = "Chicago Blues";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Texas Blues";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Country Blues";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Blues-Rock";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Piano Blues";
    m_genres.push_back(tempgenre);

    tempgenre.number = 42; // Soul
    tempgenre.name = "Motown";
    m_genres.push_back(tempgenre);

    tempgenre.number = 14; // R&B
    tempgenre.name = "Doo Wop";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Urban";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Quiet Storm";
    m_genres.push_back(tempgenre);

    tempgenre.number = 16; // Reggae
    tempgenre.name = "Dub";
    m_genres.push_back(tempgenre);

    tempgenre.number = 8; // Jazz
    tempgenre.name = "Soul Jazz";
    m_genres.push_back(tempgenre);
    tempgenre.name = "New Orleans";
    m_genres.push_back(tempgenre);

    tempgenre.number = 2; // Country
    tempgenre.name = "Honky Tonk";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Country-Pop";
    m_genres.push_back(tempgenre);

    tempgenre.number = 52; // Electronic
    tempgenre.name = "Breakbeat";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Hardcore Techno";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Happy Hardcore";
    m_genres.push_back(tempgenre);

    tempgenre.number = 10; // New Age
    tempgenre.name = "Avslappning";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Neo-klassisk";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Natur";
    m_genres.push_back(tempgenre);

    tempgenre.number = 32; // Classical
    tempgenre.name = "Medeltida";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Barock";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Romantisk";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Renässans";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Impressionist";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Expressionist";
    m_genres.push_back(tempgenre);

    tempgenre.number = 28; // Vocal
    tempgenre.name = "Gregoriansk sång";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Vokalistgrupp"; // ******* var: Harmony Vocal Group 
    m_genres.push_back(tempgenre);
    tempgenre.name = "Barbershop";
    m_genres.push_back(tempgenre);

    tempgenre.number = 38; // Gospel
    tempgenre.name = "Black Gospel";
    m_genres.push_back(tempgenre);

    tempgenre.number = 140; // CCM
    tempgenre.name = "Lovsång";
    m_genres.push_back(tempgenre);

    tempgenre.number = 98; // Easy Listening
    tempgenre.name = "Hissmusik";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Orkestral";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Mood Music";
    m_genres.push_back(tempgenre);

    tempgenre.number = 24; // Soundtrack
    tempgenre.name = "Filmmusik";
    m_genres.push_back(tempgenre);
    tempgenre.name = "TV-musik";
    m_genres.push_back(tempgenre);

    tempgenre.number = 82; // Folk
    tempgenre.name = "Folkvisa";
    m_genres.push_back(tempgenre);

    tempgenre.number = 48; // Ethnic
    tempgenre.name = "Världsmusik";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Afrikansk";
    m_genres.push_back(tempgenre);

    tempgenre.number = 86; // Latin
    tempgenre.name = "Bossanova";
    m_genres.push_back(tempgenre);

    tempgenre.number = 90; // Avant-Garde
    tempgenre.name = "Ljudkonst";
    m_genres.push_back(tempgenre);
    tempgenre.name = "Improviserad musik";
    m_genres.push_back(tempgenre);
}

GenreRemixCover ID3GenreParser::parseFromTag(const string &a_genre) const
{
    int noparentheses = count(a_genre.begin(), a_genre.end(), '(');
    int beginpos = 0, endpos = 0;
    string *parentheses = new string[noparentheses];
    string genrestring = a_genre;

    for(int i = 0; i < noparentheses; i++) {
        beginpos = genrestring.find("(");
        endpos = genrestring.find(")", beginpos);

        parentheses[i] = genrestring.substr(beginpos + 1, endpos - beginpos - 1);
        genrestring.erase(beginpos, endpos + 1);
    }

    vector<string> genres;
    GenreRemixCover grc;
    grc.remix = false;
    grc.cover = false;
    string leftover = genrestring;
    int genrenumber;

    for(int i = 0; i < noparentheses; i++) {
        try {
            genrenumber = StrToInt(AnsiString(parentheses[i].c_str()));
        }
        catch(EConvertError &) {
            if(parentheses[i] == "RX")
                grc.remix = true;
            if(parentheses[i] == "CR")
                grc.cover = true;

            continue;
        }

        if(genrenumber >= 0 && genrenumber < 148)
            genres.push_back(ID3V1GENRES[genrenumber]);
    }

    string parentgenre = "", originalgenrename = "";
    genrestring = "";

    genrenumber = getGenreNumber(leftover);
    if(genrenumber != -1) {
        parentgenre = ID3V1GENRES[m_genres[genrenumber].number];
    }

    for(unsigned int i = 0; i < genres.size(); i++) {
        if(genrestring != "")
            genrestring += "|";

        if(stricmp(parentgenre.c_str(), genres[i].c_str()) == 0)
            continue;

        genrestring += genres[i];
    }

    convertFromOriginalGenreName(&leftover);
    if(leftover != "" && genrestring != "")
        genrestring += "|" + leftover;
    if(genrestring == "")
        genrestring = leftover;

    grc.genre = genrestring;

    delete[] parentheses;
    return grc;
}

void ID3GenreParser::convertFromOriginalGenreName(string *a_ogenre) const
{
    for(int i = 0; i < 148; i++)
        if(stricmp(a_ogenre->c_str(), ORIGINALID3GENRES[i].c_str()) == 0)
            *a_ogenre = ID3V1GENRES[i];
}

void ID3GenreParser::convertToOriginalGenreName(string *a_ogenre) const
{
    for(int i = 0; i < 148; i++)
        if(stricmp(a_ogenre->c_str(), ID3V1GENRES[i].c_str()) == 0)
            *a_ogenre = ORIGINALID3GENRES[i];
}

int ID3GenreParser::getMyGenreNumber(const string &a_genre) const
{
    for(unsigned int i = 0; i < m_genres.size(); i++)
        if(stricmp(a_genre.c_str(), m_genres[i].name.c_str()) == 0)
            // går bra eftersom jag inte har 2 miljarder genres
            return (signed int)i;

    return -1;
}

int ID3GenreParser::getOriginalGenreNumber(const string &a_genre) const
{
    for(int i = 0; i < 148; i++)
        if(stricmp(a_genre.c_str(), ORIGINALID3GENRES[i].c_str()) == 0)
            return i;

    return -1;
}

int ID3GenreParser::getGenreNumber(const string &a_genre) const
{
    int gno = getOriginalGenreNumber(a_genre);

    if(gno == -1)
        gno = getMyGenreNumber(a_genre);

    return gno;
}

string ID3GenreParser::parseToTag(const GenreRemixCover &a_grc) const
{
    int nostrings = count(a_grc.genre.begin(), a_grc.genre.end(), '|') + 1;
    int stringposition;
    string *genres = new string[nostrings];
    string genrestring = a_grc.genre;

    // kan göras med vector och kontroll av stringposition istället
    for(int i = 0; i < nostrings; i++) {
        stringposition = genrestring.find("|");
        genres[i] = genrestring.substr(0, stringposition);
        genrestring.erase(0, stringposition + 1);
    }

    vector<string> id3genres;
    vector<string> othergenres;
    int genrenumber;

    for(int i = 0; i < nostrings; i++) {
        genrenumber = getGenreNumber(genres[i]);
        if(genrenumber != -1) {
            id3genres.push_back("(" +
                    string(IntToStr(m_genres[genrenumber].number).c_str()) + ")");

            if(m_genres[genrenumber].type == GTYPE_CD)
                othergenres.push_back(genres[i]);
        }
        else
            othergenres.push_back(genres[i]);
    }

    genrestring = "";
    for(unsigned int i = 0; i < id3genres.size(); i++)
        genrestring += id3genres[i];

    if(a_grc.remix)
        genrestring += "(RX)";
    if(a_grc.cover)
        genrestring += "(CR)";

    for(unsigned int i = 0; i < othergenres.size(); i++) {
        genrestring += othergenres[i];
        if(i < othergenres.size() - 1)
            genrestring += "|";
    }

    delete[] genres;
    return genrestring;
}
