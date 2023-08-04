/***********************************************************************
// OOP244 Workshop 2 p2
//name - Ankita Chandel
Email - achandel1@myseneca.ca
student id -
Date - 26 september 2023
***********************************************************************/
#include "Population.h"
using namespace sdds;

int main() {
    
    if (load("PCpopulations.csv")) {
        
        display();
    }
    
    deallocateMemory();
    return 0;
}
