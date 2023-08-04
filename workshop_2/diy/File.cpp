/***********************************************************************
// OOP244 Workshop 2 p2
//name - Ankita Chandel
Email - achandel1@myseneca.ca
student id -
Date - 26 september 2023
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>
#include "File.h"

namespace sdds
{
    FILE* fptr;
    
    bool openFile(const char fileupload[])
    {
        fptr = fopen(fileupload,"r");
        return fptr != NULL;
    }
    
    int noOfRecords()
    {
        int num_of_rec = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1)
        {
            num_of_rec += (ch == '\n');
        }
        rewind(fptr);
        return num_of_rec;
    }
    // Closes the open file
    void closeFile()
    {
        if (fptr)
            fclose(fptr);
    }

    bool read(int& value)
    {
        bool ok = false;
        if (fptr != nullptr)
        {
            // read comma
            fscanf(fptr, ",");
            ok = fscanf(fptr, "%d", &value) == 1;
        }
        return ok;
    }
    bool read(char* cstr)
    {
        bool ok = false;
        if (fptr != nullptr)
        {
            fscanf(fptr, "\r\n");
            ok = fscanf(fptr, "%4[^,]", cstr) == 1;
        }
        if (cstr[strlen(cstr) - 1] == '\r')
        {
            cstr[strlen(cstr) - 1] = '\0';
        }
        return ok;
    }

}