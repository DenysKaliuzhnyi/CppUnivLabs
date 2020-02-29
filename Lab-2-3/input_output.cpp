//Автор - Калюжний Денис, К-13, Варіант 156
#include <iostream>
#include "input_output.h"
using namespace std;

void Info()
{
	cout << "Вона моделює екосистему теплицi, яка має 3 вiкна та 1 обiгрiвач, " << endl <<
		"стан яких (on/off & open/close) впливає на температуру та вологiсть." << endl <<
		"У разi виходу за допустимий дiапазон значень клiмату спрацьовує запобiжник, " << endl <<
		"що переводить теплицю у аварiйний стан та унеможливлює подальшi змiни." << endl << endl;
}

void Available_actions()
{
	cout << "Доступнi дiї:" << endl;
	cout << "1) Вiдкрити вiкно" << endl;
	cout << "2) Закрити вiкно" << endl;
	cout << "3) Ввiмкнути обiгрiвач" << endl;
	cout << "4) Вимкнути обiгрiвач" << endl;
	cout << "5) Пройшла одиниця часу" << endl;
	cout << "6) Завершити керування" << endl;
	cout << "Виконати дiю №";
}

void Do_action(Greenhouse_156 &other)
{
	const string p = "Вiдмовлено: неможливо виконати дiю";
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
		else if (choice != 6) cout << "Такої перацiї не iснує" << endl;
		cout << endl << endl;
	} while (choice != 6);
	cout << (string)other << endl;
	cout << "Робота завершена" << endl;
}