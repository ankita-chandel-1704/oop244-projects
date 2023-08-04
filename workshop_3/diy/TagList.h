#ifndef _SDDS_TAGLIST_H_
#define _SDDS_TAGLIST_H_

#include <iostream>
#include <string.h>
#include <iomanip>
#include "NameTag.h"
namespace sdds
{
    class TagList
    {
        NameTag* tags;
        int no_of_tags;
        int current;
        int longest_name;

    public:
        void set();
        void set(int num);
        void add(const NameTag& nt);
        void print();
        void cleanup();
    };
}

#endif