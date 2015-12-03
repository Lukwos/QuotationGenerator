#ifndef DEF_ENTRY
#define DEF_ENTRY

#include <string>

#include "Row.hpp"

class Product : public Row
{
	protected:
		float m_price;
		float m_quantity;
		std::string m_unit;
		std::string m_description;

	public:
		Product(float price, float quantity, std::string unit, std::string description);
		//get-set
		float getPrice();
		float getQuantity();
		std::string getUnit();
		std::string getDescription();
};

#endif

