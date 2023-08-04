/*****************************************************************************
Full Name  :  Ankita Chandel
Student ID#:  16173219
Section    :ZBB
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/


#ifndef __SDDS_CAR_H__
#define __SDDS_CAR_H__

#include <iostream>
#include <string.h>
#include <iomanip>

#include "Vehicle.h"

namespace sdds
{
    class Car: public Vehicle
    {
        bool m_carWash;
    public:
        Car();
        Car(const char *licensePlate, const char *makeModel);
        ~Car();
        // copy constructor
        Car(const Car &src);
        // copy assignment operator
        Car &operator=(const Car &src);
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