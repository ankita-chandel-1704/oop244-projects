#ifndef __SDDS_CC_H__
#define __SDDS_CC_H__

#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
    class CC
    {
        
        char* m_name;
        unsigned long long m_cardNumber;
        short m_cvv;
        short m_expiryMonth;
        short m_expiryYear;
        // The CC class has the following Private functions:

        bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const;
        void prnNumber() const;
        

    public:
        void set();
        void cleanUp();
        bool isEmpty() const;
        void set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear);
        bool read();
        void display(int row = 0) const;
    };
}

#endif