#define _CRT_SECURE_NO_WARNINGS
#include "Population.h"
#include "File.h"
#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
namespace sdds
{

	struct Population
	{
		char postcode[4];
		                         // Population Struct
                                   		// contains postcode and population

		int population;
	};

	// A dynamic array to store a list of populations
	Population* populationList = nullptr;
	int count;
	bool load(const char fileupload[])
	{
		bool ok = false;
		int num_of_rec = 0;
		if (openFile(fileupload))
		{
			num_of_rec = noOfRecords();
			populationList = new Population[num_of_rec];
			int i;
			for (i = 0; i < num_of_rec; i++)
			{
				// use read function to read the data from the file
				// and store it in the dynamic array
				int population;
				char postcode[4];
				if (read(postcode) && read(population))
				{
					populationList[i].population = population;
					strcpy(populationList[i].postcode, postcode);
					ok = true;
				}
				else
				{
					cout << "Error : incorrect number of records read; the data is possibly corrupted!" << endl;
					ok = false;
					break;
				}
			}
			if (i != num_of_rec)
			{
				delete[] populationList;
				return false;
			}
			count = num_of_rec;
		}
		else
		{
			cout << "Could not open data file : " << fileupload << endl;
			return false;
		}
		return true;
	}

	
	void display()
	{
		// sort the data in ascending order of the population
		
		
		
		for (int i = 0; i < count; i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				if (populationList[i].population > populationList[j].population)
				{
					Population temp = populationList[i];
					populationList[i] = populationList[j];
					populationList[j] = temp;
				}
			}
		}
		
		
		
		
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;
		
		
		
		
		
		
		
		
		
		
		int total = 0;
		
		
		
		for (int i = 0; i < count; i++)
		{
			cout << i + 1 << "- " << populationList[i].postcode << ":  " << populationList[i].population << endl;
			total += populationList[i].population;
		}
		

		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << total << endl;
	}

	// deallocateMemory
	// a function with no parameters that returns nothing and deallocates the memory that was allocated dynamically in the load function

	void deallocateMemory()
	{
		delete[] populationList;
		closeFile();
	}

}