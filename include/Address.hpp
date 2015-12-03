#ifndef DEF_ADDRESS
#define DEF_ADDRESS

#include <string>

class Address
{
	protected:
		int m_number;
		std::string m_street;
		int m_postalCode;
		std::string m_city;

	public:
		Address(int number, std::string street, int postalCode, std::string city);
		//get-set
		int getNumber();
		std::string getStreet();
		int getPostalCode();
		std::string getCity();
};

#endif
