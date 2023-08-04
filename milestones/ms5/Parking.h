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


#ifndef __SDDS_PARKING_H__
#define __SDDS_PARKING_H__

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>

#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Menu.h"
namespace sdds
{
    const int MAX_PARKING_SPOTS = 100;
    class Parking
    {
        int m_noOfSpots;
        Vehicle *m_parkingSpots[MAX_PARKING_SPOTS];
        int m_noOfParkedVehicles;
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
        Parking(const char *datafile, int noOfSpots);
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