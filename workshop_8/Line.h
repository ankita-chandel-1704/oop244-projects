#pragma once
#ifndef _SDDS_LINE_H_
#define _SDDS_LINE_H_
#include "LblShape.h"

namespace sdds {
	
	class Line :public LblShape {
	private:	
		int m_length;

	public:
		Line();
		Line(const char* L_label, int length);
		//virtual ~Line();
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};

	std::ostream& operator<<(std::ostream& os, const Shape& RHS);
	std::istream& operator>>(std::istream& is, Shape& RHS);

}



#endif // !_SDDS_LINE_H_
