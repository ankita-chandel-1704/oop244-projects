
#ifndef FILE_H // replace with relevant names
#define FILE_H
#include <iostream>
#include <cstdlib>
#include "ShoppingList.h"


#include "ShoppingRec.h"

#include "Utils.h"
using namespace std;


namespace sdds
{
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
	// Your header file content goes here


}
#endif
