//����� - �������� �����, �-13
#pragma once
#include <string>

class Lexer
{
public:
	enum LineType { EMPTY, LINE, HEADER, FOOTER };
	LineType load(const std::string &source_);
	//������ �����, ���� ����� ��������, ������ ������� ������� � ������� ���������� ����� ����� �������� � �����
	bool next(std::string &lex);
	//����� next ������ � ����� �������� ������� � ������� ������ ��������; "" ���� ����� ��������
	void skipAllBeforeColon();
	bool eof() const;
	bool isEmpty(const std::string &str) const;
protected:
	std::string source; //�����, ����� ����� ����������
	bool eof_ = true;
	std::basic_string<char>::size_type pos = 0;
	static const std::string delim1;
	static const std::string delim2;
};

