#ifndef DEF_ROWHISTORY
#define DEF_ROWHISTORY

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class Row;
class Product;
class Separator;

class History
{
	protected:
		std::string m_file;
		std::vector<Product*> m_products;
		std::vector<Separator*> m_separators;

	public:
		History(std::string file);
		void loadHistory();
		void saveHistory();
		//vectors
		void addRow(Row* row);
		void removeProduct(int id);
		void removeSeparator(int id);
		//get-set
		Product* getProduct(int id);
		int getProductNumber();
		Separator* getSeparator(int id);
		int getSeparatorNumber();
};

#endif
