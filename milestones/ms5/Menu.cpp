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


#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"

using namespace std;

namespace sdds
{
    // menuitem class
    MenuItem::MenuItem(const char *content)
    {
        if (content == nullptr)
        {
            m_content[0] = '\0';
        }
        else
        {
            strncpy(m_content, content, 50);
            m_content[50] = '\0';
        }
    }

    std::ostream &MenuItem::display(std::ostream &os) const
    {
        os << m_content;
        return os;
    }

    // menu class
    Menu::Menu(const char *title, int indentation)
    {
        if (title == nullptr)
        {
            m_title[0] = '\0';
        }
        else
        {
            strncpy(m_title, title, 50);
            m_title[50] = '\0';
        }
        m_indentation = indentation;
        m_noOfItems = 0;
    }

    Menu::operator bool() const
    {
        return m_title[0] != '\0';
    }

    bool Menu::isEmpty() const
    {
        return m_title[0] == '\0';
    }

    std::ostream &Menu::display(std::ostream &os) const
    {
        if (isEmpty())
        {
            os << "Invalid Menu!" << endl;
        }
        else if (m_noOfItems == 0)
        {
            os << m_title << endl;
            os << "No Items to display!" << endl;
        }
        else
        {
            for (int j = 0; j < 4 * m_indentation; j++)
            {
                os << " ";
            }
            os << m_title << endl;
            for (int i = 0; i < m_noOfItems; i++)
            {
                for (int j = 0; j < 4 * m_indentation; j++)
                {
                    os << " ";
                }
                os << i + 1 << "- ";
                m_menuItems[i].display();
                cout << endl;
            }
            for (int j = 0; j < 4 * m_indentation; j++)
            {
                os << " ";
            }
            os << "> ";
        }
        return os;
    }

    Menu &Menu::operator=(const char *title)
    {
        if (title == nullptr)
        {
            m_title[0] = '\0';
        }
        else
        {
            strncpy(m_title, title, 50);
            m_title[50] = '\0';
        }
        return *this;
    }

    void Menu::add(const char *content)
    {
        if (content == nullptr)
        {
            m_title[0] = '\0';
        }
        else if (m_noOfItems < MAX_NO_OF_ITEMS)
        {
            strncpy(m_menuItems[m_noOfItems].m_content, content, 50);
            m_menuItems[m_noOfItems].m_content[50] = '\0';
            m_noOfItems++;
        }
    }

    Menu &Menu::operator<<(const char *content)
    {
        add(content);
        return *this;
    }

    int Menu::run() const
    {
        int selection = 0;

        display();
        if (m_noOfItems == 0)
        {
            // do nothing
            return 0;
        }
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            // If the user enters non-integer value print the following error message: "Invalid Integer, try again: " and wait for the user’s response.
            // If the user enters an integer value that is not in the range of the menu items, print the following error message: "Invalid selection, try again: " and wait for the user’s response.

            while (selection < 1 || selection > m_noOfItems)
            {
                cin >> selection;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid Integer, try again: ";
                }
                else if (selection < 1 || selection > m_noOfItems)
                {
                    cout << "Invalid selection, try again: ";
                }
            }
            cin.ignore(1000, '\n');
        }
        return selection;
    }

    Menu::operator int() const
    {
        return run();
    }

    // void clear();
    void Menu::clear()
    {
        m_title[0] = '\0';
        m_indentation = 0;
        m_noOfItems = 0;
    }
}
