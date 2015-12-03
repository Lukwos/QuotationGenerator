#ifndef DEF_ADDRESS
#define DEF_ADDRESS

#include <iostream>

class Address
{
	protected:
		int m_number;
		std::string m_street;
		std::string m_postalCode;
		std::string m_city;

	protected:
		Address(int number, std::string street, std::string postalCode, std::string city);
};

#endif
