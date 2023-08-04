
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Text.h"

using namespace std;

namespace sdds
{
	
	Text::Text()
	{
		m_content = nullptr;
	}


	Text::Text(const Text& text)
	{
		if (text.m_content != nullptr) {
			m_content = new char[strlen(text.m_content) + 1];
			strcpy(m_content, text.m_content);
		}
	}

	Text::~Text() {
		delete[] m_content;
	}


	Text& Text::operator=(const Text& text)
	{
		if (m_content != nullptr) {
			delete[] m_content;
			m_content = nullptr;
		}
		m_content = new char[strlen(text.m_content) + 1];
		strcpy(m_content, text.m_content);
		return *this;
	}


	const char& Text::operator[](int index) const
	{
		return m_content[index];
	}
	

	std::ostream& Text::write(std::ostream& os) const {
		if (m_content != nullptr) {
			os << m_content;
		}
		return os;
	}

	std::istream& Text::read(std::istream& is) {
		unsigned len = getFileLength(is);
		delete[] m_content;
		m_content = new char[len + 1];
		int i = 0;
		char ch;
		is.clear();
		is.seekg(0, ios::beg);
		while (is >> noskipws >> ch) {
			m_content[i++] = ch;
		}
		m_content[i] = '\0';
		return is;
	}

	std::istream& operator>>(std::istream& in, Text& text) {
		return text.read(in);
	}
	std::ostream& operator<<(std::ostream& os, const Text& text) {
		return text.write(os);
	}

	unsigned Text::getFileLength(istream& is)
	{
		unsigned len{};
		is.clear();
		is.seekg(0, ios::beg);
		if (is) {
			std::streampos cur = is.tellg();
			is.seekg(0, ios::end);
			len = unsigned(is.tellg());
			is.seekg(cur);
		}
		return len;
	}
}
