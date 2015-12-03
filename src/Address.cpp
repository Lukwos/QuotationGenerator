#include "Address.hpp"

Address::Address(int number, std::string street, std::string postalCode, std::string city)
	: m_number(number), m_street(street), m_postalCode(postalCode), m_city(city)
{
}
