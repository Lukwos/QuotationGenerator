#include <iostream>

#include "User.hpp"
#include "Client.hpp"
#include "Quotation.hpp"
#include "Product.hpp"
#include "Separator.hpp"
#include "LatexCreator.hpp"

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
	User* user = new User("Prenom", "Nom", NULL);
	Client* client = new Client("Client", "NomClient", NULL, NULL);
	Quotation* q = new Quotation(user, client, 19.6f);
	
	q->addRow(0, new Product(25.0f, 10.0f, "m", "description"));
	q->addRow(1, new Product(10.0f, 9.5f, "U", "une petite description"));
	q->addRow(2, new Separator("Ceci est un separateur"));
	q->addRow(3, new Product(4.5f, 18.4f, "m2", "la toto mobile"));
	q->addRow(4, new Product(1.0f, 12.34f, "ml", "brique de 5"));
	q->removeRow(2);

	LatexCreator* lc = new LatexCreator(std::string(argv[1])+".tex");
	lc->writeQuotation(q);
	lc->compile();

	return 0;
}
