#ifndef TEST_CASE_H_
#define TEST_CASE_H_

#include <string>
#include <vector>
#include <vcl/classes.hpp>

// endast ett interface

class TestCase
{
public:
    TestCase(const char *);
    ~TestCase();

protected:
    void assert(bool);
    void nextFunction();
    void pause();

    bool isInVector(AnsiString, std::vector<AnsiString>);
    bool isInVector(int, std::vector<int>);

    int m_currentfunctionnumber;
    int m_currentassertnumber;
    int m_assertcount;
};

class Dummy
{
};

#endif
