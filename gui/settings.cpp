#include "../Headers.h"
#pragma hdrstop

#include "Settings.h"

void Settings::save() const
{
    TRegistry *registry = new TRegistry();
    registry->RootKey = HKEY_LOCAL_MACHINE;

    if(registry->OpenKey("\\SOFTWARE\\Lira!", true)) {
        try {
            registry->WriteString("Player Type", m_playertype);
            registry->WriteString("Player Path", m_playerpath);
            registry->WriteString("Main Folder Path", m_mainfolderpath);
        }
        catch(Exception &e) {
            throw CantSaveSettings(e.Message);
        }
    }

    delete registry;
}

void Settings::load()
{
    TRegistry *registry = new TRegistry();
    registry->RootKey = HKEY_LOCAL_MACHINE;

    if(registry->OpenKey("\\SOFTWARE\\Lira!", true)) {
        m_playertype = registry->ReadString("Player Type");
        m_playerpath = registry->ReadString("Player Path");
        m_mainfolderpath = registry->ReadString("Main Folder Path");
    }
    else {
        m_playertype = "";
        m_playerpath = "";
        m_mainfolderpath = "";
    }

    delete registry;
}

