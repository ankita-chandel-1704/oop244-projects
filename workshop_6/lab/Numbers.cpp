#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds
{

   Numbers::Numbers()
   {
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char *filename)
   {
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load())
      {
         deallocate();
         setEmpty();
         m_isOriginal = false;
      }
   }

   Numbers::~Numbers()
   {
      save();
      deallocate();
   }

   bool Numbers::isEmpty() const
   {
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty()
   {
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }

   void Numbers::deallocate()
   {
      delete[] m_filename;
      delete[] m_numbers;
   }

   void Numbers::setFilename(const char *filename)
   {
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

   double Numbers::average() const
   {
      double aver = 0.0;
      if (!isEmpty())
      {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }

   double Numbers::min() const
   {
      double minVal = 0.0;
      if (!isEmpty())
      {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i])
               minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const
   {
      double maxVal = 0.0;
      if (!isEmpty())
      {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i])
               maxVal = m_numbers[i];
      }
      return maxVal;
   }

   // copy constructor
   Numbers::Numbers(const Numbers &N)
   {
      setEmpty();
      *this = N;
   }

   // copy assignment operator
   Numbers &Numbers::operator=(const Numbers &N)
   {
      if (this != &N)
      {
                  deallocate();
         setEmpty();
         m_isOriginal = false;
         m_numCount = N.m_numCount;
         m_numbers = new double[m_numCount];
         for (int i = 0; i < m_numCount; i++)
         {
            m_numbers[i] = N.m_numbers[i];
         }
      }
      return *this;
   }
      Numbers &Numbers::sort(bool ascending)
   {
      if (!isEmpty())
      {
         // use bubble sort
         for (int i = 0; i < m_numCount - 1; i++)
         {
            for (int j = 0; j < m_numCount - i - 1; j++)
            {
               if (ascending)
               {
                  if (m_numbers[j] > m_numbers[j + 1])
                  {
                     double temp = m_numbers[j];
                     m_numbers[j] = m_numbers[j + 1];
                     m_numbers[j + 1] = temp;
                  }
               }
               else
               {
                  if (m_numbers[j] < m_numbers[j + 1])
                  {
                     double temp = m_numbers[j];
                     m_numbers[j] = m_numbers[j + 1];
                     m_numbers[j + 1] = temp;
                  }
               }
            }
         }
      }
      return *this;
   }

      Numbers Numbers::operator-() const
   {
           Numbers temp;
      temp.m_numCount = m_numCount;
      temp.m_numbers = new double[m_numCount];
      for (int i = 0; i < m_numCount; i++)
      {
         temp.m_numbers[i] = m_numbers[i];
      }
      temp.sort(false);
      return temp;
   }

   // Numbers operator+()const
   Numbers Numbers::operator+() const
   {
      // This unary operator (that is incapable of modifying the current object) will return an ascending sorted copy of the Numbers object.
      Numbers temp;
      temp.m_numCount = m_numCount;
      temp.m_numbers = new double[m_numCount];
      for (int i = 0; i < m_numCount; i++)
      {
         temp.m_numbers[i] = m_numbers[i];
      }
      temp.sort(true);
      return temp;
   }

   // numberCount()
   int Numbers::numberCount() const
   {
      int count = 0;
            ifstream file(m_filename);
      if (file)
      {
         char ch;
         while (file.get(ch))
         {
            if (ch == '\n')
            {
               count++;
            }
         }
      }
      return count;
   }

   // load()
   bool Numbers::load()
   {
      
      bool success = false;
      int readCount = 0;
      if (m_numCount > 0)
      {
         m_numbers = new double[m_numCount];
         ifstream file(m_filename);
         if (file)
         {
            for (int i = 0; i < m_numCount; i++)
            {
               file >> m_numbers[i];
               if (file)
               {
                  success = true;
                  readCount++;
               }
               else
               {
                  success = false;
                  break;
               }
            }
            if (readCount != m_numCount)
            {
               success = false;
            }
         }
      }
      return success;
   }

     void Numbers::save() const
   {
      
      if (m_isOriginal && !isEmpty())
      {
         ofstream file(m_filename);
         if (file)
         {
            for (int i = 0; i < m_numCount; i++)
            {
               file << setprecision(2) << fixed << m_numbers[i] << endl;
            }
         }
      }
   }

   Numbers &Numbers::operator+=(double value)
   {
            if (!isEmpty())
      {
         double *temp = new double[m_numCount + 1];
         for (int i = 0; i < m_numCount; i++)
         {
            temp[i] = m_numbers[i];
         }
         m_numCount++;
         temp[m_numCount - 1] = value;
         delete[] m_numbers;
         m_numbers = temp;
      }
      return *this;
   }

      ostream &Numbers::display(ostream &ostr) const
   {
      if (isEmpty())
      {
         ostr << "Empty list";
      }
      else
      {
         ostr << "=========================" << endl;
         if (m_isOriginal)
         {
            ostr << m_filename << endl;
         }
         else
         {
            ostr << "*** COPY ***" << endl;
         }
         for (int i = 0; i < m_numCount; i++)
         {
            //  two digits after the decimal point
            ostr << setprecision(2) << fixed << m_numbers[i];
            if (i != m_numCount - 1)
            {
               ostr << ", ";
            }
         }
         ostr << endl;
         ostr << "-------------------------" << endl;
         ostr << "Total of " << m_numCount << " number(s)" << endl;
         ostr << "Largest number:  " << max() << endl;
         ostr << "Smallest number: " << min() << endl;
         ostr << "Average:         " << average() << endl;
         ostr << "=========================";
      }
      return ostr;
   }

    ostream &operator<<(ostream &os, const Numbers &N)
   {
      
      N.display(os);
      return os;
   }

   // istream& operator>>(istream& istr, Numbers& N);
   istream &operator>>(istream &istr, Numbers &N)
   {
      
      double value;
      istr >> value;
      if (istr)
      {
         N += value;
      }
      return istr;
   }
}
