#ifndef DEF_CLIENT
#define DEF_CLIENT

#include <iostream>

class Address;

class Client
{
	protected:
		std::string m_firstName;
		std::string m_lastName;
		Address* m_homeAddress;
		Address* m_workAddress;
	
	public:
		Client(std::string firstName, std::string lastName, Address* homeAddress, Address* workAdress);

};

#endif
