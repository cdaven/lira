#ifndef SETTINGS_HEADER_
#define SETTINGS_HEADER_

#include <vcl/system.hpp>
#include <vcl/sysutils.hpp>

class CantSaveSettings : public Exception
{
public:
    CantSaveSettings(AnsiString);
};
inline CantSaveSettings::CantSaveSettings(AnsiString a_msg) : Exception(a_msg) {}


class Settings {
public:
    void save() const;
    void load();

    void setPlayerType(const AnsiString &a)     { m_playertype = a; }
    void setPlayerPath(const AnsiString &a)     { m_playerpath = a; }
    void setMainFolderPath(const AnsiString &a) { m_mainfolderpath = a; }

    AnsiString getPlayerType() const        { return m_playertype; }
    AnsiString getPlayerPath() const        { return m_playerpath; }
    AnsiString getMainFolderPath() const    { return m_mainfolderpath; }

private:
    AnsiString m_playertype;
    AnsiString m_playerpath;
    AnsiString m_mainfolderpath;
};

#endif
