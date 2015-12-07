#include "History.hpp"
#include "Product.hpp"

//Idee : Historique XML ?

History::History(std::string file)
	: m_file(file)
{
}

void History::loadHistory()
{
	std::ifstream file(m_file);
	std::string line;
	int state = 0;
	//state 0 = NULL
	//state 1 = Users
	//state 2 = Clients
	//state 3 = Products
	//state 4 = Separators
	while(std::getline(file, line))
	{
		//State IDs
		if(line == "Users:")
		{
			state = 1;
		}
		else if(line == "Clients:")
		{
			state = 2;
		}
		else if(line == "Products:")
		{
			state = 3;
		}
		else if(line == "Separators:")
		{
			state = 4;
		}
		// State Handlers
		else if(state==1)
		{	
		}
		else if(state==2)
		{
		}
		else if(state==3)
		{
			std::stringstream ss(line);
			std::string description;
			std::string  strPrice;
			float price;
			std::string unit;
			getline(ss, description, '\t');
			getline(ss, strPrice, '\t');
			getline(ss, unit, '\t');
			price = std::stof(strPrice);
			m_products.push_back(new Product(price, 0, unit, description));
		}
		else if(state==4)
		{
		}
	}
}

void History::saveHistory()
{
	std::ofstream file;
	file.open(m_file);

	file << "Users:\n";
	file << "Clients:\n";
	file << "Products:\n";
	for(int i=0; i<(int)m_products.size(); i++)
	{
		file << m_products[i]->getDescription() << "\t";
		file << m_products[i]->getPrice() << "\t";
		file << m_products[i]->getUnit() << "\n";
	}
	file << "Separators:\n";

	file.close();
}

void History::addRow(Row* row)
{
	//dynamic_cast
}

void History::removeProduct(int id)
{
	m_products.erase(m_products.begin() + id);
}

void History::removeSeparator(int id)
{
	m_separators.erase(m_separators.begin() + id);
}

Product* History::getProduct(int id)
{
	return m_products[id];
}

Separator* History::getSeparator(int id)
{
	return m_separators[id];
}

int History::getProductNumber()
{
	return m_products.size();
}

int History::getSeparatorNumber()
{
	return m_separators.size();
}
