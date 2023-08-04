#ifndef SHOPPINGLIST_H // replace with relevant names
#define SHOPPINGLIST_H
#include <cstdio>

#include <iostream>
#include <cstdlib>
using namespace std;

namespace sdds
{




	// Your header file content goes here
	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();




}

#endif

