#ifndef DEF_USER
#define DEF_USER

#include <string>

class Address;

class User
{
	protected:
		std::string m_firstName;
		std::string m_lastName;
		Address* m_address;
	
	public:
		User(std::string firstName, std::string lastName, Address* address);
};

#endif
