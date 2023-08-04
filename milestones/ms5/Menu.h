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


#ifndef __SDDS_MENU_H__
#define __SDDS_MENU_H__

#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
    // Create a fully private class (no public members) called MenuItem that is owned by the Menu class. (i.e. Menu is a friend of MenuItem).

    // To make this possible (since Menu is not yet implemented), forward declare the Menu class to be able to make it a friend of MenuItem class.

    // MenuItem can hold a C-style character string with a maximum length of 50 as its content. Any attempt to set the content to more than 50 characters should store the truncated value instead (down to 50 characters).

    // forward declare the Menu class
    class Menu;

    class MenuItem
    {
        char m_content[51];
        friend class Menu;
        // constructor
        MenuItem(const char *content = nullptr);
        // display
        std::ostream &display(std::ostream &os = std::cout) const;
        // Copy and Assignment:
        // MenuItem can not get copied or assigned to another MenuItem. This, must be enforced in your code.
        MenuItem(const MenuItem &src) = delete;
        MenuItem &operator=(const MenuItem &src) = delete;
    };

    const int MAX_NO_OF_ITEMS = 10;

    class Menu
    {
        char m_title[51];
        MenuItem m_menuItems[MAX_NO_OF_ITEMS];
        int m_noOfItems;
        int m_indentation;

    public:
        // A Menu object can be created by a constant C-style character string, to be used to set its title and an optional integer value for indentation. If indentation is not provided, the value “0” will be passed instead.
        Menu(const char *title = nullptr, int indentation = 0);
        // Menu can not get copied or assigned to another Menu. This, must be enforced in your code.
        Menu(const Menu &src) = delete;
        Menu &operator=(const Menu &src) = delete;
        // bool cast overload
        operator bool() const;
        // isEmpty() function
        bool isEmpty() const;
        // display function
        std::ostream &display(std::ostream &os = std::cout) const;
        // Assignment
        // A Menu should be able to be assigned to a constant character C-string.
        Menu &operator=(const char *title);
        // add function:
        // write an add function that returns nothing and receives a constant character C-string to build a MenuItem and add it to the MenuItems of the Menu.
        void add(const char *content);
        // left shift operator overload (“<<”)
        // Overload the left shift operator to insert a constant character C-string into the Menu as a MenuItem.
        Menu &operator<<(const char *content);
        // Create a function called run that returns an integer. In this function displays the Menu and waits for the user’s response to select an option by entering the row number of the MenuItems.
        int run() const;
        // Integer cast overload
        operator int() const;
        // clear function
        void clear();
    };
}

#endif