#ifndef TAGIMPEXFACTORY_H_HEADER_INCLUDED_C0DB185C
#define TAGIMPEXFACTORY_H_HEADER_INCLUDED_C0DB185C

#include <vcl/system.hpp>
class TagImpEx;

// Skapar och tillhandahåller TagImpEx-objekt. Håller i minne _ett_ objekt per
// klass som realiserar TagImpEx.
class TagImpExFactory
{
public:
    TagImpExFactory();
    ~TagImpExFactory();

    const TagImpEx *createTagImpEx(const AnsiString &);

private:
    TagImpExFactory(TagImpExFactory &) {} // dold kopieringskonstruerare

    TagImpEx *m_pId3tagimpex;
};

#endif /* TAGIMPEXMANAGER_H_HEADER_INCLUDED_C0DB185C */
