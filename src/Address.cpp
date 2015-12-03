#include "Address.hpp"

Address::Address(int number, std::string street, int postalCode, std::string city)
	: m_number(number), m_street(street), m_postalCode(postalCode), m_city(city)
{
}

int Address::getNumber()
{
	return m_number;
}

std::string Address::getStreet()
{
	return m_street;
}

int Address::getPostalCode()
{
	return m_postalCode;
}

std::string Address::getCity()
{
	return m_city;
}

