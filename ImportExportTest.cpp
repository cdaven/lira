//---------------------------------------------------------------------------
#include <vcl.h>
#include <iostream.h>
#pragma hdrstop
#include "ConcreteImportExportFacade.h"
#include "TagImpEx.h"
#include "../Song/SongTag.h"
#include "../lib/extlib.h"
//---------------------------------------------------------------------------
void PrintIfNotNull(const string &a_description, const string &a_data)
{
    if(a_data == "")
        return;

    cout << a_description << ": "  << a_data << "\n";
}
#pragma argsused
int main(int argc, char* argv[])
{
    ImportExportFacade *cief = 0;
    SongTag *st = new SongTag();

    try {
        cief = new ConcreteImportExportFacade();
        const TagImpEx *tie = cief->createTagImpEx("ID3");

        AnsiString filename = "E:\\MP3\\Men in Black.mp3";

        try {
            tie->importTag(filename, st);
        }
        catch(EAbort &) { cout << "Eabort\n"; }

        PrintIfNotNull("artist", st->getLeadArtist());
        PrintIfNotNull("ursprunglig artist", st->getOriginalArtists());
        PrintIfNotNull("band", st->getBand());
        PrintIfNotNull("titel", st->getTitle());
        PrintIfNotNull("undertitel", st->getSubtitle());
        PrintIfNotNull("album", st->getAlbum());
        PrintIfNotNull("ursprungligt album", st->getOriginalAlbum());
        PrintIfNotNull("spårnr", st->getTrackNo());
        PrintIfNotNull("inspelad", st->getRecordingTime());
        PrintIfNotNull("ursprungligen utgiven", st->getOriginalReleaseTime());
        PrintIfNotNull("kompositör", st->getComposer());
        PrintIfNotNull("textförfattare", st->getLyricist());
        PrintIfNotNull("ursprunglig textförfattare", st->getOriginalLyricist());
        PrintIfNotNull("tolkare", st->getInterpreter());
        PrintIfNotNull("label", st->getPublisher());
        PrintIfNotNull("genre", st->getContentType());
        PrintIfNotNull("situation", st->getSituation());
        PrintIfNotNull("tempo", st->getTempo());
        PrintIfNotNull("humör", st->getMood());
        PrintIfNotNull("kodad av", st->getEncoder());
        PrintIfNotNull("kommentar", st->getComment());
        PrintIfNotNull("språk", st->getLanguages());
        PrintIfNotNull("tonart", st->getKey());
        PrintIfNotNull("sångtext", st->getLyrics());
        PrintIfNotNull("betyg", string(IntToStr(st->getRating()).c_str()));

        tie->exportTag(filename, *st);
    }
    catch(...) {
        cout << "oväntat undantag!\n";
    }

    if(cief)
        delete cief;
    if(st)
        delete st;

    cout << "\nklart.\n";
    Pause();
    return 0;
}
//---------------------------------------------------------------------------

