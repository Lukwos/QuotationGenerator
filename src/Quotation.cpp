#include <iostream> //debug
#include "Quotation.hpp"
	
Quotation::Quotation(User* user, Client* client, float tax)
	: m_user(user), m_client(client), m_tax(tax)
{
}

void Quotation::addProduct(int id, Product* product)
{
	m_products[id] = product;
}

void Quotation::removeProduct(int id)
{
	m_products.erase(id);
}

Product* Quotation::getProduct(int id)
{
	return m_products.at(id);
}

int Quotation::getMaxId()
{
	return m_products.size();
}

float Quotation::getTax()
{
	return m_tax;
}
