#include "../Headers.h"
#pragma hdrstop

#include "SongProperty.h"
#include "../Exceptions.h"

SongProperty::SongProperty()
{
    // SongTag innehåller ~35 attribut plus filstorlek etc
    m_properties.reserve(40);
}

int SongProperty::count() const
{
    return m_properties.size();
}

//bool SongProperty::isEmpty() const
//{
//    for(unsigned int i = 0; i < m_properties.size(); i++)
//        if(m_properties[i].second != "")
//            return false;
//
//    return true;
//}

// med "empty" menas att höger sida är tom, dvs. ingen data finns
// -- dock kan attribut finnas på vänster sida
bool SongProperty::isEmptyButForIndex() const
{
    for(unsigned int i = 0; i < m_properties.size(); i++)
        if(m_properties[i].second != "" && m_properties[i].first != "index")
            return false;

    return true;
}

void SongProperty::clear()
{
    m_properties.clear();
}

AnsiString SongProperty::getPropertyLeftValue(unsigned int a_propertyno) const
{
    if(a_propertyno >= m_properties.size())
        return "";

    return m_properties[a_propertyno].first;
}

AnsiString SongProperty::getPropertyRightValue(unsigned int a_propertyno) const
{
    if(a_propertyno >= m_properties.size())
        return "";

    return m_properties[a_propertyno].second;
}

AnsiString SongProperty::getPropertyRightValue(const AnsiString &a_property) const
{
    for(unsigned int i = 0; i < m_properties.size(); i++)
        if(m_properties[i].first == a_property)
            return m_properties[i].second;

    return "";
}

//void SongProperty::setPropertyLeftValue(unsigned int a_propertyno, const AnsiString &a_value)
//{
//    if(a_propertyno >= m_properties.size())
//        throw NotInContainerException("SongProperty::setPropertyLeftValue");
//
//    m_properties[a_propertyno].first = a_value;
//}

void SongProperty::setPropertyRightValue(const AnsiString &a_property, const AnsiString &a_value)
{
    for(unsigned int i = 0; i < m_properties.size(); i++)
        if(m_properties[i].first == a_property) {
            m_properties[i].second = a_value;
            return;
        }

    throw NotInContainerException("SongProperty::setPropertyRightValue");
}

// om attributet redan finns ska värdet uppdateras
void SongProperty::addProperty(const AnsiString &a_left, const AnsiString &a_right)
{
    for(unsigned int i = 0; i < m_properties.size(); i++)
        if(m_properties[i].first == a_left) {
            m_properties[i].second = a_right;
            return;
        }

    m_properties.push_back(std::make_pair(a_left, a_right));
}

