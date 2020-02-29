//Автор - Калюжний Денис, К-13, Варіант 156
#pragma once
#include <string>

class Greenhouse_156
{
public:
	//встановлює заводський стан
	Greenhouse_156();

	//Наступним кроком після створення екземпляра классу цей метод
	//перевіряє чи взагалі реальні значення ініціалізував конструктор
	bool check_start() const;

	//Функції Get_smth надають доступ до значення, зазначеного у smth
	int get_n_windows() const;
	int get_n_open() const;
	int get_n_heater() const;
	int get_n_heater_on() const;
	double get_t() const;
	double get_h() const;
	bool get_keeper() const;

	//Функції доступних дій та модель проходження часу
	bool open();
	bool close();
	bool heater_on();
	bool heater_off();
	void timeModel();
	void check_changes();

	//Перетворює поточні значення полів та іншу додаткову інформацію
	//у рядкове значення для виводу поточного стану теплиці
	operator std::string();

private:
	const int n_windows;
	int n_open;
	const int n_heater;
	int n_heater_on;
	double t;
	double h;
	bool keeper;
};

