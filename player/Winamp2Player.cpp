/*----------------------------------------------------------------------
  Winamp2Player

  Uppgift:  Kontrollerar extern spelare Winamp 2.x

  Copyright 2003 Christian Davén
----------------------------------------------------------------------*/
#include "../Headers.h"
#pragma hdrstop

#include "Winamp2Player.h"
#include "../Constants.h"
#include "../Exceptions.h"

Winamp2Player::Winamp2Player(const AnsiString &a_path)
{
    m_playerclass = "Winamp v1.x";
    m_playerpath = a_path;
    m_savedposition = 0;
}

/*----------------------------------------------------------------------
  Funktion:  play(AnsiString)
  Datum:     23 jul 2003

  Uppgift:   Spelar upp låt med filnamn a_filename, startar Winamp om nödvändigt
  Undantag:
----------------------------------------------------------------------*/
void Winamp2Player::play(const AnsiString &a_songfilename) const
{
    HWND winampwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(winampwindow == NULL) {
        startPlayerExecutable(a_songfilename);
        return;
    }

    ::SendMessage(winampwindow, WM_USER, 0, (LPARAM) wa2::CLEARPLAYLIST);

    enqueue(a_songfilename);
    play();
}

void Winamp2Player::play() const
{
    HWND winampwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(winampwindow == NULL)
        throw PlayerNotAvailableException("Winamp2Player::play");

    ::SendMessage(winampwindow, WM_COMMAND, (WPARAM) wa2::PLAY, 0);
}

void Winamp2Player::playMultiple(const std::vector<std::string> a_songs) const
{
    if(a_songs.size() == 0)
        return;

    play(AnsiString(a_songs[0].c_str()));

    for(unsigned int i = 1; i < a_songs.size(); i++)
        enqueue(AnsiString(a_songs[i].c_str()));
}

void Winamp2Player::enqueue(const AnsiString &a_songfilename) const
{
    HWND winampwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(winampwindow == NULL) {
        startPlayerExecutable(a_songfilename);
        return;
    }

    int len = a_songfilename.Length() + 1;
    char *pFn = new char[len];

    memcpy(pFn, a_songfilename.c_str(), len); // En byte för mycket?

    COPYDATASTRUCT cds;
    cds.dwData = wa2::ENQUEUEFILE;
    cds.cbData = len;
    cds.lpData = pFn;

    ::SendMessage(winampwindow, WM_COPYDATA, 0, (LPARAM) &cds);

    delete[] pFn;
}

void Winamp2Player::pause() const
{
    HWND winampwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(winampwindow == NULL)
        throw PlayerNotAvailableException("Winamp2Player::pause");

    ::SendMessage(winampwindow, WM_COMMAND, (WPARAM) wa2::PAUSE, 0);
}

void Winamp2Player::stop() const
{
    HWND winampwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(winampwindow == NULL)
        throw PlayerNotAvailableException("Winamp2Player::stop");

    ::SendMessage(winampwindow, WM_COMMAND, (WPARAM) wa2::STOP, 0);
}

void Winamp2Player::nextTrack() const
{
    HWND winampwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(winampwindow == NULL)
        throw PlayerNotAvailableException("Winamp2Player::nextTrack");

    ::SendMessage(winampwindow, WM_COMMAND, (WPARAM) wa2::NEXTTRACK, 0);
}

void Winamp2Player::previousTrack() const
{
    HWND winampwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(winampwindow == NULL)
        throw PlayerNotAvailableException("Winamp2Player::previousTrack");

    ::SendMessage(winampwindow, WM_COMMAND, (WPARAM) wa2::PREVIOUSTRACK, 0);
}

int Winamp2Player::getStatus() const
{
    HWND winampwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(winampwindow == NULL)
        return player::STOPPED;

    int status = ::SendMessage(winampwindow, WM_USER, 0, (LPARAM) wa2::ISPLAYING);

    switch(status) {
        case 1:
            return player::PLAYING;
        case 3:
            return player::PAUSED;
        default:
            return player::STOPPED;
    }
}

