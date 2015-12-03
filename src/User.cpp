#include "User.hpp"

User::User(std::string firstName, std::string lastName, Address* address)
	: m_firstName(firstName), m_lastName(lastName), m_address(address)
{
}
