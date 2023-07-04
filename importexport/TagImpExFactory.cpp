#include "../Headers.h"
#pragma hdrstop

#include "TagImpExFactory.h"
#include "TagImpEx.h"
#include "ID3TagImpEx.h"
#include "../Exceptions.h"

TagImpExFactory::TagImpExFactory()
{
    m_pId3tagimpex = 0;
}

TagImpExFactory::~TagImpExFactory()
{
    if(m_pId3tagimpex)
        delete m_pId3tagimpex;
}

// ska fknen verkligen returnera just medlemsvariabeln?
// det bryter inkapslingsprincipen; b�ttre med en kopia, om �n l�ngsammare
// � andra sidan �r den const
const TagImpEx *TagImpExFactory::createTagImpEx(const AnsiString &a_tagtype)
{
    if(a_tagtype.UpperCase() == "ID3") {
        if(m_pId3tagimpex)
            return m_pId3tagimpex;
        else {
            m_pId3tagimpex = new ID3TagImpEx();
            return m_pId3tagimpex;
        }
    }

    throw InvalidTagTypeException("TagImpExFactory::createTagImpEx");
}



