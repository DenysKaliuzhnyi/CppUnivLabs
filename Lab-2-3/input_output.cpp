//����� - �������� �����, �-13, ������ 156
#include <iostream>
#include "input_output.h"
using namespace std;

void Info()
{
	cout << "���� ������� ���������� ������i, ��� �� 3 �i��� �� 1 ��i��i���, " << endl <<
		"���� ���� (on/off & open/close) ������ �� ����������� �� �����i���." << endl <<
		"� ���i ������ �� ���������� �i������ ������� ��i���� ��������� �����i����, " << endl <<
		"�� ���������� ������� � ����i���� ���� �� ������������ �������i ��i��." << endl << endl;
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
		if (choice == 1) 
		{ if (!other.open()) cout << endl << p; }
		else if (choice == 2) 
		{ if (!other.close()) cout << endl << p; }
		else if (choice == 3) 
		{ if (!other.heater_on()) cout << endl << p; }
		else if (choice == 4) 
		{ if (!other.heater_off()) cout << endl << p; }
		else if (choice == 5) 
		{ other.timeModel(); other.check_changes(); }
		else if (choice != 6) cout << "���� �����i� �� i���" << endl;
		cout << endl << endl;
	} while (choice != 6);
	cout << (string)other << endl;
	cout << "������ ���������" << endl;
}