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


#include "ReadWritable.h"

using namespace std;

namespace sdds
{
    ReadWritable::ReadWritable()
    {
        m_commaSeparated = false;
    }

    ReadWritable::ReadWritable(const ReadWritable &src)
    {
        m_commaSeparated = src.m_commaSeparated;
    }

    ReadWritable &ReadWritable::operator=(const ReadWritable &src)
    {
        if (this != &src)
        {
            m_commaSeparated = src.m_commaSeparated;
        }
        return *this;
    }

    ReadWritable::~ReadWritable()
    {
    }

    bool ReadWritable::isCsv() const
    {
        return m_commaSeparated;
    }

    void ReadWritable::setCsv(bool value)
    {
        m_commaSeparated = value;
    }

    std::istream &operator>>(std::istream &istr, ReadWritable &rw)
    {
        return rw.read(istr);
    }

    std::ostream &operator<<(std::ostream &ostr, const ReadWritable &rw)
    {
        return rw.write(ostr);
    }
}
