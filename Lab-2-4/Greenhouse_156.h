//����� - �������� �����, �-13, ������ 156
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

	//������� Get_smth ������� ������ �� ��������, ����������� � smth
	int get_n_windows() const;
	int get_n_open() const;
	int get_n_heater() const;
	int get_n_heater_on() const;
	double get_t() const;
	double get_h() const;
	bool get_keeper() const;

	//������� ��������� ��
	bool open();
	bool close();
	bool heater_on();
	bool heater_off();
	
	//������� change_climate() �� check_changes(), ���������� ����� ��� ���� ����������
	void time_model();

	//�������� �������� ���� �������
	operator std::string() const;
protected:
	//���������� ���������� ����  �������� �������. 
	//��������������� �������� ��� ����������� � �������������� �������� �����
	Greenhouse_156(int n_windows_, int n_open, int n_heater_, int n_heater_on, double t, double h);

	//����� ����� � ������������ ������� ����
	virtual void change_climate() = 0;
	//����������� ������ ���� change_climate (���� ������) �� � ��� ����������� ��������� ���������
	virtual void check_changes() = 0;
	//���������� �������� ��� ��������� ����
	virtual void set_crash() = 0;
	//������� ����� ����� �������
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