
#include "Line.h"
#include "Utils.h"

namespace sdds{
	Line::Line()
	{
		m_length = 0;
	}

	Line::Line(const char* L_label, int length):LblShape(L_label)
	{
		m_length = length;
	}

	//Line::~Line()
	//{
	//}

	void Line::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
		int length;
		is >> length;
		is.ignore(10000,'\n');
		m_length = length;
	}

	void Line::draw(std::ostream& os) const
	{
		if ((this->m_length > 0) && (this->label())) {
			os << label();
			for (int i = 0; i < m_length-(ut.strlen(label())); i++) {
				os << "=";
			}
			
		}/*
		else {

		}*/
	}




}
