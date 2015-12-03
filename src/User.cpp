#include "User.hpp"

User::User(std::string firstName, std::string lastName, Address* address)
	: m_firstName(firstName), m_lastName(lastName), m_address(address)
{
}

std::string User::getFirstName()
{
	return m_firstName;
}

std::string User::getLastName()
{
	return m_lastName;
}

Address* User::getAddress()
{
	return m_address;
}
