#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
   class Numbers
   {
      double *m_numbers{};
      char *m_filename{};
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty() const;
      void setEmpty();
      void deallocate();
      void setFilename(const char *filename);
      // Numbers& sort(bool ascending)
      Numbers &sort(bool ascending);

   public:
      Numbers();
      Numbers(const char *filename);
      // Copy Constructor
      Numbers(const Numbers &N);
      // Copy Assignment Operator
      Numbers &operator=(const Numbers &N);
      // Unary negation operator ( - )
      Numbers operator-() const;
      // Unary plus operator ( + )
      Numbers operator+() const;
      // numberCount()
      int numberCount() const;
      // load()
      bool load();
      // save()
      void save() const;
      // Operator += Overload the += operator to add a single double value to the list of numbers
      Numbers &operator+=(double value);
      std::ostream &display(std::ostream &ostr) const;
      friend std::ostream &operator<<(std::ostream &os, const Numbers &N);
      friend std::istream &operator>>(std::istream &istr, Numbers &N);

      double average() const;
      double max() const;
      double min() const;
      ~Numbers();
   };
}
#endif // !SDDS_NUMBERS_H_
