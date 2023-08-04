/*
Name:
Email:
Student ID:
Data:
Section:
*/
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include <cstring>
#include <iomanip>
#include "VehicleBasic.h"
namespace sdds
{
    class Dumper : public VehicleBasic
    {
        double m_capacity;
        double m_load;

    public:
        Dumper(const char plate[], int year, double capacity, const char address[]);
        bool loaddCargo(double cargo);
        bool unloadCargo();
        ostream &write(ostream &os);
        istream &read(istream &in);

        // helper functions
        // insertion operator
        friend ostream &operator<<(ostream &os, Dumper &d);
        // extraction operator
        friend istream &operator>>(istream &in, Dumper &d);
    };

}
#endif
