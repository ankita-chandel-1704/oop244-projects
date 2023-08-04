#ifndef __SDDS_BASKET_H__
#define __SDDS_BASKET_H__

#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
    struct Fruit
    {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };

    //     Basket Class
    // Design and code a class named Basket that holds information about a fruit basket.

    // Basket Private Members
    // The class should be able to store the following data:

    // a dynamically allocated array of objects of type Fruit. This is the resource that you must manage.
    // the size of the Furits array.
    // the price of the basket.
    // You can add any other private members in the class, as required by your design.

    // Basket Public Members
    // the default constructor
    // a custom constructor that receives as parameters an array of objects of type Fruit, the size of the array received in the fist parameter, and the price of the basket (in this order); stores the parameters into the attributes if all the parameters are valid (the numbers are greater than 0, and the array is not null).
    // the copy constructor (you must do a deep-copy for the resource, and a shallow copy for the other attributes)
    // the copy assignment operator (you must do a deep-copy for the resource, and a shallow copy for the other attributes; note that the copy constructor and copy assignment operator have almost identical logic -- reuse the code)
    // the destructor
    // void setPrice(double price): updates the price attribute to the value received as parameter
    // the conversion to bool operator: returns true if the basket contains any fruits, false otherwise.
    // an overload of the += operator that receives as a parameter an object of type Fruit (by value) and adds it to the dynamic Fruits array (You need to resize the array)
    // Friend Helper Functions
    // overload the insertion operator (operator<<) to insert into the stream (received as the first parameter) the content of an object of type Basket (received as the second parameter).

    // If the basket doesn't contain any fruit, print the message The basket is empty!<ENDL>.

    // If the basket contains fruits, print the content in the format:

    // Basket Content:<ENDL>
    // [FRUIT_1_NAME]: [FRUIT_1_QUANTITY]kg<ENDL>
    // [FRUIT_2_NAME]: [FRUIT_2_QUANTITY]kg<ENDL>
    // ...
    // Price: [BASKET_PRICE]<ENDL>
    // The fruit names should be printed on fields of size 10, aligned to the right; the fruit quantities and basket price should be printed with two significant digits.
    class Basket
    {
        Fruit *m_fruits;
        int m_size;
        double m_price;

    public:
        Basket();
        Basket(Fruit *fruits, int size, double price);
        Basket(const Basket &src);
        Basket &operator=(const Basket &src);
        ~Basket();
        void setPrice(double price);
        operator bool() const;
        Basket &operator+=(Fruit fruit);
        friend std::ostream &operator<<(std::ostream &os, const Basket &basket);
    };

}

#endif