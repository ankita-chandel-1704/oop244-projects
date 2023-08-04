#define _CRT_SECURE_NO_WARNINGS
#include "CC.h"

using namespace std;

namespace sdds
{
    

    bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const
    {
        bool valid = false;
        if (name != nullptr && strlen(name) > 2 && cardNo >= 4000000000000000 && cardNo <= 4099999999999999 && cvv >= 100 && cvv <= 999 && expMon >= 1 && expMon <= 12 && expYear >= 22 && expYear <= 32)
        {
            valid = true;
        }
        return valid;
    }

    

    void CC::prnNumber() const
    {
        unsigned long long cardNo = m_cardNumber;
        int fourDigit = 0;
        
        for (int i = 4; i > 0; i--)
        {
            unsigned long long divisor = 1;
            // divisor = 10000 raised to the power of i
            for (int j = 1; j < i; j++)
            {
                divisor *= 10000;
            }
            fourDigit = cardNo / divisor;
            cardNo = cardNo % divisor;
            cout << setfill('0') << setw(4) << right << fourDigit;
            cout << setfill(' ') << left;
            if (i > 1)
            {
                cout << " ";
            }
        }
    }

   
    void CC::set()
    {
        m_name = nullptr;
        m_cardNumber = 0;
        m_cvv = 0;
        m_expiryMonth = 0;
        m_expiryYear = 0;
    }

    
    void CC::cleanUp()
    {
        if (m_name != nullptr)
        {
            delete[] m_name;
            m_name = nullptr;
        }
        set();
    }

    //     bool isEmpty() const;
    // Returns if the CC object is in a safe empty state or not; by returning true if the cardholder name pointer attribute of the object is nullptr, otherwise, it will return false.
    bool CC::isEmpty() const
    {
        bool empty = false;
        if (m_name == nullptr)
        {
            empty = true;
        }
        return empty;
    }
    

    void CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear)
    {
        cleanUp();
        if (validate(cc_name, cc_no, cvv, expMon, expYear))
        {
            m_name = new char[strlen(cc_name) + 1];
            strcpy(m_name, cc_name);
            m_cardNumber = cc_no;
            m_cvv = cvv;
            m_expiryMonth = expMon;
            m_expiryYear = expYear;
        }
    }

    //     bool read();
    // Assuming that the names are not longer than 70 characters, this function will attempt to read all the values from the console in local (function scope) variables first and if successful, they will be validated and then stored in the object.

    // The function will return true if the values are stored in the object and false otherwise.

    // Follow these steps to write this function: Create an array of 71 characters for the name and temporary variables for other attributes of the class.

    // The function will first call cleanUp() to deallocate possible previous data allocation and reads the values into local function scope variables as follows:

    // Prompt "Card holder name: "
    // using cin.getline() read 71 characters into a local name cstring.
    // if cin has not failed prompt "Credit card number: "

    bool CC::read()
    {
        char name[71];
        unsigned long long no;
        short cvv;
        short mon;
        short year;
        cleanUp();
        cout << "Card holder name: ";
        cin.getline(name, 71);
        if (!cin.fail())
        {
            cout << "Credit card number: ";
            cin >> no;
            if (!cin.fail())
            {
                cout << "Card Verification Value (CVV): ";
                cin >> cvv;
                if (!cin.fail())
                {
                    cout << "Expiry month and year (MM/YY): ";
                    cin >> mon;
                    cin.ignore();
                    cin >> year;
                    if (!cin.fail())
                    {
                        set(name, no, cvv, mon, year);
                    }
                    else
                    {
                        cin.clear();
                    }
                }
                else
                {
                    cin.clear();
                }
            }
            else
            {
                cin.clear();
            }
        }
        else
        {
            cin.clear();
        }
        cin.ignore(1000, '\n');
        return !isEmpty();
    }

    //     void display(int row = 0) const;
    // If the object isEmpty(), print "Invalid Credit Card Record";

    // If it is not in a safe empty state, depending on the value of the row being greater than zero or not, print the CC information in a row, or in a form format respectively:

    // if row > 0:
    // When printing, all the values have one space between them and the separator bar (see example).

    // row: right justified in 3 spaces
    // Name: left justified in 30 spaced
    // Card number: printed using prnNumber
    // cvv: printed as is
    // Month: right justified in 2 spaces
    // slash ('/')
    // year: printed as it.
    // newline
    // Example:

    // |  30 | Homer Simpson                  | 4089 0511 8229 9500 | 815 |  6/30 |
    // note: using cout.setf(ios::left) or cout.setf(ios::right), its a good practice to unsetf them after printing the field (ie. cout.unsetf(ios::left) or cout.unsetf(ios::right)). This will put cout back in its neutral state.

    // if row < = 0
    // Display the CC information in the following way (no formatting, other than the prnNumber function)

    // Name: Hubert Blaine
    // Creditcard No: 4098 7654 2345 7896
    // Card Verification Value: 123
    // Expiry Date: 5/25

    void CC::display(int row) const
    {
        if (isEmpty())
        {
            cout << "Invalid Credit Card Record" << endl;
        }
        else
        {
            if (row > 0)
            {
                char name[31];
                // copy first 30 characters of m_name into name
                strncpy(name, m_name, 30);
                name[30] = '\0';
                cout << "| " << setw(3) << right << row << " | " << setw(30) << left << name << " | ";
                prnNumber();
                cout << " | " << m_cvv << " | " << setw(2) << right << m_expiryMonth << "/" << m_expiryYear << " |" << endl;
                // put cout back in its neutral state.
                cout.unsetf(ios::right);
                cout.unsetf(ios::left);
            }
            else
            {
                cout << "Name: " << m_name << endl;
                cout << "Creditcard No: ";
                prnNumber();
                cout << endl;
                cout << "Card Verification Value: " << m_cvv << endl;
                cout << "Expiry Date: " << m_expiryMonth << "/" << m_expiryYear << endl;
            }
        }
    }
}

