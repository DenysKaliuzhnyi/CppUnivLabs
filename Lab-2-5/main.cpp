//104
//����� - �������� �����, �-13
#include <iostream>
#include <fstream>
#include <string>
#include "Loading.h"
#include "Container.h"
#include "../copyright/copyright.h"
using namespace std;

//C:\Users\Denis\Desktop\Lab4_4\Debug\lab5.exe C : \Users\Denis\Desktop\Lab4_4\lab5\myFile.txt -output C : \Users\Denis\Desktop\Lab4_4\lab5\B2.txt -sort :con -stat C : \Users\Denis\Desktop\Lab4_4\lab5\B3.txt smth : con

void outputSorted(const std::string &path, const InvoicesList &inL, const string& command);
void outputTop(const string &path, const InvoicesList &inL);
void Load(const std::string &fname, InvoicesList &a);
void info();

int main(int argc, char* argv[])
{
	setlocale(LC_CTYPE, "rus");
	cout << endl;
	copyright();
	info();
	cout << "*****" << endl;
	InvoicesList inL;
	const string fname = argv[1]; //name of file that we read
	Load(fname, inL);
	for (int i = 2; argv[i] != nullptr; i += 2)
	{
		if (argv[i + 1] != nullptr) 
		{
			string path = argv[i + 1];
			if (strcmp(argv[i], "-output") == 0) outputSorted(path, inL, argv[i]);
			else if (strcmp(argv[i], "-sort") == 0) outputSorted(path, inL.sorList(), argv[i]);
			else if (strcmp(argv[i], "-stat") == 0) outputTop(path, inL);
			else if (strcmp(argv[i], "-output") != 0 && strcmp(argv[i], "-sort") != 0 && strcmp(argv[i], "-stat") != 0) 
				cout << argv[i] << " :ignored" << endl;
			else if (argv[i] == nullptr) cout << " ERROR";
		}
		else cout << " ERROR" << endl;
	}
	cout << "*****" << endl;
	system("pause");
	return 0;
}

void Load(const string &fname, InvoicesList &inL)
{
	Builder minecraft;
	try
	{
		cout << "input " << fname << " :";
		if (minecraft.load(inL, fname)) cout << "OK\n";
		else cout << "UPS\n";
	}
	catch (runtime_error &ex) { cout << "runtime: " << ex.what() << endl; }
	catch (logic_error &ex) { cout << "logic: " << ex.what() << endl; }
	catch (exception &ex) { cout << "other: " << ex.what() << endl; }
}

void outputSorted(const std::string &path, const InvoicesList &inL, const string& command)
{
	string mess;
	if (command == "-output") mess = "output";
	else mess = "sort";
	const string mes = mess + ' ' + path;
	if (path == ":con")
	{
		if (cout << inL) cout << mes + " :OK\n";
		else  cout << mes + " :UPS\n";
	}
	else
	{
		ofstream fout(path);
		if (fout)
		{
			fout << inL;
			cout << mes + " :OK\n";
		}
		else  cout << mes + " :UPS\n";
	}
}

void outputTop(const string &path, const InvoicesList &inL)
{
	const string delim = "<>";
	Invoice in = inL.findPopularProducts().first;
	Invoice::Product p = in.findTopProductInInvoice();
	int count = inL.findPopularProducts().second;
	const string mes = "stat " + path;
	if (path == ":con")
	{
		if (cout << p.product_name_ << delim << count << delim << round(p.count * 100)/100 << delim << round(p.price_per_1 * 100)/100 << endl) cout << mes << " :OK\n";
		else cout << mes << " :UPS\n";
	}
	else
	{
		ofstream f(path);
		if (f << p.product_name_ << delim << count << delim << round(p.count * 100 / 100) << delim << round(p.price_per_1 * 100) << endl) cout << mes << " :OK\n";
		cout << mes << " :UPS\n";
	}
}

void info()
{
	cout << "���� �������� ���� (������ i�������i� � ����������), ���� �i����� ������ �������� ���������." << endl
		<< "���i� ����-��� i�������i� ���� �i��������� ��� �� �������, ��� � ���� - ������� \":con\" a�� i�'� ����� �i����i���" << endl
		<< "1) ��i� �������� ����������� i�������i� - ������a \"output\"." << endl
		<< "2) ��i� ��������� ��i�� ����� � ������ �������: �������� �� ������ ������, ���i� �� �i���i���, �i���, " << endl
		<< "����i���, ������� �������� - ������� \"stat\"." << endl
		<< "3) ��i� ��������� ����������: ����i��� ��������i ������ (�i, �� �i�������������� � ����i���i� �i������i); " << endl
		<< "�������� �� ��� i�������i� (����� ������, � ��i����� ���������, ��i���� ���� �i���������� �� �� ���� " << endl
		<< "����i����� �i��� �� ���� �i����������) - ������� stat. " << endl
		<< "������� ������ � ���������� ����� �����: <����������� ����> <i�� ��i����� �����> {�<�������> <i�� ���i����� �����>} " << endl
		<< "<�������> -���� � output, sort, stat" << endl
		<< "�i����i ����� ���������, �� �i����i��� ������� ���������� ����� ���� �����i������ ���i���� �i���i��� ���i�." << endl << endl;
}