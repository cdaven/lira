#ifndef SONG_H_HEADER_INCLUDED_C0C8AF45
#define SONG_H_HEADER_INCLUDED_C0C8AF45

#include <vcl/system.hpp>
#include "../ImportExport/TagImpEx.h"
#include "SongTag.h"
#include "SongProperty.h"

// Motsvarar en fil på hårddisk, cd-skiva etc.
class Song
{
public:
    Song();
    Song(const AnsiString &, const TagImpEx *);
    Song(const SongProperty &, const TagImpEx *);
    ~Song();

    int getIndex() const { return m_index; }

    AnsiString getProperty(const AnsiString &) const;
    void setProperty(const AnsiString &, const AnsiString &);

    AnsiString getFilename() const;
    void setFilename(const AnsiString &a_filename) { m_filename = a_filename; }

    void importTag();
    void exportTag() const;

private:
    int stringToInt(AnsiString) const;

    SongTag m_tag;
    const TagImpEx *m_pTagimportexport;

    AnsiString m_filename;
    int m_index;
    unsigned int m_filesize;
    int m_fileage;
};

#endif /* SONG_H_HEADER_INCLUDED_C0C8AF45 */
