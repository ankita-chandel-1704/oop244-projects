#ifndef __SDDS_PARKING_H__
#define __SDDS_PARKING_H__

#include <iostream>
#include <string.h>
#include <iomanip>
#include "Menu.h"
namespace sdds
{
    class Parking
    {
        char *m_filename;
        Menu m_parkingMenu;
        Menu m_vehicleMenu;
        // isEmpty() function
        bool isEmpty() const;
        // Parking Status function
        void parkingStatus() const;
        // Park Vehicle function
        void parkVehicle();
        // Return Vehicle function
        void returnVehicle();
        // List Parked Vehicles function
        void listParkedVehicles() const;
        // Find Vehicle function
        void findVehicle() const;
        // Close Parking function
        bool closeParking();
        // Exit Parking App Function
        bool exitParkingApp() const;
        // Load Data File function
        bool loadDataFile();
        // Save Data File function
        void saveDataFile() const;

    public:
        // A Parking object can be created by a constant C-style character string, to be used to set its filename.
        Parking(const char *filename = nullptr);
        // destructor
        ~Parking();
        // Parking can not get copied or assigned to another Parking. This, must be enforced in your code.
        Parking(const Parking &src) = delete;
        Parking &operator=(const Parking &src) = delete;
        // int Parking::run();
        int run();
    };
}

#endif