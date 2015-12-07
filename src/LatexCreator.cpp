#include "LatexCreator.hpp"
#include "Quotation.hpp"
#include "User.hpp"
#include "Client.hpp"
#include "Address.hpp"
#include "Product.hpp"
#include "Separator.hpp"

//Idee : Avoir un fichier ".tex" juste a parser et a rajouter des valeurs a l'interieur -> plus facile a manipuler
//TODO : Comment marche minipage

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
	file << "\\documentclass[a4paper,12pt]{article}\n";
	file << "\n";
	file << "\\usepackage[utf8]{inputenc}\n";
	file << "\\usepackage{textcomp}\n";
	file << "\\usepackage{geometry}\n";
	file << "\\usepackage{array}\n";
	file << "\n";
	//mise en page
	file << "\\pagestyle{empty}\n";
	file << "\\geometry{hmargin=20pt,vmargin=50pt}\n";
	file << "\\newcolumntype{R}[1]{>{\\raggedleft\\arraybackslash}m{#1}}";
	file << "\n";
	file << "\\begin{document}\n";
	//user
	User* user = quotation->getUser();
	Address* uAddress = user->getAddress();
	file << "\\begin{minipage}[t]{0.4\\textwidth}\n";
	file << "\\center\n";
	file << "\\large\n";
	file << user->getFirstName() << " " << user->getLastName() << "\\\\\n";
	file << "\n";
	file << "\\normalsize\n";
	file << uAddress->getNumber() << " " << uAddress->getStreet() << "\\\\\n";
	file << uAddress->getPostalCode() << " " << uAddress->getCity() << "\\\\\n";
	file << "\\end{minipage}\n";
	file << "\\hfill\n";
	//client
	Client* client = quotation->getClient();
	Address* hAddress = client->getHomeAddress();
	Address* wAddress = client->getWorkAddress();
	file << "\\begin{minipage}[t]{0.5\\textwidth}\n";
	file << "\\center\n";
	file << "\\large\n";
	file << client->getFirstName() << " " << client->getLastName() << "\\\\\n";
	file << "\n";
	file << "\\normalsize\n";
	file << hAddress->getNumber() << " " << hAddress->getStreet() << "\\\\\n";
	file << hAddress->getPostalCode() << " " << hAddress->getCity() << "\\\\\n";
	file << "Lieu des travaux :\\\\\n";
	file << wAddress->getNumber() << " " << wAddress->getStreet() << "\\\\\n";
	file << wAddress->getPostalCode() << " " << wAddress->getCity() << "\\\\\n";
	file << "\\end{minipage}\n";
	file << "\\vspace{45pt}\n";
	//table
	file << "\n";
	file << "\\begin{tabular}{|p{200pt}|p{50pt}|p{20pt}|R{70pt}|R{70pt}|}\n";
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
