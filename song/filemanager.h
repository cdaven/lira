#ifndef FILEMANAGER_H_HEADER_INCLUDED_C0C8F8C2
#define FILEMANAGER_H_HEADER_INCLUDED_C0C8F8C2

#include "../Constants.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

class FolderNotFoundException : public Exception
{
public:
    FolderNotFoundException(AnsiString);
};
inline FolderNotFoundException::FolderNotFoundException(AnsiString a_msg) : Exception(a_msg)
{
}


struct File
{
    string name;
    unsigned int size;
    unsigned int time;
};


typedef vector<File> filevector;
typedef map<string, File> filemap;

class SongFacade;


// Raderar, flyttar, kopierar och söker filer på hårddisk, cd-rom eller andra
// media.
class FileManager
{
public:
//    FileManager() {}
    FileManager(SongFacade *const);

    void moveFile(const AnsiString &, const AnsiString &) const;
    void copyFile(const AnsiString &, const AnsiString &) const;
    void removeFile(const AnsiString &) const;
    void renameFile(const AnsiString &, const AnsiString &) const;
    void updatePath(const AnsiString &);

    void copyFolder(const AnsiString &, const AnsiString &) const;
    void moveFolder(const AnsiString &, const AnsiString &) const;
    void removeFolder(const AnsiString &) const;

// private: -- återställ vid release
    File getFileFromList(const string &, filemap *) const;
    bool compareFiles(const File &, const File &) const;
    void traverseAndCheckPath(string, filemap *const, intvector *);
    void removeSongsNotFound(filemap, intvector *);
    
    SongFacade *const m_pSongfacade;
};

#endif /* FILEMANAGER_H_HEADER_INCLUDED_C0C8F8C2 */
