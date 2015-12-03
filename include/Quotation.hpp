#ifndef DEF_QUOTATION
#define DEF_QUOTATION

#include <map>

class User;
class Client;
class Product;

class Quotation
{
	protected:
		User* m_user;
		Client* m_client;
		float m_tax;
		std::map<int, Product*> m_products;
	
	public:
		Quotation(User* user, Client* client, float tax);
		//transform map
		void addProduct(int id, Product* product);
		void removeProduct(int id);
		//get-set
		int getMaxId();
		float getTax();
		Product* getProduct(int id);
};

#endif
