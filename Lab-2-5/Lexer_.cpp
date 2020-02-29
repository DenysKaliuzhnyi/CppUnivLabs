//Автор - Калюжний Денис, К-13
#include "Lexer_.h"
#include "Functions.h"
using namespace std;

const std::string Lexer::delim1 = "??";
const std::string Lexer::delim2 = "<>";

Lexer::LineType Lexer::load(const string &source_)
{
	string source__ = trim(source_);
	if (isEmpty(source__))
	{
		source = "";
		eof_ = true;
		pos = string::npos;
		return EMPTY;
	}
	else
	{
		source = source_;
		eof_ = false;
		pos = 0;
		if (!(source__.find("header:")))
			return HEADER;
		if (!(source__.find("footer:")))
			return FOOTER;
		return LINE;
	}
}

bool Lexer::eof() const
{
	return eof_;
}

bool Lexer::next(string &lex)
{
	lex = "";
	if (eof()) return false;
	string source_ = trim(source);
	size_t pos1;
	string delim_;
	auto pos1_1 = source_.find(delim1, pos);
	auto pos1_2 = source_.find(delim2, pos);
	if (pos1_1 < pos1_2) { pos1 = pos1_1; delim_ = delim1; }
	else { pos1 = pos1_2; delim_ = delim2; }
	lex = source_.substr(pos, pos1 - pos);
	if (pos1 < string::npos) pos1 += delim_.length();
	else eof_ = true;
	pos = pos1;
	return true;
}

bool Lexer::isEmpty(const string &str) const
{
	if (!str.size()) return true;
	for (int i = 0; i < str.size(); i++)
		if (str[i] != ' ') return false;
	return true;
}

void Lexer::skipAllBeforeColon()
{
	pos = trim(source).find_first_of(':') + 1;
}