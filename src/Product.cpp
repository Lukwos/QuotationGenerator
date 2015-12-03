#include "Product.hpp"

Product::Product(float price, float quantity, std::string unit, std::string description)
	: m_price(price), m_quantity(quantity), m_unit(unit), m_description(description)
{
}

float Product::getPrice()
{
	return m_price;
}

float Product::getQuantity()
{
	return m_quantity;
}

std::string Product::getUnit()
{
	return m_unit;
}

std::string Product::getDescription()
{
	return m_description;
}

