#include "Quotation.hpp"
	
Quotation::Quotation(User* user, Client* client, float tax)
	: m_user(user), m_client(client), m_tax(tax)
{
}

void Quotation::addRow(int id, Row* row)
{
	if(m_rows.find(id) == m_rows.end())
	{
		m_rows[id] = row;
	}
	else
	{
		m_rows[m_rows.size()] = row;
		for(int i=(int)m_rows.size()-1; i>id; i--)
		{
			swapRows(i, i-1);
		}
	}
}

void Quotation::removeRow(int id)
{
	//move the row in the top
	for(int i=id; i<(int)m_rows.size()-1; i++)
	{
		swapRows(i, i+1);
	}
	m_rows.erase(m_rows.size()-1);
}

void Quotation::swapRows(int id1, int id2)
{
	Row* tmp = m_rows.at(id1);
	m_rows[id1] = m_rows.at(id2);
	m_rows[id2] = tmp;
}

User* Quotation::getUser()
{
	return m_user;
}

Client* Quotation::getClient()
{
	return m_client;
}

Row* Quotation::getRow(int id)
{
	return m_rows.at(id);
}

int Quotation::getMaxId()
{
	return m_rows.size();
}

float Quotation::getTax()
{
	return m_tax;
}
