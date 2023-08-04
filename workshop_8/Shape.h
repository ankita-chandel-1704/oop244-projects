#pragma once
#ifndef _SDDS_SHAPE_H_
#define _SDDS_SHAPE_H_
#include <iostream> 

namespace sdds{

	class Shape {//interface
	public:
		virtual ~Shape(){};
		virtual void draw(std::ostream& os) const = 0;
		virtual void getSpecs(std::istream& is) = 0;
		
	};
	
	//Shape& operator<<(const Shape& RHS , std::ostream& os);//
	//Shape& operator>>(Shape& RHS, std::istream& is);//
	std::ostream& operator<<(std::ostream& os, const Shape& RHS);
	std::istream& operator>>(std::istream& is, Shape& RHS);
}


#endif // !_SDDS_SHAPE_H_
