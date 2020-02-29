//Автор - Калюжний Денис, К-13
#pragma once
#include "Container.h"
#include "Lexer_.h"
#include <fstream>

class Builder
{
public:
	/*відкрити файл з іменем fname на читання; поки (вдалося прочитати рядок вхідного тексту)   обробити рядок; вивести підсумки обробки*/
	bool load(InvoicesList &nk, const std::string &fname); //throw(runtime_error) за помилки читання файлу, ігнорує рядки з неправильним вмістом   
	int getLine() const;
private:
	std::string s; //поточний рядок

	int line = -1; //номер поточного рядка
	unsigned problems = 0; //кількість помилок
	unsigned loaded = 0; // кількість успішно завантажениї непорожніх рядків

	//some statistics
	unsigned countOfProductsInCurrentInvoice = 0;
	double totalTypeOfProducts = 0;
	unsigned totalInvoices = 0;
	double totalCountOfProducts = 0;

	InvoicesList *nvcs = nullptr; //вказівник на контейнер, в який записуємо інформацію
	Lexer lex;

	//fields
	std::string snumber, sproduct_name, scount, sprice_per_1, scost, shead, sfoot1, sfoot2;

	void loadOneLine(); 
	//у залежності від типу вмісту рядка викликати відповідний метод-обробник
	void loadLine(); 
	//1) розібрати вхідний рядок на частини; 2) за необхідністю перетворити рядкові значення на відповідні числові; 3) записати конвертовану інформацію в контейнер; 4) обновити підсумкову інформацію.
	void loadHeader();
	void loadFooter();
	void parseLine(); 
	//Його відповідальністю є розділити рядок на частини згідно з роздільниками і переконатися, що частин правильна кількість
	void parseHead();
	void parseFoot();
};
