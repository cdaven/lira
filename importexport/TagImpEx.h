#ifndef TAGIMPEX_H_HEADER_INCLUDED_C0DB48BB
#define TAGIMPEX_H_HEADER_INCLUDED_C0DB48BB

#include <vcl/system.hpp>

class SongTag;

class TagImpEx
{
public:
    virtual ~TagImpEx();

    virtual void exportTag(const AnsiString &, const SongTag &) const = 0;
    virtual void importTag(const AnsiString &, SongTag *) const = 0;
};

TagImpEx::~TagImpEx()
{
}

#endif /* TAGIMPEX_H_HEADER_INCLUDED_C0DB48BB */
