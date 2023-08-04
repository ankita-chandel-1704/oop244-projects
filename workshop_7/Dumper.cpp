#define _CRT_SECURE_NO_WARNINGS
#include "Dumper.h"

namespace sdds
{
    Dumper::Dumper(const char plate[], int year, double capacity, const char address[]) : VehicleBasic(plate, year)
    {
        m_capacity = capacity;
        m_load = 0;
        NewAddress(address);
    }

    bool Dumper::loaddCargo(double cargo)
    {
        bool result = false;
        if (m_load + cargo <= m_capacity)
        {
            m_load += cargo;
            result = true;
        }
        return result;
    }

    bool Dumper::unloadCargo()
    {
        bool result = false;
        if (m_load > 0)
        {
            m_load = 0;
            result = true;
        }
        return result;
    }

    ostream &Dumper::write(ostream &os)
    {
        VehicleBasic::write(os);
        os << " | " << m_load << "/" << m_capacity;
        return os;
    }

    istream &Dumper::read(istream &in)
    {
        VehicleBasic::read(in);
        cout << "Capacity: ";
        in >> m_capacity;
        cout << "Cargo: ";
        in >> m_load;
        return in;
    }

    // helper functions
    // insertion operator
    ostream &operator<<(ostream &os, Dumper &d)
    {
        return d.write(os);
    }
    // extraction operator
    istream &operator>>(istream &in, Dumper &d)
    {
        return d.read(in);
    }

}
