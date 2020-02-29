//Автор - Калюжний Денис, К-13, Варіант 156
#include <iostream>
#include <string>
#include "Greenhouse_156.h"
#include "../copyright/copyright.h"
using namespace std;

void Info();
//Виводить загальну інформацію про програму

//Функція Available_actions виводить информацію про доступні дії над теплицею

void Do_action(Greenhouse_156 &other);
//Виявляє яку дію треба виконати над теплицею та інформує про її поточний стан

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
	cout << "Вона моделює екосистему теплицi, яка має 3 вiкна та 1 обiгрiвач, " << endl <<
		"стан яких (on/off & open/close) впливає на температуру та вологiсть." << endl <<
		"У разi виходу за допустимий дiапазон значень клiмату спрацьовує запобiжник, " << endl <<
		"що переводить теплицю у аварiйний стан та унеможливлює подальшi змiни." << endl << endl;
	cout << "Оберiть модель теплицi: натиснiть 1 щоб обрати першу модель "
		<< "або 2 для другої моделi вiдповiдно." << endl;
	cout << "Прцювати з Greenhouse №";
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
		default: cout << "Такої перацiї не iснує" << endl;
		}
		cout << endl << endl;
	} while (choice != 6);
	cout << (string)other << endl;
	cout << "Робота завершена" << endl;
}