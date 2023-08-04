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