#include "TourBus.h"

using namespace std;

namespace sdds
{
    TourBus::TourBus(int numOfSeats)
    {
        // Your TourBus should come in three sizes:

        // 4 passenger private tour
        // 16 passengers Mini tour bus
        // 22 passengers Full-size bus.

        // If the number of seats is not one of the above, then the TourBus is invalid.
        if (numOfSeats == 4 || numOfSeats == 16 || numOfSeats == 22)
        {
            m_numOfSeats = numOfSeats;
            m_tickets = new TourTicket[m_numOfSeats];
            m_numOfIssuedTickets = 0;
        }
        else
        {
            m_numOfSeats = 0;
            m_tickets = nullptr;
            m_numOfIssuedTickets = 0;
        }
    }

    bool TourBus::validTour() const
    {
        return m_numOfSeats > 0;
    }

    TourBus& TourBus::board()
    {
        // board the passengers
        // Boarding 4 Passengers:
        cout << "Boarding " << m_numOfSeats << " Passengers:" << endl;
        for (int i = 0; i < m_numOfSeats; i++)
        {
            //    1/4- Passenger Name:
            cout << i + 1 << "/" << m_numOfSeats << "- Passenger Name: ";
            char name[41];
            cin.getline(name, 41, '\n');
            m_tickets[i].issue(name);
            m_numOfIssuedTickets++;
        }
        return *this;
    }

    void TourBus::startTheTour() const
    {
        int i;
        if (validTour() && m_numOfIssuedTickets == m_numOfSeats)
        {
            cout << "Starting the tour...." << endl;
            cout << "Passenger List:" << endl;
            cout << "|Row | Passenger Name                           | Num |" << endl;
            cout << "+----+------------------------------------------+-----+" << endl;
            for (i = 0; i < m_numOfSeats; i++)
            {
                cout << "| " << setw(2) << i + 1 << " ";
                m_tickets[i].display();
                cout << endl;
            }
            cout << "+----+------------------------------------------+-----+" << endl;
        }
        else
        {
            cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
        }
    }

    TourBus::~TourBus()
    {
        delete[] m_tickets;
    }
}
