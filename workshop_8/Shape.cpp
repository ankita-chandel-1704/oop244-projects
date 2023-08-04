#include <iostream>
#include "Shape.h"
#include "Utils.h"

namespace sdds {
	
	//Shape& operator<<(const Shape& LHS, std::ostream& os) {
	//	LHS.draw(os);
	//	//return RHS;
	//};

	//Shape& operator>>(Shape& LHS, std::istream& is) {
	//	LHS.getSpecs(is);

	//};


	std::ostream& operator<<(std::ostream& os, const Shape& RHS)
	{
		RHS.draw(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, Shape& RHS)
	{
		RHS.getSpecs(is);
		return is;
		
	}

}