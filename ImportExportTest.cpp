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
        PrintIfNotNull("sp�rnr", st->getTrackNo());
        PrintIfNotNull("inspelad", st->getRecordingTime());
        PrintIfNotNull("ursprungligen utgiven", st->getOriginalReleaseTime());
        PrintIfNotNull("komposit�r", st->getComposer());
        PrintIfNotNull("textf�rfattare", st->getLyricist());
        PrintIfNotNull("ursprunglig textf�rfattare", st->getOriginalLyricist());
        PrintIfNotNull("tolkare", st->getInterpreter());
        PrintIfNotNull("label", st->getPublisher());
        PrintIfNotNull("genre", st->getContentType());
        PrintIfNotNull("situation", st->getSituation());
        PrintIfNotNull("tempo", st->getTempo());
        PrintIfNotNull("hum�r", st->getMood());
        PrintIfNotNull("kodad av", st->getEncoder());
        PrintIfNotNull("kommentar", st->getComment());
        PrintIfNotNull("spr�k", st->getLanguages());
        PrintIfNotNull("tonart", st->getKey());
        PrintIfNotNull("s�ngtext", st->getLyrics());
        PrintIfNotNull("betyg", string(IntToStr(st->getRating()).c_str()));

        tie->exportTag(filename, *st);
    }
    catch(...) {
        cout << "ov�ntat undantag!\n";
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

