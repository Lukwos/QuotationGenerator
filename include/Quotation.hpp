#ifndef DEF_QUOTATION
#define DEF_QUOTATION

#include <map>

class User;
class Client;
class Row;

class Quotation
{
	protected:
		User* m_user;
		Client* m_client;
		float m_tax;
		int m_id;
		std::map<int, Row*> m_rows;
	
	public:
		Quotation(User* user, Client* client, float tax, int id);
		//transform map
		//TODO Need Optimisation
		void addRow(int id, Row* row);
		void removeRow(int id);
		void swapRows(int id1, int id2);
		//get-set
		User* getUser();
		Client* getClient();
		int getId();
		Row* getRow(int id);
		int getMaxId();
		float getTax();
};

#endif
