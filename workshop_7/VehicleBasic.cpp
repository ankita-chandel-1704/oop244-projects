#define _CRT_SECURE_NO_WARNINGS

#include "VehicleBasic.h"

namespace sdds
{
    VehicleBasic::VehicleBasic(const char plate[], int year)
    {
        strcpy(m_plate, plate);
        m_year = year;
        strcpy(m_address, "Factory");
    }

    void VehicleBasic::NewAddress(const char *address)
    {
        if (strcmp(m_address, address) != 0)
        {
            // |[LICENSE_PLATE]| |[CURRENT_ADDRESS] ---> [NEW_ADDRESS]|<ENDL>
            // the license plate is a field of 8 characters aligned to the right
            // current address is a field of 20 characters aligned to the right
            // new address is a field of 20 characters aligned to left
            cout << "|" << setw(8) << right << m_plate << "| |" << setw(20) << right << m_address << " ---> " << setw(20) << left << address << "|" << endl;
            strcpy(m_address, address);
        }
    }

    ostream &VehicleBasic::write(ostream &os)
    {
        // | [YEAR] | [PLATE] | [ADDRESS]
        os << "| " << m_year << " | " << m_plate << " | " << m_address;
        return os;
    }

    istream &VehicleBasic::read(istream &in)
    {
        // Built year: [USER TYPES HERE]
        // License plate: [USER TYPES HERE]
        // Current location: [USER TYPES HERE]

        int year;
        char plate[10];
        char address[65];

        cout << "Built year: ";
        in >> year;
        cout << "License plate: ";
        in >> plate;
        cout << "Current location: ";
        if (in.peek() == '\n')
        {
            in.ignore();
        }
        in.getline(address, 65, '\n');
        m_year = year;
        strcpy(m_plate, plate);
        strcpy(m_address, address);
        return in;
    }

    // insertion operator
    ostream &operator<<(ostream &os, VehicleBasic v)
    {
        return v.write(os);
    }

    // extraction operator
    istream &operator>>(istream &in, VehicleBasic &v)
    {
        return v.read(in);
    }
}
