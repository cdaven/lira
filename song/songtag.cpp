#include "../Headers.h"
#pragma hdrstop

#include "SongTag.h"
#include "../Exceptions.h"

SongTag::SongTag()
{
    m_rating = -1;
    m_bitrate = -1;
    m_bpm = -1;
    m_length = -1;

    m_cover = false;
    m_remix = false;
}

void SongTag::setOriginalReleaseTime(const string &a)
{
    if(isStringOkDate(a))
        m_originalreleasetime = a;
}

void SongTag::setRecordingTime(const string &a)
{
    if(isStringOkDate(a))
        m_recordingtime = a;
}

void SongTag::setReleaseTime(const string &a)
{
    if(isStringOkDate(a))
        m_releasetime = a;
}

bool SongTag::isStringOkDate(const string &a_string) const
{
    switch(a_string.length()) {
        case 10: // åååå-mm-dd
            if(!a_string[7] == '-' || !isDay(a_string.substr(8)))
                break;

        case 7:  // åååå-mm
            if(!a_string[4] == '-' || !isMonth(a_string.substr(5)))
                break;

        case 4:  // åååå
            if(isYear(a_string))
                return true;

            break;

        case 0:  // null
            return true;

        default:
            return false;
    }

    return false;
}

bool SongTag::isNumber(const char &a_char) const
{
    if(a_char == '0' ||
       a_char == '1' ||
       a_char == '2' ||
       a_char == '3' ||
       a_char == '4' ||
       a_char == '5' ||
       a_char == '6' ||
       a_char == '7' ||
       a_char == '8' ||
       a_char == '9') return true;
    else
        return false;
}

// om strängen BÖRJAR med ett årtal 1xxx eller 2xxx
bool SongTag::isYear(const string &a_year) const
{
    if(a_year.length() < 4)
        return false;

    if(a_year[0] != '1' && a_year[0] != '2')
        return false;

    if(!isNumber(a_year[1]) || !isNumber(a_year[2]) || !isNumber(a_year[3]))
        return false;

    return true;
}

// om strängen BÖRJAR med en månad 01-12
bool SongTag::isMonth(const string &a_month) const
{
    if(a_month.length() < 2)
        return false;

    if(a_month[0] == '0')
        if(isNumber(a_month[1]) && a_month[1] != '0')
            return true;

    if(a_month[0] == '1')
        if(a_month[1] == '0' || a_month[1] == '1' || a_month[1] == '2')
            return true;

    return false;
}

// om strängen BÖRJAR med ett datum 01-31
bool SongTag::isDay(const string &a_day) const
{
    if(a_day.length() < 2)
        return false;

    if(a_day[0] == '0')
        if(isNumber(a_day[1]) && a_day[1] != '0')
            return true;

    if(a_day[0] == '1' || a_day[0] == '2')
        if(isNumber(a_day[1]))
            return true;

    if(a_day[0] == '3')
        if(a_day[1] == '0' || a_day[1] == '1')
            return true;

    return false;
}


