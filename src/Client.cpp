#include "Client.hpp"

Client::Client(std::string firstName, std::string lastName, Address* homeAddress, Address* workAddress)
	: m_firstName(firstName), m_lastName(lastName), m_homeAddress(homeAddress), m_workAddress(workAddress)
{
}

std::string Client::getFirstName()
{
	return m_firstName;
}

std::string Client::getLastName()
{
	return m_lastName;
}

Address* Client::getHomeAddress()
{
	return m_homeAddress;
}

Address* Client::getWorkAddress()
{
	return m_workAddress;
}
