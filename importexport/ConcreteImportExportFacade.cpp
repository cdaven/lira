#include "../Headers.h"
#pragma hdrstop

#include "ConcreteImportExportFacade.h"
#include "TagImpExFactory.h"

ConcreteImportExportFacade::ConcreteImportExportFacade()
{
    m_tagimpexfactory = new TagImpExFactory();
}

ConcreteImportExportFacade::~ConcreteImportExportFacade()
{
    if(m_tagimpexfactory)
        delete m_tagimpexfactory;
}

const TagImpEx *ConcreteImportExportFacade::createTagImpEx(const AnsiString &a_tagtype) const
{
    return m_tagimpexfactory->createTagImpEx(a_tagtype);
}

