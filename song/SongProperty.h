#ifndef SONGPROPERTY_H_HEADER_INCLUDED_C0E0300F
#define SONGPROPERTY_H_HEADER_INCLUDED_C0E0300F

#include "../Constants.h"

// Är en "kapsel" med data som skickas mellan paketen

class SongProperty
{
public:
    SongProperty();

    int count() const;
//    bool isEmpty() const;
    bool isEmptyButForIndex() const;
    void clear();

    AnsiString getPropertyLeftValue(unsigned int) const;
    AnsiString getPropertyRightValue(unsigned int) const;
    AnsiString getPropertyRightValue(const AnsiString &) const;
//    void setPropertyLeftValue(unsigned int, const AnsiString &);
    void setPropertyRightValue(const AnsiString &, const AnsiString &);

    void addProperty(const AnsiString &, const AnsiString & = misc::EMPTYSTRING);

private:
//    map<AnsiString, AnsiString> m_properties;
    std::vector< std::pair<AnsiString, AnsiString> > m_properties;
};

#endif /* SONGPROPERTY_H_HEADER_INCLUDED_C0E0300F */
