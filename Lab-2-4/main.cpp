//����� - �������� �����, �-13, ������ 156
#include <iostream>
#include <string>
#include "Greenhouse_156.h"
#include "../copyright/copyright.h"
using namespace std;

void Info();
//�������� �������� ���������� ��� ��������

//������� Available_actions �������� ���������� ��� ������� 䳿 ��� ��������

void Do_action(Greenhouse_156 &other);
//������� ��� �� ����� �������� ��� �������� �� ������� ��� �� �������� ����

int main()
{
	setlocale(LC_CTYPE, "rus");
	copyright();
	Info();
	string type_choise;
	bool stop = false;
	try
	{
		Greenhouse_156 *pGreenhouse = nullptr;
		cin >> type_choise;
		cout << endl;
		if (type_choise == "1") pGreenhouse = new Greenhouse1_156();
		else if (type_choise == "2") pGreenhouse = new Greenhouse2_156();
		else stop = true;
		if (!stop)
		{
			Do_action(*pGreenhouse);
			delete pGreenhouse;
			pGreenhouse = nullptr;
		}
		else cout << "wrong input!" << endl;
	}
	catch (const bad_alloc &ex) { cout << ex.what() << ", no data to create new Greenhouse" << endl; }
	catch (const exception &ex) { cout << ex.what() << ", error of class exception" << endl; }
	catch (...) { cout << "unknown error" << endl; }
	system("pause");
	return 0;
}

void Info()
{
	cout << "���� ������� ���������� ������i, ��� �� 3 �i��� �� 1 ��i��i���, " << endl <<
		"���� ���� (on/off & open/close) ������ �� ����������� �� �����i���." << endl <<
		"� ���i ������ �� ���������� �i������ ������� ��i���� ��������� �����i����, " << endl <<
		"�� ���������� ������� � ����i���� ���� �� ������������ �������i ��i��." << endl << endl;
	cout << "����i�� ������ ������i: ������i�� 1 ��� ������ ����� ������ "
		<< "��� 2 ��� ����� �����i �i����i���." << endl;
	cout << "�������� � Greenhouse �";
}

void Available_actions()
{
	cout << "�������i �i�:" << endl;
	cout << "1) �i������ �i���" << endl;
	cout << "2) ������� �i���" << endl;
	cout << "3) ��i������ ��i��i���" << endl;
	cout << "4) �������� ��i��i���" << endl;
	cout << "5) ������� ������� ����" << endl;
	cout << "6) ��������� ���������" << endl;
	cout << "�������� �i� �";
}

void Do_action(Greenhouse_156 &other)
{
	const string p = "�i��������: ��������� �������� �i�";
	unsigned int choice;
	do
	{
		cout << (string)other << endl;
		Available_actions();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{ if (!other.open()) cout << endl << p; break; }
		case 2:
		{ if (!other.close()) cout << endl << p; break; }
		case 3:
		{ if (!other.heater_on()) cout << endl << p; break; }
		case 4:
		{ if (!other.heater_off()) cout << endl << p; break; }
		case 5:
		{ other.time_model(); break; }
		case 6: break;
		default: cout << "���� �����i� �� i���" << endl;
		}
		cout << endl << endl;
	} while (choice != 6);
	cout << (string)other << endl;
	cout << "������ ���������" << endl;
}