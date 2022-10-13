// Cube.cpp -- description of some Cube methods
#include "Cube.h"
#include <iostream>

namespace uiuc
{
    Cube::Cube(double lenght, HSLAPixel color)
    {
        m_lenght = lenght;
        m_color = color;
    }

    Cube::Cube(const Cube& obj)
    {
        m_lenght = obj.m_lenght;
        m_color = obj.m_color;
    }

    Cube::~Cube()
    {
        // Nothing ;)
    }

    Cube& Cube::operator=(const Cube& obj)
    {
        if (this == &obj)           // check if doing self-assignment
            return *this;
        m_lenght = obj.m_lenght;
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const Cube& cube)
    {
        os << "[" << cube.getLenght() << " ";
        switch (cube.m_color)
        {
        case uiuc::BLUE:
            os << "Blue]";
            break;
        case uiuc::PURPLE:
            os << "Purple]";
            break;
        case uiuc::YELLOW:
            os << "Yellow]";
            break;
        case uiuc::ORANGE:
            os << "Orange]";
            break;
        default:
            break;
        }
        return os;
    }
}