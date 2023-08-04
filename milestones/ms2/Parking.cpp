#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"

using namespace std;

namespace sdds
{
    // Parking constructor
    Parking::Parking(const char *filename) : m_parkingMenu("Parking Menu, select an action:", 0),
                                             m_vehicleMenu("Select type of the vehicle:", 1)
    {
        if (filename == nullptr || filename[0] == '\0')
        {
            m_filename = nullptr;
        }
        else
        {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
        }
        if (!loadDataFile())
        {
            cout << "Error in data file" << endl;
        }
        m_parkingMenu << "Park Vehicle"
                      << "Return Vehicle"
                      << "List Parked Vehicles"
                      << "Find Vehicle"
                      << "Close Parking (End of day)"
                      << "Exit Program";
        m_vehicleMenu << "Car"
                      << "Motorcycle"
                      << "Cancel";
    }

    // Parking destructor
    Parking::~Parking()
    {
        saveDataFile();
        delete[] m_filename;
        m_filename = nullptr;
    }

    // isEmpty() function
    bool Parking::isEmpty() const
    {
        return m_filename == nullptr;
    }

    // Parking Status function
    void Parking::parkingStatus() const
    {
        cout << "****** Valet Parking ******" << endl;
    }

    // Park Vehicle function
    void Parking::parkVehicle()
    {
        // The function displays the Vehicle Selection sub-menu. Then based on the user's selection; Car, Motorcycle or Cancel, it will print the corresponding message. Afterwards, it goes to a new line.
        int selection = m_vehicleMenu.run();
        if (selection == 1)
        {
            // ---------------------------------
            // Parking Car
            // ---------------------------------
            cout << "---------------------------------" << endl;
            cout << "Parking Car" << endl;
            cout << "---------------------------------" << endl
                 << endl;
        }
        else if (selection == 2)
        {
            // ---------------------------------
            // Parking Motorcycle
            // ---------------------------------
            cout << "---------------------------------" << endl;
            cout << "Parking Motorcycle" << endl;
            cout << "---------------------------------" << endl
                 << endl;
        }
        else
        {
            // ---------------------------------
            // Cancelled parking
            // ---------------------------------
            cout << "---------------------------------" << endl;
            cout << "Cancelled parking" << endl;
            cout << "---------------------------------" << endl
                 << endl;
        }
    }

    // Return Vehicle function
    void Parking::returnVehicle()
    {
        cout << "---------------------------------" << endl;
        cout << "Returning Vehicle" << endl;
        cout << "---------------------------------" << endl
             << endl;
    }

    // List Parked Vehicles function
    void Parking::listParkedVehicles() const
    {
        cout << "---------------------------------" << endl;
        cout << "Listing Parked Vehicles" << endl;
        cout << "---------------------------------" << endl
             << endl;
    }

    // Find Vehicle function
    void Parking::findVehicle() const
    {
        cout << "---------------------------------" << endl;
        cout << "Finding a Vehicle" << endl;
        cout << "---------------------------------" << endl
             << endl;
    }

    // Close Parking function
    bool Parking::closeParking()
    {
        // Selecting this option ends the parking application for the day
        // If the exit program option is selected first display the message:

        // This will close the parking; All the vehicles will be removed!
        // Are you sure? (Y)es/(N)o:
        // And wait for the user to enter either “Y” or “N” (lowercase or uppercase) and exit if the response is yes.

        // If the user enters an invalid response then print:

        // Invalid response, only (Y)es or (N)o are acceptable, retry:
        // And repeat until a proper response is entered.

        char response;
        cout << "This will close the parking; All the vehicles will be removed!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        while (true)
        {
            cin >> response;
            if (response == 'Y' || response == 'y')
            {
                return true;
            }
            else if (response == 'N' || response == 'n')
            {
                return false;
            }
            else
            {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            }
        }
    }

    // Exit Parking App Function
    bool Parking::exitParkingApp() const
    {
        //    Selecting this option ends the parking application temporarily.
        //     If the exit program option is selected first display the message:

        //     This will terminate the application and save the data!
        //     Are you sure? (Y)es/(N)o:
        //     And wait for the user to enter either “Y” or “N” (lowercase or uppercase) and exit if the response is yes.

        //     If the user enters an invalid response then print:

        //     Invalid response, only (Y)es or (N)o are acceptable, retry:
        //     And repeat until a proper response is entered.

        char response;
        cout << "This will terminate the application and save the data!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        while (true)
        {
            cin >> response;
            if (response == 'Y' || response == 'y')
            {
                return true;
            }
            else if (response == 'N' || response == 'n')
            {
                return false;
            }
            else
            {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            }
        }
    }

    // Load Data File function
    bool Parking::loadDataFile()
    {
        bool ok = false;
        if (m_filename != nullptr)
        {
            cout << "---------------------------------" << endl;
            cout << "loading data from " << m_filename << endl;
            cout << "---------------------------------" << endl
                 << endl;

            ok = true;
        }
        return ok;
    }

    // Save Data File function
    void Parking::saveDataFile() const
    {
        if (m_filename != nullptr)
        {
            cout << "---------------------------------" << endl;
            cout << "Saving data into " << m_filename << endl;
            cout << "---------------------------------" << endl
                 << endl;
        }
    }

    // int Parking::run();
    int Parking::run()
    {
        int selection = 0;
        if (!isEmpty())
        {
            bool continueApp = true;
            do
            {
                parkingStatus();
                selection = m_parkingMenu.run();
                switch (selection)
                {
                case 1:
                    parkVehicle();
                    break;
                case 2:
                    returnVehicle();
                    break;
                case 3:
                    listParkedVehicles();
                    break;
                case 4:
                    findVehicle();
                    break;
                case 5:
                    if (closeParking())
                    {
                        continueApp = false;
                        cout << "Ending application!" << endl;
                    }
                    break;
                default:
                    if (exitParkingApp())
                    {
                        continueApp = false;
                        cout << "Exiting application!" << endl;
                    }
                    break;
                }
            } while (continueApp);
            return 0;
        }
        return 1;
    }

}
