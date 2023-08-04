#define _CRT_SECURE_NO_WARNINGS
#include "Vehicle.h"

using namespace std;

namespace sdds
{
    Vehicle::Vehicle()
    {
        m_makeModel = nullptr;
        setEmpty();
    }

    Vehicle::Vehicle(const char *licensePlate, const char *makeModel)
    {
        m_makeModel = nullptr;
        setEmpty();
        if (licensePlate != nullptr && licensePlate[0] != '\0' && makeModel != nullptr && makeModel[0] != '\0' && strlen(licensePlate) <= 8 && strlen(makeModel) >= 2 && strlen(makeModel) <= 60)
        {
            strncpy(m_licensePlate, licensePlate, 8);
            m_licensePlate[8] = '\0';
            m_makeModel = new char[strlen(makeModel) + 1];
            strcpy(m_makeModel, makeModel);
            m_parkingSpotNumber = 0;
        }
    }

    Vehicle::~Vehicle()
    {
        delete[] m_makeModel;
        m_makeModel = nullptr;
    }

    Vehicle::Vehicle(const Vehicle &src)
    {
        m_makeModel = nullptr;
        setEmpty();
        *this = src;
    }

    Vehicle &Vehicle::operator=(const Vehicle &src)
    {
        if (this != &src)
        {
            // call copy constructor of ReadWritable
            ReadWritable::operator=(src);
            if (m_makeModel != nullptr)
            {
                delete[] m_makeModel;
                m_makeModel = nullptr;
            }
            strncpy(m_licensePlate, src.m_licensePlate, 8);
            m_licensePlate[8] = '\0';
            if (src.m_makeModel != nullptr)
            {
                m_makeModel = new char[strlen(src.m_makeModel) + 1];
                strcpy(m_makeModel, src.m_makeModel);
            }
            m_parkingSpotNumber = src.m_parkingSpotNumber;
        }
        return *this;
    }

    void Vehicle::setEmpty()
    {
        m_licensePlate[0] = '\0';
        if (m_makeModel != nullptr)
        {
            delete[] m_makeModel;
            m_makeModel = nullptr;
        }
        m_parkingSpotNumber = 0;
    }

    bool Vehicle::isEmpty() const
    {
        return m_licensePlate[0] == '\0' && m_makeModel == nullptr && m_parkingSpotNumber == 0;
    }

    const char *Vehicle::getLicensePlate() const
    {
        return m_licensePlate;
    }

    const char *Vehicle::getMakeModel() const
    {
        return m_makeModel;
    }

    void Vehicle::setMakeModel(const char *makeModel)
    {
        if (makeModel != nullptr && makeModel[0] != '\0')
        {
            if (m_makeModel != nullptr)
            {
                delete[] m_makeModel;
                m_makeModel = nullptr;
            }
            m_makeModel = new char[strlen(makeModel) + 1];
            strcpy(m_makeModel, makeModel);
        }
    }

    int Vehicle::getParkingSpot() const
    {
        return m_parkingSpotNumber;
    }

    void Vehicle::setParkingSpot(int parkingSpot)
    {
        if (parkingSpot >= 0)
        {
            m_parkingSpotNumber = parkingSpot;
        }
        else
        {
            setEmpty();
        }
    }

    bool Vehicle::operator==(const char *licensePlate) const
    {
        if (licensePlate != nullptr && licensePlate[0] != '\0' && m_licensePlate != nullptr && m_licensePlate[0] != '\0')
        {
            // change to uppercase
            char *temp = new char[strlen(licensePlate) + 1];
            strcpy(temp, licensePlate);
            for (int i = 0; temp[i] != '\0'; i++)
            {
                temp[i] = toupper(temp[i]);
            }
            // change to uppercase
            char *temp2 = new char[strlen(m_licensePlate) + 1];
            strcpy(temp2, m_licensePlate);
            for (int i = 0; temp2[i] != '\0'; i++)
            {
                temp2[i] = toupper(temp2[i]);
            }
            bool result = strcmp(temp, temp2) == 0;
            delete[] temp;
            delete[] temp2;
            return result;
        }
        return false;
    }

    bool Vehicle::operator==(const Vehicle &src) const
    {
        if (src.m_licensePlate != nullptr && src.m_licensePlate[0] != '\0' && m_licensePlate != nullptr && m_licensePlate[0] != '\0')
        {
            // change to uppercase
            char *temp = new char[strlen(src.m_licensePlate) + 1];
            strcpy(temp, src.m_licensePlate);
            for (int i = 0; temp[i] != '\0'; i++)
            {
                temp[i] = toupper(temp[i]);
            }
            // change to uppercase
            char *temp2 = new char[strlen(m_licensePlate) + 1];
            strcpy(temp2, m_licensePlate);
            for (int i = 0; temp2[i] != '\0'; i++)
            {
                temp2[i] = toupper(temp2[i]);
            }
            bool result = strcmp(temp, temp2) == 0;
            delete[] temp;
            delete[] temp2;
            return result;
        }
        return false;
    }

    istream &Vehicle::read(istream &istr)
    {
        if (isCsv())
        {
            istr >> m_parkingSpotNumber;
            istr.ignore();
            istr.getline(m_licensePlate, 9, ',');
            // change to uppercase
            for (int i = 0; m_licensePlate[i] != '\0' && i < 9; i++)
            {
                m_licensePlate[i] = toupper(m_licensePlate[i]);
            }
            char makeModel[61];
            istr.getline(makeModel, 61, ',');
            setMakeModel(makeModel);
        }
        else
        {

            m_parkingSpotNumber = 0;
            cout << "Enter License Plate Number: ";
            // Then it will read up to 8 characters from the console. If the user enters more than 8 Characters, it will print the following error message and tries again until a proper license plate number is entered.
            // "Invalid Licence Plate, try again: "

            string licensePlate;
            getline(istr, licensePlate);
            while (licensePlate.length() > 8)
            {
                cout << "Invalid License Plate, try again: ";
                getline(istr, licensePlate);
            }
            // change to uppercase
            for (int i = 0; licensePlate[i] != '\0' && i < 8; i++)
            {
                licensePlate[i] = toupper(licensePlate[i]);
            }
            strcpy(m_licensePlate, licensePlate.c_str());
            cout << "Enter Make and Model: ";
            // Afterwards, it will read 2 to 60 characters from the console. If the user enters a value with an invalid length, it will print the following error message and tries again until a proper make and model are entered.
            // "Invalid Make and model, try again: "
            string makeModel;
            getline(istr, makeModel);
            while (makeModel.length() < 2 || makeModel.length() > 60)
            {
                cout << "Invalid Make and model, try again: ";
                getline(istr, makeModel);
            }
            setMakeModel(makeModel.c_str());
        }

        if (istr.fail())
        {
            setEmpty();
        }
        return istr;
    }

    ostream &Vehicle::write(ostream &ostr) const
    {
        if (isEmpty())
        {
            ostr << "Invalid Vehicle Object" << endl;
        }
        else
        {
            writeType();
            if (isCsv())
            {
                ostr << m_parkingSpotNumber << "," << m_licensePlate << "," << m_makeModel << ",";
            }
            else
            {
                ostr << "Parking Spot Number: ";
                if (m_parkingSpotNumber == 0)
                {
                    ostr << "N/A" << endl;
                }
                else
                {
                    ostr << m_parkingSpotNumber << endl;
                }
                ostr << "License Plate: " << m_licensePlate << endl;
                ostr << "Make and Model: " << m_makeModel << endl;
            }
        }
        return ostr;
    }
}
