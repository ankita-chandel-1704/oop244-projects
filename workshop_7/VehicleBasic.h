#ifndef __SDDS_VEHICLEBASIC_H__
#define __SDDS_VEHICLEBASIC_H__

#include <iostream>
#include <cstring>
#include <string.h>
#include <iomanip>

using namespace std;
namespace sdds
{
    class VehicleBasic
    {
        char m_plate[10];
        char m_address[65];
        int m_year;

    public:
        VehicleBasic(const char plate[], int year);
        void NewAddress(const char *address);
        ostream &write(ostream &os);
        istream &read(istream &in);

        // helper functions
        // insertion operator
        friend ostream &operator<<(ostream &os, VehicleBasic v);
        // extraction operator
        friend istream &operator>>(istream &in, VehicleBasic &v);
    };
}

#endif