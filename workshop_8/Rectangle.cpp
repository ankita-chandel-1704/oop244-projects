#define _CRT_SECURE_NO_WARNINGS
#include "Rectangle.h"
#include "Utils.h"

namespace sdds {

	Rectangle::Rectangle()
	{
		m_height = 0;
		m_width = 0;
	}

	Rectangle::Rectangle(const char* R_label, int width, int height) :LblShape(R_label)
	{
		if (height < 3 || width < (ut.strlen(R_label)+ 2)) {
			m_height = 0;
			m_width = 0;
		}
		else {
			m_width = width;
			m_height = height;
		}
	}

void Rectangle::getSpecs(std::istream& is)
{
	LblShape::getSpecs(is);
	int t_width, t_height;
	is >> t_width;
	is.ignore(1000,',');
	is >> t_height;
	is.ignore(1000, '\n');
	m_width = t_width;
	m_height = t_height;
}

void Rectangle::draw(std::ostream& os) const
{
	if (m_height != 0 || m_width != 0) {
		os << "+";//first line
		for (int i = 0; i < m_width - 2; i++) {
			os << "-";
		}
		os << "+"<<std::endl;
		//second line
		os << "|";
		os.width(m_width-2);
		os.setf(std::ios::left);
		os << label();
		os.unsetf(std::ios::left);
		os << "|"<< std::endl;
		//lines
		for (int j = 0; j < m_height - 3; j++) {
			os << "|";
			for (int i = 0; i < m_width - 2; i++) {
				os << " ";
			}
			os << "|"<< std::endl;
		}
		//last lines
		os << "+";
		for (int i = 0; i < m_width - 2; i++) {
			os << "-";
		}
		os << "+";
	}
}


}
