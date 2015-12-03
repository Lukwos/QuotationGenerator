#include "Separator.hpp"

Separator::Separator(std::string title)
	: Row(), m_title(title)
{
}

std::string Separator::getTitle()
{
	return m_title;
}
