#ifndef EXTLIB_H_BLAHBLAH
#define EXTLIB_H_BLAHBLAH

#include <vcl/system.hpp>
#include <string>

AnsiString GetLastErrorMessage();
void Assert(bool, AnsiString = "");
void Pause();

#endif
