#ifndef EXCEPTIONS_H_BLAHBLAH
#define EXCEPTIONS_H_BLAHBLAH

#include <vcl/sysutils.hpp> // Exception

// Skapa "snyggare" undantagshierarki med fler gemensamma basklasser

class FileNotFoundException : public EInOutError
{
public:
    FileNotFoundException(AnsiString);
};
inline FileNotFoundException::FileNotFoundException(AnsiString a_msg) : EInOutError(a_msg)
{
}

class FileNotWritableException : public EInOutError
{
public:
    FileNotWritableException(AnsiString);
};
inline FileNotWritableException::FileNotWritableException(AnsiString a_msg) : EInOutError(a_msg)
{
}

class FileNotDeletableException : public EInOutError
{
public:
    FileNotDeletableException(AnsiString);
};
inline FileNotDeletableException::FileNotDeletableException(AnsiString a_msg) : EInOutError(a_msg)
{
}

class FileAlreadyExists : public EInOutError
{
public:
    FileAlreadyExists(AnsiString);
};
inline FileAlreadyExists::FileAlreadyExists(AnsiString a_msg) : EInOutError(a_msg)
{
}


class PlayerNotAvailableException : public EAbort
{
public:
    PlayerNotAvailableException(AnsiString);
};
inline PlayerNotAvailableException::PlayerNotAvailableException(AnsiString a_msg) : EAbort(a_msg)
{
}

class TagNotFoundException : public EAbort
{
public:
    TagNotFoundException(AnsiString);
};
inline TagNotFoundException::TagNotFoundException(AnsiString a_msg) : EAbort(a_msg)
{
}


class InvalidPlayerTypeException : public Exception
{
public:
    InvalidPlayerTypeException(AnsiString);
};
inline InvalidPlayerTypeException::InvalidPlayerTypeException(AnsiString a_msg) : Exception(a_msg)
{
}

class InvalidTagTypeException : public Exception
{
public:
    InvalidTagTypeException(AnsiString);
};
inline InvalidTagTypeException::InvalidTagTypeException(AnsiString a_msg) : Exception(a_msg)
{
}


class AlreadyInContainerException : public EAbort
{
public:
    AlreadyInContainerException(AnsiString);
};
inline AlreadyInContainerException::AlreadyInContainerException(AnsiString a_msg) : EAbort(a_msg)
{
}

class NotInContainerException : public EAbort
{
public:
    NotInContainerException(AnsiString);
};
inline NotInContainerException::NotInContainerException(AnsiString a_msg) : EAbort(a_msg)
{
}

class NullPointerException : public Exception
{
public:
    NullPointerException(AnsiString);
};
inline NullPointerException::NullPointerException(AnsiString a_msg) : Exception(a_msg)
{
}


class BadInitialisationException : public Exception
{
public:
    BadInitialisationException(AnsiString);
};
inline BadInitialisationException::BadInitialisationException(AnsiString a_msg) : Exception(a_msg)
{
}


// bör ändras till mer beskrivande namn!
class UnknownException : public Exception
{
public:
    UnknownException(AnsiString);
};
inline UnknownException::UnknownException(AnsiString a_msg) : Exception(a_msg)
{
}

#endif
