#pragma once
#ifndef _SDDS_RECTANGLE_H_
#define _SDDS_RECTANGLE_H
#include "LblShape.h"

namespace sdds {
	class Rectangle :public LblShape {
	private:
		int m_width;
		int m_height;

	public:
		Rectangle();
		Rectangle(const char* R_label, int width, int height);
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;

	};



}


#endif // !_SDDS_RECTANGLE_H_
