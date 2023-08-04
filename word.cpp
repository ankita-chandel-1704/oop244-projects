#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "word.h"
using namespace std;

namespace sdds
{
    void displayStruct(struct wordStruct w, int num)
    {
        if (num == 0)
        {
            cout << "[" << w.word << "] has [" << w.defNum << "] definitions:\n";
            for (int i = 0; i < w.defNum; i++)
            {
                cout << i + 1 << ". {" << w.typeWord[i] << "} " << w.defination[i] << endl;
            }
        }
        else
        {
            cout << "[" << w.word << "] has multiple definitions:\n";
            for (int i = 0; i < w.defNum; i++)
            {
                cout << i + 1 << ". {" << w.typeWord[i] << "} " << w.defination[i] << endl;

            }
        }
    }
}