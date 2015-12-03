#ifndef DEF_LATEXCREATOR
#define DEF_LATEXCREATOR

#include <iostream>
#include <fstream>
#include <string.h>

class Quotation;

class LatexCreator
{
	protected:
		std::string m_path;
	public:
		LatexCreator(std::string path);
		void writeQuotation(Quotation* quotation);
		void compile();
};

#endif
