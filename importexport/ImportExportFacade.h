#ifndef IMPORTEXPORTFACADE_H_HEADER_INCLUDED_C0DB0397
#define IMPORTEXPORTFACADE_H_HEADER_INCLUDED_C0DB0397

#include <vcl/system.hpp>

class TagImpEx;
class TagImpExFactory;

class ImportExportFacade
{
public:
    virtual ~ImportExportFacade() = 0;

    virtual const TagImpEx *createTagImpEx(const AnsiString &) const = 0;
};

ImportExportFacade::~ImportExportFacade()
{
}

#endif /* IMPORTEXPORTFACADE_H_HEADER_INCLUDED_C0DB0397 */
