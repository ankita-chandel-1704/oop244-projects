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


#ifndef __SDDS_VEHICLE_H__
#define __SDDS_VEHICLE_H__

#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>
#include "ReadWritable.h"

namespace sdds
{
    class Vehicle : public ReadWritable
    {
        char m_licensePlate[9];
        char *m_makeModel;
        int m_parkingSpotNumber;
    protected:
        void setEmpty();
        bool isEmpty() const;
        const char *getLicensePlate() const;
        const char *getMakeModel() const;
        void setMakeModel(const char *makeModel);
    public:
        Vehicle();
        Vehicle(const char *licensePlate, const char *makeModel);
        ~Vehicle();
        // copy constructor
        Vehicle(const Vehicle &src);
        // copy assignment operator
        Vehicle &operator=(const Vehicle &src);

        int getParkingSpot() const;
        void setParkingSpot(int parkingSpot);
        // operator==
        bool operator==(const char *licensePlate) const;
        bool operator==(const Vehicle &src) const;
        // overriden methods
        std::istream &read(std::istream &istr = std::cin);
        std::ostream &write(std::ostream &ostr = std::cout) const;
        // writeType (pure virtual)
        // writeType receives and returns a reference of ostream.
        // This pure virtual method in future generations of Vehicle classes will print the type of Vehicle.
        virtual std::ostream &writeType(std::ostream &ostr = std::cout) const = 0;
    };
}

#endif