#ifndef CONCRETEIMPORTEXPORTFACADE_H_HEADER_BLAHBLAH
#define CONCRETEIMPORTEXPORTFACADE_H_HEADER_BLAHBLAH

#include "ImportExportFacade.h"

class ConcreteImportExportFacade : public ImportExportFacade
{
public:
    ConcreteImportExportFacade();
    virtual ~ConcreteImportExportFacade();

    virtual const TagImpEx *createTagImpEx(const AnsiString &) const;

private:
    TagImpExFactory *m_tagimpexfactory;
};

#endif
