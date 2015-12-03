#include "LatexCreator.hpp"
#include "Quotation.hpp"
#include "Product.hpp"
#include "Separator.hpp"

LatexCreator::LatexCreator(std::string path)
	: m_path(path)
{
}

void LatexCreator::writeQuotation(Quotation* quotation)
{
	std::ofstream file;
	file.open(m_path);
	
	file.precision(2);
	
	file << "\\documentclass[a4paper,11pt]{report}\n";
	file << "\n";
	file << "\\usepackage[utf8]{inputenc}\n";
	file << "\\usepackage{textcomp}\n";
	file << "\n";
	file << "\\begin{document}\n";
	file << "\\begin{tabular}{|l|c|c|c|c|}\n";
	file << "\\hline\n";
	file << "Description & Quantité & Prix Unitaire & Unité & Prix\\\\\n";
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
			file << product->getPrice() << " & ";
			file << product->getUnit() << " & ";
			file << product->getQuantity()*product->getPrice() << "\\\\\n";
			total += product->getQuantity()*product->getPrice();
		}
		if(Separator* separator = dynamic_cast<Separator*>(row))
		{
			file << "\\multicolumn{5}{|l|}{" << separator->getTitle() << "}\\\\\n";
		}
		file << "\\hline\n";
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
