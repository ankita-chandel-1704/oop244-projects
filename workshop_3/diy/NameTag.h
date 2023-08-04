#ifndef _SDDS_NAMETAG_H_
#define _SDDS_NAMETAG_H_

#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
    class NameTag
    {
        char name[51];

    public:
        NameTag();
        NameTag(const char* name);
        void set(const char* name);
        char* getName() const;
    };
}

#endif