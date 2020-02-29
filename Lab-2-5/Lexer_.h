//Автор - Калюжний Денис, К-13
#pragma once
#include <string>

class Lexer
{
public:
	enum LineType { EMPTY, LINE, HEADER, FOOTER };
	LineType load(const std::string &source_);
	//отримує рядок, який треба розібрати, ініціює початок розбору і визначає інформація якого сорту міститься в рядку
	bool next(std::string &lex);
	//Метод next виділяє з рядка черговий елемент й повертає ознаку успішності; "" якщо рядок розібрано
	void skipAllBeforeColon();
	bool eof() const;
	bool isEmpty(const std::string &str) const;
protected:
	std::string source; //рядок, розбір якого виконується
	bool eof_ = true;
	std::basic_string<char>::size_type pos = 0;
	static const std::string delim1;
	static const std::string delim2;
};

