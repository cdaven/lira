#include "../Headers.h"
#pragma hdrstop

#include "FileManager.h"
#include "SongFacade.h"
#include "Song.h"
#include "SongProperty.h"
#include "../Exceptions.h"
#include "../Constants.h"

FileManager::FileManager(SongFacade *const a_pSongfacade)
    : m_pSongfacade(a_pSongfacade)
{
    if(a_pSongfacade == NULL)
        throw NullPointerException("FileManager::FileManager");
}

void FileManager::moveFile(const AnsiString &a_source, const AnsiString &a_destination) const
{
    renameFile(a_source, a_destination);
}

void FileManager::copyFile(const AnsiString &a_source, const AnsiString &a_destination) const
{
    if(FileExists(a_destination))
        throw FileAlreadyExists("FileManager::copyFile");

    if(!CopyFile((char *)a_source.c_str(), (char *)a_destination.c_str(), true))
        throw EInOutError("FileManager::copyFile");
}

void FileManager::removeFile(const AnsiString &a_filename) const
{
    if(FileIsReadOnly(a_filename))
        throw FileNotWritableException("FileManager::removeFile");

    if(!DeleteFile(a_filename) && FileExists(a_filename))
        throw FileNotDeletableException("FileManager::removeFile");
}

void FileManager::renameFile(const AnsiString &a_oldname, const AnsiString &a_newname) const
{
    if(FileExists(a_newname))
        throw FileAlreadyExists("FileManager::renameFile");

    if(!RenameFile(a_oldname, a_newname))
        throw EInOutError("FileManager::renameFile");
}

void FileManager::copyFolder(const AnsiString &a_src, const AnsiString &a_dest) const
{
}

void FileManager::moveFolder(const AnsiString &a_src, const AnsiString &a_dest) const
{
}

void FileManager::removeFolder(const AnsiString &a_folder) const
{
    if(!RemoveDir(a_folder)) // Måste vara tom
        throw EInOutError("FileManager::removeFolder");
}

void FileManager::updatePath(const AnsiString &a_path)
{
    filemap files;
    intvector songs, updatedsongs;
    File f;

    if(!DirectoryExists(a_path))
        throw FolderNotFoundException("FileManager::updatePath");

    SongProperty sp;
    sp.addProperty(properties::INDEX, "*");

    songs = m_pSongfacade->getSongsMatchingProperties(sp);

    sp.addProperty(properties::FILENAME);
    sp.addProperty(properties::FILESIZE);

    for(unsigned int i = 0; i < songs.size(); i++) {
        m_pSongfacade->getSongProperties(songs[i], &sp);

        f.name = string(sp.getPropertyRightValue(properties::FILENAME).c_str());
        f.size = StrToInt(sp.getPropertyRightValue(properties::FILESIZE));
        files[f.name] = f;
    }

    traverseAndCheckPath(string(a_path.c_str()), &files, &updatedsongs);

    if(!files.empty())
        removeSongsNotFound(files, &updatedsongs);

    m_pSongfacade->updateDatabase(updatedsongs);
}

File FileManager::getFileFromList(const string &a_file, filemap *a_list) const
{
    if(a_list->find(a_file) == a_list->end()) {
        File retval;
        retval.name = "";
        retval.size = 0;
        retval.time = 0;

        return retval;
    }

    return (*a_list)[a_file];
}

bool FileManager::compareFiles(const File &a_original, const File &a_new) const
{
//    if(stricmp(a_original.name.c_str(), a_new.name.c_str()) != 0)
//        return false;

    if(a_original.size != a_new.size)
        return false;

    return true;
}

void FileManager::traverseAndCheckPath(string a_path, filemap *const a_files, intvector *a_updatedsongs)
{
    TSearchRec sr;
    File filefound, filefromdatabase;
    string fname;
    int attributes = faAnyFile;
    int tempsong;

    // ** återställ efter tester ** Application->ProcessMessages(); // egentligen en GUI-metod...

    AnsiString musicmask(a_path.c_str());
    musicmask += "\\*.mp3";

    if(FindFirst(musicmask, attributes, sr) == 0) {
        do {
            if((sr.Attr & attributes) == sr.Attr) {
                fname = a_path + "\\" + string(sr.Name.c_str());

                filefound.name = fname;
                filefound.size = sr.Size;
                filefound.time = sr.Time;
                filefromdatabase = getFileFromList(fname, a_files);
                a_files->erase(fname);

                if(filefromdatabase.size != 0 && filefromdatabase.name != ""
                        && compareFiles(filefromdatabase, filefound))
                    continue;

                // En okänd eller känd, uppdaterad fil har hittats
                tempsong = m_pSongfacade->addSong(AnsiString(fname.c_str()));
                a_updatedsongs->push_back(tempsong);
            }
        } while(FindNext(sr) == 0);

        FindClose(sr);
    }

    attributes = faDirectory;

    AnsiString foldermask(a_path.c_str());
    foldermask += "\\*";

    if(FindFirst(foldermask, attributes, sr) == 0) {
        do {
            if((sr.Attr & attributes) > 0 && sr.Name != "." && sr.Name != "..") {
                fname = a_path + "\\" + string(sr.Name.c_str());
                traverseAndCheckPath(fname, a_files, a_updatedsongs);
            }
        } while(FindNext(sr) == 0);

        FindClose(sr);
    }
}

void FileManager::removeSongsNotFound(filemap a_songs, intvector *a_updatedsongs)
{
    intvector songindexes;
    SongProperty sp;
    sp.addProperty(properties::FILENAME);
    filemap::iterator iterator;

    for(iterator = a_songs.begin(); iterator != a_songs.end(); iterator++) {
        sp.setPropertyRightValue(properties::FILENAME, AnsiString(iterator->second.name.c_str()));
        songindexes = m_pSongfacade->getSongsMatchingProperties(sp);

        for(unsigned int j = 0; j < songindexes.size(); j++) {
            m_pSongfacade->removeSong(songindexes[j]);
            a_updatedsongs->push_back(songindexes[j]);
        }
    }
}

