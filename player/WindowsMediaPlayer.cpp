#include "../Headers.h"
#pragma hdrstop

#include "WindowsMediaPlayer.h"
#include "../Constants.h"
#include "../Exceptions.h"

WindowsMediaPlayer::WindowsMediaPlayer(const AnsiString &a_path)
{
    m_playerclass = "WMPlayerApp";
    m_playerpath = a_path;
}

void WindowsMediaPlayer::play(const AnsiString &a_songfilename) const
{
    startPlayerExecutable("\"" + a_songfilename + "\"");
}

void WindowsMediaPlayer::play() const
{
    HWND wmpwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(wmpwindow == NULL)
        throw PlayerNotAvailableException("WindowsMediaPlayer::play");

    ::SendMessage(wmpwindow, WM_COMMAND, (WPARAM) wmp::PLAY, 0);
}

void WindowsMediaPlayer::playMultiple(const std::vector<std::string> a_songs) const
{
    if(a_songs.size() == 0)
        return;

    AnsiString songlist = "";

    for(unsigned int i = 0; i < a_songs.size(); i++)
        songlist += "\"" + AnsiString(a_songs[i].c_str()) + "\" ";

    startPlayerExecutable(songlist);
}

void WindowsMediaPlayer::enqueue(const AnsiString &a_songfilename) const
{
    play(a_songfilename); // Kan inte lägga en låt i kö...
}

void WindowsMediaPlayer::pause() const
{
    HWND wmpwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(wmpwindow == NULL)
        throw PlayerNotAvailableException("WindowsMediaPlayer::pause");

    ::SendMessage(wmpwindow, WM_COMMAND, (WPARAM) wmp::PAUSE, 0);
}

void WindowsMediaPlayer::stop() const
{
    HWND wmpwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(wmpwindow == NULL)
        throw PlayerNotAvailableException("WindowsMediaPlayer::stop");

    ::SendMessage(wmpwindow, WM_COMMAND, (WPARAM) wmp::STOP, 0);
}

void WindowsMediaPlayer::nextTrack() const
{
    HWND wmpwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(wmpwindow == NULL)
        throw PlayerNotAvailableException("WindowsMediaPlayer::nextTrack");

    ::SendMessage(wmpwindow, WM_COMMAND, (WPARAM) wmp::NEXTTRACK, 0);
}

void WindowsMediaPlayer::previousTrack() const
{
    HWND wmpwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(wmpwindow == NULL)
        throw PlayerNotAvailableException("WindowsMediaPlayer::previousTrack");

    ::SendMessage(wmpwindow, WM_COMMAND, (WPARAM) wmp::PREVIOUSTRACK, 0);
}

int WindowsMediaPlayer::getStatus() const
{
    // Kan inte avgöra om den spelar eller ej

    return player::PLAYING;
}

AnsiString WindowsMediaPlayer::getPlayedFile() const
{
    return "";
}

void WindowsMediaPlayer::saveAndStop()
{
}

void WindowsMediaPlayer::resumePlay()
{
}

void WindowsMediaPlayer::close() const
{
    HWND wmpwindow = ::FindWindow(m_playerclass.c_str(), NULL);

    if(wmpwindow == NULL)
        // Om WMP är stängt behöver vi inte stänga det igen
        return;

    ::SendMessage(wmpwindow, WM_CLOSE, 0, 0);
}

void WindowsMediaPlayer::startPlayerExecutable(const AnsiString &a_songlist) const
{
    AnsiString commandline = "\"" + m_playerpath + "\" /Play " + a_songlist;

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));

    si.wShowWindow = SW_SHOWMINNOACTIVE;
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.cb = sizeof(si);

    if(!CreateProcess(NULL, (char *)commandline.c_str(), NULL, NULL, false, 0, NULL, NULL, &si, &pi))
    {
        throw UnknownException("WindowsMediaPlayer::startPlayerExecutable");
    }
}

