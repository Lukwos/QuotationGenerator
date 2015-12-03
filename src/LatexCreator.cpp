#include "LatexCreator.hpp"
#include "Quotation.hpp"
#include "User.hpp"
#include "Client.hpp"
#include "Address.hpp"
#include "Product.hpp"
#include "Separator.hpp"

//Idee : Avoir un fichier ".tex" juste a parser et a rajouter des valeurs a l'interieur -> plus facile a manipuler

LatexCreator::LatexCreator(std::string path)
	: m_path(path)
{
}

void LatexCreator::writeQuotation(Quotation* quotation)
{
	std::ofstream file;
	file.open(m_path);
	
	file.precision(2);
	//header
	file << "\\documentclass[a4paper,11pt]{report}\n";
	file << "\n";
	file << "\\usepackage[utf8]{inputenc}\n";
	file << "\\usepackage{textcomp}\n";
	file << "\n";
	file << "\\begin{document}\n";
	//user
	User* user = quotation->getUser();
	Address* uAddress = user->getAddress();
	file << "\\begin{minipage}{0.45\\textwidth}\n";
	file << user->getFirstName() << " " << user->getLastName() << "\\\\\n";
	file << uAddress->getNumber() << " " << uAddress->getStreet() << "\\\\\n";
	file << uAddress->getPostalCode() << " " << uAddress->getCity() << "\\\\\n";
	file << "\\end{minipage}\n";
	file << "\\hfill\n";
	//client
	Client* client = quotation->getClient();
	Address* hAddress = client->getHomeAddress();
	Address* wAddress = client->getWorkAddress();
	file << "\\begin{minipage}{0.45\\textwidth}\n";
	file << client->getFirstName() << " " << client->getLastName() << "\\\\\n";
	file << hAddress->getNumber() << " " << hAddress->getStreet() << "\\\\\n";
	file << hAddress->getPostalCode() << " " << hAddress->getCity() << "\\\\\n";
	file << "Lieu des travaux :\\\\\n";
	file << wAddress->getNumber() << " " << wAddress->getStreet() << "\\\\\n";
	file << wAddress->getPostalCode() << " " << wAddress->getCity() << "\\\\\n";
	file << "\\end{minipage}\n";
	//table
	file << "\\\\\\\\\n"; // temporaire(ou pas)
	file << "\\begin{tabular}{|l|c|c|c|c|}\n";
	file << "\\hline\n";
	file << "Description & \\multicolumn{2}{|c|}{Quantité} & Prix Unitaire & Montant\\\\\n";
	file << "\\hline\n";
	float total = 0;
	for(int i=0; i<quotation->getMaxId(); i++)
	{
		Row* row = quotation->getRow(i);
		if(Product* product = dynamic_cast<Product*>(row))
		{
			file << std::fixed;
			file << product->getDescription() << " & ";
			file << product->getQuantity() << " & ";
			file << product->getUnit() << " & ";
			file << product->getPrice() << " & ";
			file << product->getQuantity()*product->getPrice() << "\\\\\n";
			total += product->getQuantity()*product->getPrice();
		}
		if(Separator* separator = dynamic_cast<Separator*>(row))
		{
			file << "\\bf " << separator->getTitle() << " & & & & \\\\\n";
		}
		//file << "\\hline\n";
	}
	float tax = total*quotation->getTax()/100.0f;
	file << "\\hline\n";
	file << "& & &HT& " << total << "\\\\\n";
	file << "\\hline\n";
	file << "& & &TVA& " << tax << "\\\\\n";
	file << "\\hline\n";
	file << "& & &TTC& " << total+tax << "\\\\\n";
	file << "\\hline\n";
	file << "\\end{tabular}\n";
	file << "\\end{document}\n";
	
	file.close();
}

void LatexCreator::compile()
{
	std::string command = "pdflatex " + m_path;// + " >> /dev/null";
	std::cout << command << std::endl;
	system(command.c_str());
}
