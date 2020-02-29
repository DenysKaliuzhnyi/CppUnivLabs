//Автор - Калюжний Денис, К-13, Варіант 156
#pragma once
#include <string>

class Greenhouse_156 //abstract class!!!
{
public:
	virtual ~Greenhouse_156() = default;
	Greenhouse_156(const Greenhouse_156& a) = default;
    Greenhouse_156(Greenhouse_156&& a) = default;
	Greenhouse_156& operator =(const Greenhouse_156& a) = default;
	Greenhouse_156& operator =(Greenhouse_156&& a) = default;

	//Функції Get_smth надають доступ до значення, зазначеного у smth
	int get_n_windows() const;
	int get_n_open() const;
	int get_n_heater() const;
	int get_n_heater_on() const;
	double get_t() const;
	double get_h() const;
	bool get_keeper() const;

	//Функції доступних дій
	bool open();
	bool close();
	bool heater_on();
	bool heater_off();
	
	//Викликає change_climate() та check_changes(), перевіривши перед цим стан запобіжника
	void time_model();

	//Виводить поточний стан теплиці
	operator std::string() const;
protected:
	//Встановлює заводський стан  похідних теплиць. 
	//Використовується виключно для делегування з конструкторами похідних класів
	Greenhouse_156(int n_windows_, int n_open, int n_heater_, int n_heater_on, double t, double h);

	//Змінює клімат з проходженням одиниці часу
	virtual void change_climate() = 0;
	//Викликається одразу після change_climate (зміни клімату) та у разі необхідності спрацьовує запобіжник
	virtual void check_changes() = 0;
	//Встановлює значення при аварійному стані
	virtual void set_crash() = 0;
	//Повертає назву моделі теплиці
	virtual std::string name() const = 0;

	const int n_windows;
	int n_open;
	const int n_heater;
	int n_heater_on;
	double t;
	double h;
	bool keeper;
};

class Greenhouse1_156 : public Greenhouse_156
{
public:
	Greenhouse1_156();
private:
	std::string name() const override;
	void change_climate() override;
	void check_changes() override;
	void set_crash() override;
};

class Greenhouse2_156 : public Greenhouse_156
{
public:
	Greenhouse2_156();
private:
	std::string name() const override;
	void change_climate() override;
	void check_changes() override;
	void set_crash() override;
};