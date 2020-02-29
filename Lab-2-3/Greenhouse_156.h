//����� - �������� �����, �-13, ������ 156
#pragma once
#include <string>

class Greenhouse_156
{
public:
	//���������� ���������� ����
	Greenhouse_156();

	//��������� ������ ���� ��������� ���������� ������ ��� �����
	//�������� �� ������ ������ �������� ����������� �����������
	bool check_start() const;

	//������� Get_smth ������� ������ �� ��������, ����������� � smth
	int get_n_windows() const;
	int get_n_open() const;
	int get_n_heater() const;
	int get_n_heater_on() const;
	double get_t() const;
	double get_h() const;
	bool get_keeper() const;

	//������� ��������� �� �� ������ ����������� ����
	bool open();
	bool close();
	bool heater_on();
	bool heater_off();
	void timeModel();
	void check_changes();

	//���������� ������ �������� ���� �� ���� ��������� ����������
	//� ������� �������� ��� ������ ��������� ����� �������
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

