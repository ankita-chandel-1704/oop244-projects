#ifndef __SDDS_TOURBUS_H__
#define __SDDS_TOURBUS_H__

#include <iostream>
#include <string.h>
#include <iomanip>
#include "TourTicket.h"
namespace sdds
{
    class TourBus
    {
        TourTicket* m_tickets;
        int m_numOfSeats;
        int m_numOfIssuedTickets;

    public:
        TourBus(int numOfSeats);
        bool validTour() const;
        TourBus& board();
        void startTheTour() const;
        ~TourBus();
    };
}

#endif