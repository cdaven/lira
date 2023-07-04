#ifndef PLAYLIST_TRANSFER_HEADER_
#define PLAYLIST_TRANSFER_HEADER_

#include "../Song/SongProperty.h"
#include "../Constants.h"

// F�r f�rflyttning av spellistor till och fr�n
// databasmotorn/spellistefasaden

struct SmartPlaylistTransfer {
    std::string name;
    SongProperty properties;
};

struct SimplePlaylistTransfer {
    std::string name;
    intvector songs;
};

#endif

