#define _CRT_SECURE_NO_WARNINGS
#include "Assessment.h"

using namespace std;

namespace sdds
{
    //     bool read(int& value, FILE* fptr);
    // Reads one integer from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false

    bool read(int& value, FILE* fptr)
    {
        bool ok = false;
        if (fptr != nullptr)
        {
            ok = fscanf(fptr, "%d", &value) == 1;
        }
        return ok;
    }

    //     bool read(double& value, FILE* fptr);
    // Reads one double from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false

    bool read(double& value, FILE* fptr)
    {
        bool ok = false;
        if (fptr != nullptr)
        {
            ok = fscanf(fptr, "%lf", &value) == 1;
        }
        return ok;
    }

    //     bool read(char* cstr, FILE* fptr);
    // Skips a comma and then reads a cstring no longer than 60 characters from the fptr file into the address, cstr and returns true if it was successful, otherwise, it will return false

    bool read(char* cstr, FILE* fptr)
    {
        bool ok = false;
        if (fptr != nullptr)
        {
            fscanf(fptr, ",");
            ok = fscanf(fptr, "%60[^\n]", cstr) == 1;
        }
        if (cstr[strlen(cstr) - 1] == '\r')
        {
            cstr[strlen(cstr) - 1] = '\0';
        }
        return ok;
    }

    //     bool read(Assessment& asmnt, FILE* fptr);
    // First it will try to read a double value for the mark and a string for title into a temporary local double variable and a 60 character lone cString (+1 for null).

    // If the read is successful, it will then allocate a dynamic double and a dynamic cString to the exact size of the read cstring from the file into the fields of the asmnt structure (asmnt.m_mark and asmnt.m_title) and copies the values into them.
    // In this case, the function will return true, otherwise, it will return false with no memory allocation.

    bool read(Assessment& asmnt, FILE* fptr)
    {
        bool ok = false;
        if (fptr != nullptr)
        {
            double tempMark;
            char* tempTitle = new char[61];
            if (read(tempMark, fptr) && read(tempTitle, fptr))
            {
                asmnt.m_mark = new double;
                asmnt.m_title = new char[strlen(tempTitle) + 1];
                *asmnt.m_mark = tempMark;
                strcpy(asmnt.m_title, tempTitle);
                ok = true;
            }
            delete[] tempTitle;
        }
        return ok;
    }

    //     void freeMem(Assessment*& aptr, int size);
    // This function will receive a reference of a dynamic Assessment array and its size. The function then will delete the dynamic Assessment array as follows:

    // The dynamic array will be deleted by first going through each element of the Assessment array in a loop, deleting the dynamic double and the dynamic cString of all Assessment elements and then it will delete the array itself.

    void freeMem(Assessment*& aptr, int size)
    {
        if (aptr != nullptr)
        {
            for (int i = 0; i < size; i++)
            {
                delete aptr[i].m_mark;
                delete[] aptr[i].m_title;
            }
            delete[] aptr;
            aptr = nullptr;
        }
    }

    //     int read(Assessment*& aptr, FILE* fptr);
    // This read function receives a reference of an Assessment pointer (to hold a dynamic array) and a file pointer from which it will read the assessment records into a newly allocated dynamic array.

    // The function will first read one integer which is the number of upcoming records to read.

    // Then it will allocate a dynamic array of Assessments in the aptr pointer reference. After allocating the memory, in a loop, it will read each record of the file into the Assessment elements (use the proper read overload for this). This loop should stop either if the number of reads reaches the number of elements or if the read function fails.

    // When the loop is done compare the number of reads to the number of elements of the array. If the number is not a match, free the Memory of the dynamic array (freeMem) and return zero, otherwise, return the size of the array.

    int read(Assessment*& aptr, FILE* fptr)
    {
        int size = 0;
        if (fptr != nullptr)
        {
            int num;
            read(num, fptr);
            aptr = new Assessment[num];
            for (int i = 0; i < num; i++)
            {
                if (!read(aptr[i], fptr))
                {
                    freeMem(aptr, size);
                    return 0;
                }
                size++;
            }
        }
        return size;
    }
}