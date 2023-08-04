#include "Mark.h"

using namespace std;

namespace sdds
{
    // Mark	Grade	Scale 4 mark
    // 0 <= Mark < 50	F	0.0
    // 50 <= Mark < 60	D	1.0
    // 60 <= Mark < 70	C	2.0
    // 70 <= Mark < 80	B	3.0
    // 80 <= Mark <= 100	A	4.0

    Mark::Mark(int mark)
    {
        if (mark >= 0 && mark <= 100)
        {
            m_mark = mark;
        }
        else
        {
            m_mark = -1;
        }
    }

    Mark::operator double() const
    {
        if (m_mark >= 0 && m_mark <= 100)
        {
            // return gpa
            if (m_mark < 50)
            {
                return 0.0;
            }
            else if (m_mark < 60)
            {
                return 1.0;
            }
            else if (m_mark < 70)
            {
                return 2.0;
            }
            else if (m_mark < 80)
            {
                return 3.0;
            }
            else
            {
                return 4.0;
            }
        }
        else
        {
            return 0;
        }
    }

    Mark::operator int() const
    {
        if (m_mark != -1)
        {
            return m_mark;
        }
        else
        {
            return 0;
        }
    }

    Mark::operator char() const
    {
        char grade = 'X';
        if (m_mark >= 0 && m_mark < 50)
        {
            grade = 'F';
        }
        else if (m_mark >= 50 && m_mark < 60)
        {
            grade = 'D';
        }
        else if (m_mark >= 60 && m_mark < 70)
        {
            grade = 'C';
        }
        else if (m_mark >= 70 && m_mark < 80)
        {
            grade = 'B';
        }
        else if (m_mark >= 80 && m_mark <= 100)
        {
            grade = 'A';
        }
        return grade;
    }

    Mark::operator bool() const
    {
        return m_mark >= 0 && m_mark <= 100;
    }

    bool Mark::operator==(const Mark &RO) const
    {
        return m_mark == RO.m_mark;
    }

    bool Mark::operator!=(const Mark &RO) const
    {
        return m_mark != RO.m_mark;
    }

    bool Mark::operator<(const Mark &RO) const
    {
        return m_mark < RO.m_mark;
    }

    bool Mark::operator>(const Mark &RO) const
    {
        return m_mark > RO.m_mark;
    }

    bool Mark::operator<=(const Mark &RO) const
    {
        return m_mark <= RO.m_mark;
    }

    bool Mark::operator>=(const Mark &RO) const
    {
        return m_mark >= RO.m_mark;
    }

    Mark &Mark::operator++()
    {
        if (m_mark >= 0 && m_mark <= 100)
        {
            m_mark++;
        }
        return *this;
    }

    Mark &Mark::operator--()
    {
        if (m_mark >= 0 && m_mark <= 100)
        {
            m_mark--;
        }
        return *this;
    }

    Mark Mark::operator++(int)
    {
        Mark temp = *this;
        if (m_mark >= 0 && m_mark <= 100)
        {
            m_mark++;
        }
        return temp;
    }

    Mark Mark::operator--(int)
    {
        Mark temp = *this;
        if (m_mark >= 0 && m_mark <= 100)
        {
            m_mark--;
        }
        return temp;
    }

    bool Mark::operator~() const
    {
        return m_mark >= 50 && m_mark <= 100;
    }
    // A Mark object can be set to an integer using the assignment operator.
    Mark &Mark::operator=(int mark)
    {
        m_mark = mark;

        return *this;
    }

    // An integer can be added to the value or deducted from the value of the mark using += and -= operator; if the mark is invalid, the action is omitted. A reference of the mark is returned after the operation.
    Mark &Mark::operator+=(int mark)
    {
        if (m_mark >= 0 && m_mark <= 100)
        {
            m_mark += mark;
            if (m_mark > 100)
            {
                m_mark = 100;
            }
        }
        return *this;
    }

    Mark &Mark::operator-=(int mark)
    {
        if (m_mark >= 0 && m_mark <= 100)
        {
            m_mark -= mark;
            if (m_mark < 0)
            {
                m_mark = 0;
            }
        }
        return *this;
    }
    // int+=Mark
    // friend int operator+=(int &value, const Mark &RO);]
    int operator+=(int &value, const Mark &RO)
    {
        if (RO.m_mark >= 0 && RO.m_mark <= 100)
        {
            value += RO.m_mark;
            // if (value > 100)
            // {
            //     value = 100;
            // }
        }
        return value;
    }
    // int-=Mark
    // friend int operator-=(int &value, const Mark &RO);
    int operator-=(int &value, const Mark &RO)
    {
        if (RO.m_mark >= 0 && RO.m_mark <= 100)
        {
            value -= RO.m_mark;
            // if (value < 0)
            // {
            //     value = 0;
            // }
        }
        return value;
    }
    // The sum of a Mark and an integer or another Mark will return a Mark with the sum of the two values as a result.
    // Mark+int
    // friend Mark operator+(const Mark &LO, int value);
    Mark operator+(const Mark &LO, int value)
    {
        Mark temp = LO;
        if (LO.m_mark >= 0 && LO.m_mark <= 100)
        {
            temp.m_mark += value;
            // if (temp.m_mark > 100)
            // {
            //     temp.m_mark = 100;
            // }
        }
        return temp;
    }
    // Mark+Mark
    // friend Mark operator+(const Mark &LO, const Mark &RO);
    Mark operator+(const Mark &LO, const Mark &RO)
    {
        Mark temp = LO;
        if (LO.m_mark >= 0 && LO.m_mark <= 100)
        {
            temp.m_mark += RO.m_mark;
            // if (temp.m_mark > 100)
            // {
            //     temp.m_mark = 100;
            // }
        }
        return temp;
    }

    // Mark &operator>>(Mark &RO);

    Mark &Mark::operator>>(Mark &RO)
    {
        if (RO.m_mark >= 0 && RO.m_mark <= 100)
        {
            RO.m_mark += m_mark;
            m_mark = 0;
            if (RO.m_mark > 100)
            {
                RO.m_mark = 100;
            }
        }
        return *this;
    }

    // Mark &operator<<(Mark &RO);

    Mark &Mark::operator<<(Mark &RO)
    {
        if (RO.m_mark >= 0 && RO.m_mark <= 100)
        {
            m_mark += RO.m_mark;
            RO.m_mark = 0;
            if (m_mark > 100)
            {
                m_mark = 100;
            }
        }
        return *this;
    }

    //  friend int operator+(int &value, const Mark &RO);
    int operator+(int value, const Mark RO)
    {
        if (RO.m_mark >= 0 && RO.m_mark <= 100)
        {
            value += RO.m_mark;
            // if (value > 100)
            // {
            //     value = 100;
            // }
        }
        return value;
    }
}
