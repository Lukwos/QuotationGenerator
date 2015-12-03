#include "Client.hpp"

Client::Client(std::string firstName, std::string lastName, Address* homeAddress, Address* workAddress)
	: m_firstName(firstName), m_lastName(lastName), m_homeAddress(homeAddress), m_workAddress(workAddress)
{
}
