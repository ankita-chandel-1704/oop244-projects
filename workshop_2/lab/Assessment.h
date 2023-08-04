#ifndef __SDDS_ASSESSMENT_H__
#define __SDDS_ASSESSMENT_H__

#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
    struct Assessment
    {
        double* m_mark;
        char* m_title;
    };

    bool read(int& value, FILE* fptr);
    bool read(double& value, FILE* fptr);
    bool read(char* cstr, FILE* fptr);
    bool read(Assessment& asmnt, FILE* fptr);
    void freeMem(Assessment*& aptr, int size);
    int read(Assessment*& aptr, FILE* fptr);

}

#endif