#include <iostream>
#include <stdlib>
#include <string>
#include <algorith>
#include <vector>

#include "TestCase.h"

TestCase::TestCase(const char *a_casename)
{
    std::cout << "\nTestar modul " << a_casename << "...\n";

    m_currentfunctionnumber = 1;
    m_currentassertnumber = 0;
    m_assertcount = 0;
}

TestCase::~TestCase()
{
    std::cout << m_assertcount << " tester genomfördes.\n";
}

void TestCase::assert(bool a_expression)
{
    m_currentassertnumber++;
    m_assertcount++;

    if (!a_expression) {
        std::cout << "Test nummer " << m_currentassertnumber
        << " i funktion nummer " << m_currentfunctionnumber << " misslyckades!\n";
        pause();
        exit(EXIT_FAILURE);
    }
}

void TestCase::nextFunction()
{
    m_currentfunctionnumber++;
    m_currentassertnumber = 0;
}

#pragma warn -8080
void TestCase::pause()
{
    char c;
    std::cin >> c;
}
#pragma warn .8080

bool TestCase::isInVector(AnsiString a_string, std::vector<AnsiString> a_vector)
{
    std::vector<AnsiString>::iterator position;
    position = std::find(a_vector.begin(), a_vector.end(), a_string);
    if(position == a_vector.end())
        return false;
    else
        return true;
}

bool TestCase::isInVector(int a_int, std::vector<int> a_vector)
{
    std::vector<int>::iterator position;
    position = std::find(a_vector.begin(), a_vector.end(), a_int);
    if(position == a_vector.end())
        return false;
    else
        return true;
}

