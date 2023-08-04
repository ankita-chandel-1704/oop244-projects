#include "Car.h"

using namespace std;

namespace sdds
{
    Car::Car()
    {
        m_carWash = false;
    }

    Car::Car(const char *licensePlate, const char *makeModel) : Vehicle(licensePlate, makeModel)
    {
        m_carWash = false;
    }

    Car::~Car()
    {
    }

    Car::Car(const Car &src) : Vehicle(src)
    {
        m_carWash = src.m_carWash;
    }

    Car &Car::operator=(const Car &src)
    {
        if (this != &src)
        {
            Vehicle::operator=(src);
            m_carWash = src.m_carWash;
        }
        return *this;
    }

    istream &Car::read(istream &istr)
    {
        if (isCsv())
        {
            Vehicle::read(istr);
            istr >> m_carWash;
            istr.ignore(1000, '\n');
        }
        else
        {
            cout << endl
                 << "Car information entry" << endl;
            Vehicle::read(istr);
            cout << "Carwash while parked? (Y)es/(N)o: ";
            string answer;
            getline(istr, answer);
            while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
            {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                getline(istr, answer);
            }
            if(answer == "Y" || answer == "y")
                m_carWash = true;
            else
                m_carWash = false;
            // istr.ignore(1000, '\n');
        }
        return istr;
    }

    ostream &Car::write(ostream &ostr) const
    {
        if (isEmpty())
        {
            ostr << "Invalid Car Object" << endl;
        }
        else
        {
            if (isCsv())
            {
                Vehicle::write(ostr);
                ostr << m_carWash << endl;
            }
            else
            {
                Vehicle::write(ostr);
                if (m_carWash)
                {
                    ostr << "With Carwash" << endl;
                }
                else
                {
                    ostr<<"Without Carwash"<<endl;
                }
            }
        }
        return ostr;
    }

    ostream &Car::writeType(ostream &ostr) const
    {
        // Override the pure virtual method writeType to write "C," if the object is in comma-separated values format (isCsv()), or otherwise write Vehicle type: Car" and a NEWLINE.
        if (isCsv())
        {
            ostr << "C,";
        }
        else
        {
            ostr << "Vehicle type: Car" << endl;
        }
        return ostr;
    }
}
