/*****************************************************************************
                               Reflection
Full Name  :  Ankita Chandel
Student ID#:  16173219
Section    :ZBB


Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/


#ifndef __SDDS_MOTORCYCLE_H__
#define __SDDS_MOTORCYCLE_H__

#include <iostream>
#include <string.h>
#include <iomanip>

#include "Vehicle.h"

namespace sdds
{
    class Motorcycle: public Vehicle
    {
        bool m_sidecar;
    public:
        Motorcycle();
        Motorcycle(const char *licensePlate, const char *makeModel);
        ~Motorcycle();
        // copy constructor
        Motorcycle(const Motorcycle &src);
        // copy assignment operator
        Motorcycle &operator=(const Motorcycle &src);
        // overriden methods
        std::istream &read(std::istream &istr = std::cin);
        std::ostream &write(std::ostream &ostr = std::cout) const;
        // writeType (pure virtual)
        // writeType receives and returns a reference of ostream.
        // This pure virtual method in future generations of Vehicle classes will print the type of Vehicle.
        std::ostream &writeType(std::ostream &ostr = std::cout) const;
    };
}

#endif