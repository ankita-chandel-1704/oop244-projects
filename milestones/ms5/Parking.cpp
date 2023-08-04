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




#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"

using namespace std;

namespace sdds
{
    // Parking constructor
    Parking::Parking(const char *datafile, int noOfSpots) : m_parkingMenu("Parking Menu, select an action:", 0),
							    m_vehicleMenu("Select type of the vehicle:", 1)
    {
	for (int i = 0; i < MAX_PARKING_SPOTS; i++)
	{
	    m_parkingSpots[i] = nullptr;
	}
	if (noOfSpots < 10 || noOfSpots > MAX_PARKING_SPOTS)
	{
	    m_filename = nullptr;
	    m_noOfSpots = 0;
	    m_noOfParkedVehicles = 0;
	}
	else
	{
	    m_noOfSpots = noOfSpots;
	    m_noOfParkedVehicles = 0;
	    if (datafile == nullptr || datafile[0] == '\0')
	    {
		m_filename = nullptr;
	    }
	    else
	    {
		m_filename = new char[strlen(datafile) + 1];
		strcpy(m_filename, datafile);
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
    }
    // Parking destructor
    Parking::~Parking()
    {
	saveDataFile();
	delete[] m_filename;
	m_filename = nullptr;
	for (int i = 0; i < m_noOfSpots; i++)
	{
	    delete m_parkingSpots[i];
	    m_parkingSpots[i] = nullptr;
	}
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
	// "***** Available spots: "
	// In 4 spaces, left justified, it will print the number of available Parking Spots
	// " *****"<NEWLINE>
	cout << "*****  Available spots: ";
	cout << setw(4) << left << (m_noOfSpots - m_noOfParkedVehicles);
	cout << " *****" << endl;
    }

    // Park Vehicle function
    void Parking::parkVehicle()
    {
	// // The function displays the Vehicle Selection sub-menu. Then based on the user's selection; Car, Motorcycle or Cancel, it will print the corresponding message. Afterwards, it goes to a new line.
	// int selection = m_vehicleMenu.run();
	// if (selection == 1)
	// {
	//     // ---------------------------------
	//     // Parking Car
	//     // ---------------------------------
	//     cout << "---------------------------------" << endl;
	//     cout << "Parking Car" << endl;
	//     cout << "---------------------------------" << endl
	//          << endl;
	// }
	// else if (selection == 2)
	// {
	//     // ---------------------------------
	//     // Parking Motorcycle
	//     // ---------------------------------
	//     cout << "---------------------------------" << endl;
	//     cout << "Parking Motorcycle" << endl;
	//     cout << "---------------------------------" << endl
	//          << endl;
	// }
	// else
	// {
	//     // ---------------------------------
	//     // Cancelled parking
	//     // ---------------------------------
	//     cout << "---------------------------------" << endl;
	//     cout << "Cancelled parking" << endl;
	//     cout << "---------------------------------" << endl
	//          << endl;
	// }

	// This function does not receive or return anything.

	// If there are no Parking Spots available, the function prints "Parking is full" and exits. Otherwise, the function displays the Vehicle Selection sub-menu and then based on the user’s selection performs the following:

	// If the user selects Cancel, it will print "Parking Cancelled"<NEWLINE> and exits the function. Otherwise, it will dynamically create an instance of a Car or Motorcycle (based on the user’s selection) in a Vehicle pointer. Then it will set it NOT to be in Comma Separated mode and reads it from the console.

	// After receiving the Vehicle information from the console, the function will search through the Parking Spots array and finds the first available (null) Parking Spot and sets it to the Vehicle pointer and also it will set the Parking Spot member variable of the Vehicle to the spot number it was parked in (index + 1) and prints the following: "Parking Ticket"<NEWLINE> and prints the Vehicle.

	if (m_noOfParkedVehicles == m_noOfSpots)
	{
	    cout << "Parking is full" << endl;
	}
	else
	{
	    Vehicle *v = nullptr;
	    int selection = m_vehicleMenu.run();
	    if (selection == 1)
	    {
		// ---------------------------------
		// Parking Car
		// ---------------------------------
		// cout << "---------------------------------" << endl;
		// cout << "Parking Car" << endl;
		// cout << "---------------------------------" << endl
		//      << endl;

		v = new Car;
	    }
	    else if (selection == 2)
	    {
		// ---------------------------------
		// Parking Motorcycle
		// ---------------------------------
		// cout << "---------------------------------" << endl;
		// cout << "Parking Motorcycle" << endl;
		// cout << "---------------------------------" << endl
		//      << endl;

		v = new Motorcycle;
	    }
	    else
	    {
		cout << "Parking cancelled" << endl;
		// Press <ENTER> to continue....
		cout << "Press <ENTER> to continue....";
		cin.get();
		return;
	    }
	    v->setCsv(false);
	    cin >> *v;
	    for (int i = 0; i < m_noOfSpots; i++)
	    {
		if (m_parkingSpots[i] == nullptr)
		{
		    m_parkingSpots[i] = v;
		    m_parkingSpots[i]->setParkingSpot(i + 1);
		    cout << endl
			 << "Parking Ticket" << endl;
		    m_parkingSpots[i]->write(cout);
		    cout << endl;
		    m_noOfParkedVehicles++;
		    break;
		}
	    }
	}
	cout << "Press <ENTER> to continue....";
	cin.get();
    }

    // Return Vehicle function
    void Parking::returnVehicle()
    {
	// cout << "---------------------------------" << endl;
	// cout << "Returning Vehicle" << endl;
	// cout << "---------------------------------" << endl
	//      << endl;

	cout << "Return Vehicle" << endl;
	cout << "Enter Licence Plate Number: ";
	string licencePlate;
	cin >> licencePlate;
	while (licencePlate.length() > 8 || licencePlate.length() < 1)
	{
	    cout << "Invalid Licence Plate, try again: ";
	    cin >> licencePlate;
	}
	// convert to upper case
	for (size_t i = 0; i < licencePlate.length(); i++)
	{
	    licencePlate[i] = toupper(licencePlate[i]);
	}
	cout << endl;
	int i;
	for (i = 0; i < m_noOfSpots; i++)
	{
	    if (m_parkingSpots[i] != nullptr && *m_parkingSpots[i] == licencePlate.c_str())
	    {
		m_parkingSpots[i]->setCsv(false);
		cout << "Returning:" << endl
		     << *m_parkingSpots[i] << endl;
		delete m_parkingSpots[i];
		m_parkingSpots[i] = nullptr;
		m_noOfParkedVehicles--;
		// cout << endl;
		cout << "Press <ENTER> to continue....";
		cin.get();
		if (cin.peek() == '\n')
		{
		    cin.get();
		}
		return;
	    }
	}
	cout << "License plate " << licencePlate << " Not found" << endl;
	cout << endl;
	cout << "Press <ENTER> to continue....";
	cin.get();
	if (cin.peek() == '\n')
	{
	    cin.get();
	}
    }

    // List Parked Vehicles function
    void Parking::listParkedVehicles() const
    {
	// cout << "---------------------------------" << endl;
	cout << "*** List of parked vehicles ***" << endl;
	// cout << "---------------------------------" << endl
	//      << endl;

	for (int i = 0; i < m_noOfSpots; i++)
	{
	    if (m_parkingSpots[i] != nullptr)
	    {
		m_parkingSpots[i]->setCsv(false);
		m_parkingSpots[i]->write(cout);
		cout << "-------------------------------";
		cout << endl;
	    }
	}
	cout << "Press <ENTER> to continue....";
	cin.get();
    }

    // Find Vehicle function
    void Parking::findVehicle() const
    {
	// cout << "---------------------------------" << endl;
	// cout << "Finding a Vehicle" << endl;
	// cout << "---------------------------------" << endl
	//      << endl;

	cout << "Vehicle Search" << endl;

	string licensePlate;
	cout << "Enter Licence Plate Number: ";
	getline(cin, licensePlate);
	while (licensePlate.length() < 1 || licensePlate.length() > 8)
	{
	    cout << "Invalid Licence Plate, try again: ";
	    getline(cin, licensePlate);
	}
	// convert to uppercase
	for (size_t i = 0; i < licensePlate.length(); i++)
	{
	    licensePlate[i] = toupper(licensePlate[i]);
	}
	for (int i = 0; i < m_noOfSpots; i++)
	{
	    if (m_parkingSpots[i] != nullptr)
	    {
		if (*m_parkingSpots[i] == licensePlate.c_str())
		{
		    // If found, print "Vechicle found:"<NEWLINE> and print the Vehicle.
		    cout << endl
			 << "Vechicle found: " << endl;
		    m_parkingSpots[i]->setCsv(false);
		    m_parkingSpots[i]->write(cout);
		    cout << endl
			 << "Press <ENTER> to continue....";
		    cin.get();
		    return;
		}
	    }
	}

	// If not found, print "No match found"<NEWLINE>
	cout << endl
	     << "License plate " << licensePlate << " Not found" << endl
	     << endl;
	cout << "Press <ENTER> to continue....";
	cin.get();
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

	// char response;
	// cout << "This will close the parking; All the vehicles will be removed!" << endl;
	// cout << "Are you sure? (Y)es/(N)o: ";
	// while (true)
	// {
	//     cin >> response;
	//     if (response == 'Y' || response == 'y')
	//     {
	//         return true;
	//     }
	//     else if (response == 'N' || response == 'n')
	//     {
	//         return false;
	//     }
	//     else
	//     {
	//         cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
	//     }
	// }

	// If the Parking is empty this function will print:
	// "Closing Parking" <NEWLINE>
	// Then exits the function returning true.

	// Otherwise, this function first prints a confirmation message for the user as follows:
	// "This will Remove and tow all remaining Vehicles from the Parking!"<NEWNLINE>
	// "Are you sure? (Y)es/(N)o: "
	// And waits for the user to enter either “Y” or “N” (lowercase or uppercase). If the user enters an invalid response then prints:
	// "Invalid response, only (Y)es or (N)o are acceptable, retry: "
	// and repeats until the proper response is entered.

	// If the user response is no, then the function exits returning false. Otherwise, it will first print
	// "Closing Parking"<NEWLINE>
	// it will go through all the parked Vehicles as follows:
	// 1- Prints a towing ticket:
	// "Towing request"<NEWLINE>
	// "*********************"<NEWLINE>
	// 2- Prints the Vehicle and skips a line.
	// 3- Deletes the Vehicle and sets the Parking Spot to null until all the Vehicles are removed from the Parking. then returns true.

	if (m_noOfParkedVehicles == 0)
	{
	    cout << "Closing Parking" << endl;
	    return true;
	}
	else
	{
	    char response;
	    cout << "This will This will Remove and tow all remaining vehicles from the parking!!" << endl;
	    cout << "Are you sure? (Y)es/(N)o: ";
	    while (true)
	    {
		cin >> response;
		if (response == 'Y' || response == 'y')
		{
		    cout << "Closing Parking" << endl;

		    for (int i = 0; i < m_noOfSpots; i++)
		    {
			if (m_parkingSpots[i] != nullptr)
			{
			    cout << endl
				 << "Towing request" << endl;
			    cout << "*********************" << endl;
			    m_parkingSpots[i]->setCsv(false);
			    cout << *m_parkingSpots[i];
			    delete m_parkingSpots[i];
			    m_parkingSpots[i] = nullptr;
			}
		    }
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
	cout << "This will This will terminate the program!!" << endl;
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
	    // cout << "---------------------------------" << endl;
	    // cout << "loading data from " << m_filename << endl;
	    // cout << "---------------------------------" << endl
	    //      << endl;

	    ifstream datafile(m_filename);

	    if (!datafile.is_open())
	    {
		if (m_noOfParkedVehicles == 0 && m_noOfSpots == 0)
		{
		    ok = true;
		}
	    }
	    else
	    {
		char type;
		int i = 0;
		while (i < m_noOfSpots)
		{
		    datafile >> type;
		    datafile.ignore();
		    Vehicle *v = nullptr;
		    if (datafile.fail())
		    {
			break;
		    }
		    if (type == 'M')
		    {
			v = new Motorcycle;
		    }
		    else if (type == 'C')
		    {
			v = new Car;
		    }
		    else
		    {
			v = nullptr;
		    }
		    if (v != nullptr)
		    {
			v->setCsv(true);
			datafile >> *v;
			if (datafile.fail())
			{
			    ok = false;
			    delete v;
			    v = nullptr;
			    break;
			}
			else
			{
			    m_parkingSpots[v->getParkingSpot() - 1] = v;
			    ok = true;
			    m_noOfParkedVehicles++;
			}
		    }
		    i++;
		}
	    }
	}
	return ok;
    }

    // Save Data File function
    void Parking::saveDataFile() const
    {
	if (m_filename != nullptr)
	{
	    // cout << "---------------------------------" << endl;
	    // cout << "Saving data into " << m_filename << endl;
	    // cout << "---------------------------------" << endl
	    //      << endl;

	    ofstream datafile(m_filename);
	    if (datafile.is_open())
	    {
		for (int i = 0; i < m_noOfSpots; i++)
		{
		    if (m_parkingSpots[i] != nullptr)
		    {
			m_parkingSpots[i]->setCsv(true);
			datafile << *m_parkingSpots[i];
		    }
		}
	    }
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
		    }
		    break;
		default:
		    if (exitParkingApp())
		    {
			continueApp = false;
			cout << "Exiting program!" << endl;
		    }
		    break;
		}
	    } while (continueApp);
	    if (cin.peek() == '\n')
	    {
		cin.get();
	    }
	    return 0;
	}
	return 1;
    }

}
