#include "Motorcycle.h"

using namespace std;

namespace sdds
{
    Motorcycle::Motorcycle()
    {
        m_sidecar = false;
    }

    Motorcycle::Motorcycle(const char *licensePlate, const char *makeModel) : Vehicle(licensePlate, makeModel)
    {
        m_sidecar = false;
    }

    Motorcycle::~Motorcycle()
    {
    }

    Motorcycle::Motorcycle(const Motorcycle &src) : Vehicle(src)
    {
        m_sidecar = src.m_sidecar;
    }

    Motorcycle &Motorcycle::operator=(const Motorcycle &src)
    {
        if (this != &src)
        {
            Vehicle::operator=(src);
            m_sidecar = src.m_sidecar;
        }
        return *this;
    }

    istream &Motorcycle::read(istream &istr)
    {
        if (isCsv())
        {
            Vehicle::read(istr);
            istr >> m_sidecar;
            istr.ignore(1000, '\n');
        }
        else
        {
            cout << endl
                 << "Motorcycle information entry" << endl;
            Vehicle::read(istr);
            cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
            string answer;
            getline(istr, answer);
            while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
            {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                getline(istr, answer);
            }
            if(answer == "Y" || answer == "y")
                m_sidecar = true;
            else
                m_sidecar = false;
        }
        return istr;
    }

    ostream &Motorcycle::write(ostream &ostr) const
    {
        if (isEmpty())
        {
            ostr << "Invalid Motorcycle Object" << endl;
        }
        else
        {
            
            Vehicle::write(ostr);
            if (isCsv())
            {
                ostr << m_sidecar << endl;
            }
            else
            {
                if (m_sidecar)
                {    
                    ostr << "With Sidecar" << endl;
                }
            }
        }
        return ostr;
    }

    ostream &Motorcycle::writeType(ostream &ostr) const
    {
        // Override the pure virtual method writeType to write "M," if the object is in comma-separated values format (isCsv()), or otherwise write "Vehicle type: Motorcycle" and a NEWLINE.
        if (isCsv())
        {
            ostr << "M,";
        }
        else
        {
            ostr << "Vehicle type: Motorcycle" << endl;
        }
        return ostr;
    }
}
