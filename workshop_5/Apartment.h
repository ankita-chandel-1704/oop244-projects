
#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
   class Apartment
   {
      int m_number = -1;
      double m_balance = 0.0;

   public:
      Apartment(int number, double balance);
      std::ostream &display() const;
      // operator bool
      operator bool() const;
      // operator int
      operator int() const;
      // operator double
      operator double() const;
      // bool operator ~()
      bool operator~() const;
      // assignment operators
      // overload the assignment operator so an apartment can be set to an integer
      Apartment &operator=(int number);
      // overload the assignment operator so an apartment can be set to another apartment object
      Apartment &operator=(Apartment &apt);
      // overload the += operator to add a double value to an apartment.
      Apartment &operator+=(double balance);
      // overload the -= operator to reduce an apartment rent balance by a double value.
      Apartment &operator-=(double balance);
      // overload the << operator (left shift operator) to move the balance from the right apartment to the left apartment
      Apartment &operator<<(Apartment &apt);
      // overload the >> operator (right shift operator) to move the balance from the left apartment to the right apartment.
      Apartment &operator>>(Apartment &apt);
      // create a binary stand-alone helper + operator that accepts a constant apartment reference on the left and another constant apartment reference on the right that returns a double value.
      friend double operator+(const Apartment &left, const Apartment &right);
      // create a binary stand-alone helper += operator that accepts a double reference on the left and a constant apartment reference on the right that returns a double value.
      friend double &operator+=(double &left, const Apartment &right);
   };
}

#endif // SDDS_APARTMENT_H_