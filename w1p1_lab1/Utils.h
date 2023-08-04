#ifndef UTILS_H // replace with relevant names
#define UTILS_H
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
namespace sdds
{


	// Your header file content goes here
	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);

}
#endif