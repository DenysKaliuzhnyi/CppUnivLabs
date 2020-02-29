//Автор - Калюжний Денис, К-13
#include "Loading.h"
#include <exception>
#include "Functions.h"
#include <iostream>
using namespace std;

bool Builder::load(InvoicesList &nvcs_, const std::string &fname)
{
	ifstream f;
	nvcs = &nvcs_; //встановлюємо вказівник наш контейнер
	f.open(fname);
	f.clear();
	if (!f) throw runtime_error("Unable to open input file " + fname);
	line = -1;
	problems = 0;
	loaded = 0;
	totalTypeOfProducts = 0;
	totalInvoices = 0;
	totalCountOfProducts = 0;
	while (getline(f, s))
	{
		++line;
		try { loadOneLine(); }
		catch (logic_error &ex)
		{
			++problems;
			std::cout << s << "\nLine" << line << ": " << ex.what() << endl;
		}
	}
	if (!f.eof()) throw runtime_error("Unable to read input file " + fname);
	f.close();
	return problems == 0;
}


void Builder::loadOneLine()
{
	switch (Builder::lex.load(s))
	{
	case Lexer::EMPTY: return;
	case Lexer::LINE: { loadLine();   return; }
	case Lexer::HEADER: { loadHeader(); return; }
	case Lexer::FOOTER: {  loadFooter();  return; }
	default: {	++problems; throw logic_error("Unknown \ answer from Lexer::load. Revise code for \ Loader::loadOneLine\n"); }
	}
}

void Builder::loadHeader()
{
	parseHead();
	nvcs->getHead() = atof(trim(shead).c_str());
	loaded++;
}

void Builder::loadFooter()
{
	parseFoot();
	nvcs->getFoot1() = atof(trim(sfoot1).c_str());
	nvcs->getFoot2() = atof(trim(sfoot2).c_str());
	loaded++;

}

void Builder::loadLine() //no check
{
	countOfProductsInCurrentInvoice = 0;
	while (!lex.eof())
	{
		parseLine();
		double count = atof(trim(scount).c_str());
		nvcs->add_product(trim(snumber), trim(sproduct_name), count , atof(trim(sprice_per_1).c_str()) , atof(trim(scost).c_str()));
		countOfProductsInCurrentInvoice++;
		totalTypeOfProducts++;
		totalCountOfProducts += count;
	}
	totalInvoices++;
	loaded++;
}

void Builder::parseLine()
{
	if (countOfProductsInCurrentInvoice == 0)
	{
		lex.skipAllBeforeColon();
		if (!lex.next(snumber)) throw logic_error("Too less information in line:line number is absent");
	}
	if (!lex.next(sproduct_name)) throw logic_error("Too less information in line:line number is absent");
	if (!lex.next(scount)) throw logic_error("Too less information in line:line number is absent");
	if (!lex.next(sprice_per_1)) throw logic_error("Too less information in line:line number is absent");
	if (!lex.next(scost)) throw logic_error("Too less information in line:line number is absent");
}

void Builder::parseHead()
{
	lex.skipAllBeforeColon();
	if (!lex.next(shead))  throw logic_error("Too less information in line:product name is absent");
}

void Builder::parseFoot()
{
	lex.skipAllBeforeColon();
	if (!lex.next(sfoot1)) throw logic_error("Too less information in line:product name is absent");
	if (!lex.next(sfoot2)) throw logic_error("Too less information in line:product name is absent");
}

int Builder::getLine() const
{
	return line;
}