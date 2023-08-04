#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>
#include "LblShape.h"
#include "Utils.h"

namespace sdds{

char* sdds::LblShape::label() const
{
    return m_label;
}

LblShape::LblShape()
{
}

LblShape::LblShape(const char* incomingCstring)
{
    m_label = new char[ut.strlen(incomingCstring) + 1];
    ut.strcpy(m_label, incomingCstring);
}

LblShape::~LblShape()
{
    delete[]m_label;
}

void LblShape::getSpecs(std::istream& is) //??
{
    std::string str;
    std::getline(is, str, ',');
    //is.ignore(1000, ',');

    delete[] this->m_label;
    //this->m_label = nullptr;
    this->m_label = new char[ut.strlen(str.c_str()) +1];
    
    ut.strcpy(m_label,str.c_str());
    
}




}
