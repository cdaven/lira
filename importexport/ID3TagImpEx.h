#ifndef ID3TAGIMPEX_H_HEADER_INCLUDED_C0DB7E56
#define ID3TAGIMPEX_H_HEADER_INCLUDED_C0DB7E56

#ifndef ID3LIB_LINKOPTION
#define ID3LIB_LINKOPTION 1
#endif

#include <string>
#include <map>

#include <vcl/sysutils.hpp>

#include <id3.h>
#include "TagImpEx.h"
#include "ID3GenreParser.h"

class FrameDuplicateException : public Exception
{
public:
    FrameDuplicateException(AnsiString);
};

inline FrameDuplicateException::FrameDuplicateException(AnsiString a_msg) : Exception(a_msg) {}



class SongTag;

using namespace std;

typedef map<string, string> stringmap;
typedef map<int, string> intstringmap;

class ID3TagImpEx : public TagImpEx
{
public:
    ID3TagImpEx();
    ~ID3TagImpEx();

    virtual void exportTag      (const AnsiString &, const SongTag &) const;
    virtual void importTag      (const AnsiString &, SongTag *) const;

private:
    void parseFrame             (ID3Frame *, SongTag *const) const;
    void createNewTag           (ID3Tag *const, const SongTag &) const;

    string getLanguageFromCode  (const string &) const;
    string getCodeFromLanguage  (const string &) const;

    string getTempoFromMusicMatch       (const string &) const;
    string getMoodFromMusicMatch        (const string &) const;
    string getSituationFromMusicMatch   (const string &) const;
    int getRatingFromMusicMatch         (const string &) const;

    void updateOrAdd        (ID3Tag *const, const ID3_FrameID &, const string &) const;
    void updateOrAddUserText(ID3Tag *const, const string &, const string &) const;

    void setString          (ID3Frame *, const string &) const;
    void setDescription     (ID3Frame *, const string &) const;
    string getString        (ID3Frame *) const;
    string getDescription   (ID3Frame *) const;

    ID3Frame *findFrameWithDescription(ID3Tag *const, const ID3_FrameID &, const string &) const;

    stringmap m_languagecodes;
    ID3GenreParser m_genreparser;
};

#endif /* ID3TAGIMPEX_H_HEADER_INCLUDED_C0DB7E56 */
