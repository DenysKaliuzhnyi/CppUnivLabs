//����� - �������� �����, �-13
#pragma once
#include "Container.h"
#include "Lexer_.h"
#include <fstream>

class Builder
{
public:
	/*������� ���� � ������ fname �� �������; ���� (������� ��������� ����� �������� ������)   �������� �����; ������� ������� �������*/
	bool load(InvoicesList &nk, const std::string &fname); //throw(runtime_error) �� ������� ������� �����, ������ ����� � ������������ ������   
	int getLine() const;
private:
	std::string s; //�������� �����

	int line = -1; //����� ��������� �����
	unsigned problems = 0; //������� �������
	unsigned loaded = 0; // ������� ������ ����������� ��������� �����

	//some statistics
	unsigned countOfProductsInCurrentInvoice = 0;
	double totalTypeOfProducts = 0;
	unsigned totalInvoices = 0;
	double totalCountOfProducts = 0;

	InvoicesList *nvcs = nullptr; //�������� �� ���������, � ���� �������� ����������
	Lexer lex;

	//fields
	std::string snumber, sproduct_name, scount, sprice_per_1, scost, shead, sfoot1, sfoot2;

	void loadOneLine(); 
	//� ��������� �� ���� ����� ����� ��������� ��������� �����-��������
	void loadLine(); 
	//1) �������� ������� ����� �� �������; 2) �� ����������� ����������� ������ �������� �� ������� ������; 3) �������� ������������ ���������� � ���������; 4) �������� ��������� ����������.
	void loadHeader();
	void loadFooter();
	void parseLine(); 
	//���� ������������� � �������� ����� �� ������� ����� � ������������ � ������������, �� ������ ��������� �������
	void parseHead();
	void parseFoot();
};