AnsiString Winamp2Player::getPlayedFile() const
{
    if(getStatus() == player::STOPPED)
        return "";

    HWND winampwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(winampwindow == NULL)
        throw PlayerNotAvailableException("Winamp2Player::getPlayedFile");

    int track;
    unsigned long address, processid;
    HANDLE process;

    char *pFilename = new char[MAX_PATH + 1];

    track = ::SendMessage(winampwindow, WM_USER, 0, (LPARAM) wa2::GETLISTPOS);
    address = ::SendMessage(winampwindow, WM_USER, (WPARAM) track, (LPARAM) wa2::GETPLAYLISTFILE);

    GetWindowThreadProcessId(winampwindow, &processid);
    process = OpenProcess(PROCESS_VM_READ, false, processid);

    if(process == NULL) {
        AnsiString msg = getLastErrorMessage();
        delete[] pFilename;
        throw UnknownException(msg);
    }

    if(!ReadProcessMemory(process, (void *)address, (void *)pFilename, MAX_PATH, 0)) {
        AnsiString msg = getLastErrorMessage();
        delete[] pFilename;
        throw UnknownException(msg);
    }

    if(!CloseHandle(process)) {
        AnsiString msg = getLastErrorMessage();
        delete[] pFilename;
        throw UnknownException(msg);
    }

    AnsiString file = AnsiString(pFilename);
    delete[] pFilename;

    return file;
}

/*----------------------------------------------------------------------
  Funktion:  saveAndStop
  Datum:     22 jul 2003

  Uppgift:   Stannar spelaren och kommer ihåg positionen (ex. för att skriva till fil)
  Undantag:
----------------------------------------------------------------------*/
void Winamp2Player::saveAndStop()
{
    HWND winampwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(winampwindow == NULL) {
        // Om inte Winamp är igång behöver vi inte bry oss om
        // att stanna den...
        m_savedposition = 0;
        return;
    }

    if(getStatus() != player::STOPPED) {
        m_savedposition = ::SendMessage(winampwindow, WM_USER, 0, (LPARAM) wa2::GETOUTPUTTIME);
        stop();
    }
    else m_savedposition = 0;
}

void Winamp2Player::resumePlay()
{
    HWND winampwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(winampwindow == NULL)
        return;

    if(m_savedposition != 0) {
        play();
        ::SendMessage(winampwindow, WM_USER, (WPARAM) m_savedposition, (LPARAM) wa2::JUMPTOTIME);
        m_savedposition = 0;
    }
}

void Winamp2Player::close() const
{
    HWND winampwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(winampwindow == NULL)
        // Om Winamp är stängt behöver vi inte stänga det igen
        return;

    ::SendMessage(winampwindow, WM_COMMAND, (WPARAM) wa2::CLOSE, 0);
}

void Winamp2Player::startPlayerExecutable(const AnsiString &a_songfilename) const
{
    AnsiString commandline = "\"" + m_playerpath + "\" \"" + a_songfilename + "\"";

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));

    si.wShowWindow = SW_SHOWMINNOACTIVE;
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.cb = sizeof(si);

    if(!CreateProcess(NULL, (char *)commandline.c_str(), NULL, NULL, false, 0, NULL, NULL, &si, &pi))
    {
        throw UnknownException("Winamp2Player::startPlayerExecutable");
    }
}

/*----------------------------------------------------------------------
  Funktion:  GetLastErrorMessage
  Datum:     23 jul 2003

  Uppgift:   Returnerar en sträng som beskriver felet som ges av GetLastError
  Undantag:  --
----------------------------------------------------------------------*/
AnsiString Winamp2Player::getLastErrorMessage() const
{
    void *pMessage;
    int success;
    AnsiString msg = "";

    success = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
            NULL, GetLastError(), 0, (char *)&pMessage, 0, NULL);

    if(success) {
        msg = AnsiString((char *)pMessage);
        LocalFree(pMessage);
    }

    return msg;
}

