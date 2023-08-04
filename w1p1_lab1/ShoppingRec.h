#ifndef SHOPPINGREC_H // replace with relevant names
#define SHOPPINGREC_H
#include <iostream>
#include <cstdlib>
using namespace std;


namespace sdds
{
	const int MAX_TITLE_LENGTH = 50;


	// Your header file content goes here
	struct ShoppingRec
	{
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};


	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);

}
#endif
