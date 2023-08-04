#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;
namespace sdds
{
   Apartment::Apartment(int number, double balance)
   {

      if (number >= 1000 && number <= 9999 && balance >= 0)
      {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream &Apartment::display() const
   {
      if (*this)
      {
         cout.width(4);
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else
      {
         cout << "Invld|  Apartment   ";
      }
      return cout;
   }

   Apartment::operator bool() const
   {
      return (m_number >= 1000 && m_number <= 9999 && m_balance >= 0);
   }

   Apartment::operator int() const
   {
      return m_number;
   }

   Apartment::operator double() const
   {
      return m_balance;
   }

   bool Apartment::operator~() const
   {
      return m_balance < 0.00001;
   }

   Apartment &Apartment::operator=(int number)
   {
      if (number >= 1000 && number <= 9999)
      {
         m_number = number;
      }
      else
      {
         m_number = -1;
         m_balance = 0.0;
      }
      return *this;
   }

   Apartment &Apartment::operator=(Apartment &apt)
   {
      if (apt && *this)
      {
         // this action should swap the rent balance and the apartment number of one apartment to another
         int temp = m_number;
         m_number = apt.m_number;
         apt.m_number = temp;
         double temp2 = m_balance;
         m_balance = apt.m_balance;
         apt.m_balance = temp2;
      }
      return *this;
   }

   Apartment &Apartment::operator+=(double balance)
   {
      if (*this && balance > 0)
      {
         m_balance += balance;
      }
      return *this;
   }

   Apartment &Apartment::operator-=(double balance)
   {
      if (*this && balance > 0 && m_balance >= balance)
      {
         m_balance -= balance;
      }
      return *this;
   }

   Apartment &Apartment::operator<<(Apartment &apt)
   {
      if (apt && *this && &apt != this)
      {
         m_balance += apt.m_balance;
         apt.m_balance = 0;
      }
      return *this;
   }

   Apartment &Apartment::operator>>(Apartment &apt)
   {
      // overload the << operator (left shift operator) to move the balance from the right apartment to the left apartment. After this operation, the balance of the left apartment account will be the sum of both the left and right apartment, and the balance of the right apartment account will be zero.
      // The balance of an apartment should not be able to be "moved" to itself and this operation will not affect the account in this situation.
      // In any case, a reference of the current object (apartment) should be returned.

      if (apt && *this && &apt != this)
      {
         apt.m_balance += m_balance;
         m_balance = 0;
      }
      return *this;
   }

   double operator+(const Apartment &left, const Apartment &right)
   {
      if (left && right)
         return double(left) + double(right);
      return 0;
   }

   double &operator+=(double &left, const Apartment &right)
   {
      if (right)
         left += double(right);
      return left;
   }

}