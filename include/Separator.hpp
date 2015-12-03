#ifndef DEF_SEPARATOR
#define DEF_SEPARATOR

#include <string>

#include "Row.hpp"

class Separator : public Row
{
	protected:
		std::string m_title;
	public:
		Separator(std::string title);
		std::string getTitle();
};

#endif
