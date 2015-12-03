#include <iostream>

#include "User.hpp"
#include "Client.hpp"
#include "Quotation.hpp"
#include "Product.hpp"
#include "LatexCreator.hpp"

int main(int argc, char* argv[])
{
	for(int i=0; i<argc; i++)
	{
		std::cout << argv[i] << std::endl;
	}

	if(argc != 2)
	{
		std::cout << "must have 1 argument" << std::endl;
		return 1;
	}
	
	//init
	User* user = new User("Prenom", "Nom", NULL);
	Client* client = new Client("Client", "NomClient", NULL, NULL);
	Quotation* q = new Quotation(user, client, 19.6f);
	
	q->addProduct(0, new Product(25.0f, 10.0f, "m", "description"));
	q->addProduct(1, new Product(10.0f, 9.50f, "U", "une petite description"));
	q->addProduct(2, new Product(4.5f, 18.45f, "m2", "la toto mobile"));
	q->addProduct(3, new Product(1.0f, 12.34f, "ml", "brique de 5"));
	
	LatexCreator* lc = new LatexCreator(argv[1]);
	lc->writeQuotation(q);
	lc->compile();

	return 0;
}
