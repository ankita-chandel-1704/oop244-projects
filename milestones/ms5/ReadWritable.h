
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

#ifndef __SDDS_READWRITABLE_H__
#define __SDDS_READWRITABLE_H__

#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
    class ReadWritable
    {
        bool m_commaSeparated;

    public:
        ReadWritable();
        // copy constructor
        ReadWritable(const ReadWritable &src);
        // copy assignment operator
        ReadWritable &operator=(const ReadWritable &src);
        virtual ~ReadWritable();
        bool isCsv() const;
        void setCsv(bool value);
        virtual std::istream &read(std::istream &istr = std::cin) = 0;
        virtual std::ostream &write(std::ostream &ostr = std::cout) const = 0;

        // operator overloads
        friend std::istream &operator>>(std::istream &istr, ReadWritable &rw);
        friend std::ostream &operator<<(std::ostream &ostr, const ReadWritable &rw);
    };
}

#endif