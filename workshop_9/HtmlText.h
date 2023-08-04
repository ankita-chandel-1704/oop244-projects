

#ifndef SDDS_HtmlText_H
#define SDDS_HtmlText_H
#include "Text.h"

namespace sdds
{
	class HtmlText : public Text {
	private:
      char* m_title{};
	public:
		HtmlText();
		HtmlText(const char* content);

		~HtmlText();
		HtmlText(const HtmlText* htmlText);
		HtmlText& operator=(const HtmlText& htmlText);

	    std::ostream& write(std::ostream& os) const override;

		friend std::ostream& operator<<(std::ostream& is, const HtmlText& htmlText);
		friend std::istream& operator>>(std::istream& is, HtmlText& htmlText);
	};
}

#endif