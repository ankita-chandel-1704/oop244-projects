#ifndef __SDDS_MARK_H__
#define __SDDS_MARK_H__

#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
    class Mark
    {
        // Create a C++ Module for a class called Mark to encapsulate a mark between 0 and 100.

        // Mark	Grade	Scale 4 mark
        // 0 <= Mark < 50	F	0.0
        // 50 <= Mark < 60	D	1.0
        // 60 <= Mark < 70	C	2.0
        // 70 <= Mark < 80	B	3.0
        // 80 <= Mark <= 100	A	4.0
        // ⚠️Important: No values are allowed to be kept in a mark out of the range of 0 to 100. In any circumstance and during any function if the value goes below 0 or above 100, the mark is set to an invalid empty state. This rule is to be followed during the workshop and applies to all the functions and operators of class Mark

        int m_mark;

    public:
        // parameterized constructor
        Mark(int mark = 0);
        // type coversions
        // double
        explicit operator double() const;
        // int
        explicit operator int() const;
        // char
        explicit operator char() const;
        // bool
        explicit operator bool() const;
        // Comparison operators
        // A Mark can be compared with other Marks using ==, !=, <, >, <= and >= returning a boolean in result.
        bool operator==(const Mark &RO) const;
        bool operator!=(const Mark &RO) const;
        bool operator<(const Mark &RO) const;
        bool operator>(const Mark &RO) const;
        bool operator<=(const Mark &RO) const;
        bool operator>=(const Mark &RO) const;
        // Unary operators:
        // The ++ and -- operators (postfix and prefix) work with a mark exactly as they do with an integer, except that they don't take any action if the mark is invalid.
        Mark &operator++();
        Mark &operator--();
        // postfix
        Mark operator++(int);
        Mark operator--(int);

        // ~ operator returns true if the mark is a pass
        bool operator~() const;
        // Binary Operators
        // A Mark object can be set to an integer using the assignment operator. If the mark is in an invalid state, the invalid value can be corrected by the assignment.
        Mark &operator=(int value);
        // An integer can be added to the value or deducted from the value of the mark using += and -= operator; if the mark is invalid, the action is omitted. A reference of the mark is returned after the operation.
        Mark &operator+=(int value);
        Mark &operator-=(int value);
        // A mark's value can be added to an integer or deducted from an integer, returning the integer after the operation. Invalid marks will not have any effect on the value of the integer.
        // int+=Mark
        friend int operator+=(int &value, const Mark &RO);
        // int-=Mark
        friend int operator-=(int &value, const Mark &RO);
        // The sum of a Mark and an integer or another Mark will return a Mark with the sum of the two values as a result.
        // Mark+int
        friend Mark operator+(const Mark &LO, int value);
        // Mark+Mark
        friend Mark operator+(const Mark &LO, const Mark &RO);

        // int = int + Mark
        friend int operator+(int value, const Mark RO);

        // << and >> operators move and add the mark value from one mark (source) to another (destination) leaving the source as zero.
        Mark &operator<<(Mark &RO);
        Mark &operator>>(Mark &RO);
    };
}

#endif