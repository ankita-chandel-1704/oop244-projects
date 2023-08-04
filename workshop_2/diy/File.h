/***********************************************************************
// OOP244 Workshop 2 p2
//name - Ankita Chandel
Email - achandel1@myseneca.ca
student id - 
Date - 26 september 2023
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds
{
	// Opens a file and keeps the file pointer in the File.cpp (file scope)
	bool openFile(const char fileupload[]);
	// Closes the open file
	void closeFile();
	// Finds the records kept in the file to be used for the dynamic memory allocation
	
	int noOfRecords();
	
	bool read(char* cstr);
	bool read(int& value);

}
#endif // !SDDS_FILE_H_
