//����� - �������� �����, �-13, ������ 156
#include <iostream>
#include "sortmas.h"
#include "../copyright/copyright.h"
using namespace std;

bool choose(int mas[], int &N)
{
	int type;
	cout << "����i�� ����� ���������� ������. ������i�� \"1\", ���� ������ ��������� ����� "
		<< "����������� ��� \"2\", ���� ������ ��������� ����� ������: ";
	cin >> type;
	if (type == 1)
	{
		return readArray1(mas, N);
	}
	else if (type == 2)
	{
		readArray2(mas, N);
		return true;
	}
	else cout << "������i�� 1 ��� 2!" << endl;
	return false;
}

int main()
{
	int mas[1000], N;
	setlocale(LC_CTYPE, "rus");
	copyright();
	cout << "�� �������� �������� ���� �i�i�������� �� ������������� �������i� ������, "
		<< "���� ��� �������� ������������ ������i��� ��� ���������� �����������." << endl;
	if (choose(mas, N))
	{
		coutArray(mas, N);
		cout << "���a �i�i�������� �� ������������� �������i� ������ sum = " << printMas5(mas, N)<<endl;
	}
	system("pause");
}