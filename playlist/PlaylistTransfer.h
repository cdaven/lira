#ifndef PLAYLIST_TRANSFER_HEADER_
#define PLAYLIST_TRANSFER_HEADER_

#include "../Song/SongProperty.h"
#include "../Constants.h"

// För förflyttning av spellistor till och från
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

