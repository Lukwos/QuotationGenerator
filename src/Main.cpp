#include "User.hpp"
#include "Client.hpp"
#include "Address.hpp"
#include "Quotation.hpp"
#include "Product.hpp"
#include "Separator.hpp"
#include "LatexCreator.hpp"
#include "History.hpp"

int main(int argc, char* argv[])
{
	std::cout << "-----INPUT-----" << std::endl;
	for(int i=0; i<argc; i++)
	{
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl << "---------------" << std::endl;

	if(argc != 2)
	{
		std::cout << "must have 1 argument" << std::endl;
		return 1;
	}
	
	//init
	History* history = new History("History");
	Address* addr = new Address(9, "impasse du pont des noelles", 22600, "Loudeac");
	User* user = new User("Prenom", "Nom", addr);
	Client* client = new Client("Client", "NomClient", addr, addr);
	Quotation* q = new Quotation(user, client, 19.6f);
	history->loadHistory();
	history->saveHistory();
	for(int i=0; i<history->getProductNumber(); i++)
	{
		q->addRow(i, history->getProduct(i));
	}
	LatexCreator* lc = new LatexCreator(std::string(argv[1])+".tex");
	lc->writeQuotation(q);
	lc->compile();

	return 0;
}
