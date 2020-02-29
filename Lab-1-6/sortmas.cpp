//����� - �������� �����, �-13, ������ 156
#include <iostream>
#include <time.h>
using namespace std;


void coutArray(int mas[], int N)
{
	if (N > 0)
	{
		cout << "�i���i��� �������i� � �����i N = " << N << endl;
		cout << "�������� ������: ";
		cout << mas[0];
		for (int i = 1; i < N; i++)
		{
			cout << ", ";
			cout << mas[i];
		}
		cout << '.' << endl;
	}
	else cout << "����� ������i�!"<<endl;
}

void generateArray(int mas[], int N)
{
	int change;        //����� ��� ��������� ��'����� ��������
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		change = rand() % 5 + 1;
		mas[i] = rand();
		if (rand() % change == 0) mas[i] *= -1;
	}
}

bool readArray1(int mas[], int &N)
{
	cout << "����i�� �i���i��� �������i� ������ N = ";
	cin >> N;
	if ((N > 1000) || (N <= 0))
	{
		cout << "����i� ������ �� 1000 �������i�!" << endl;
		return false;
	}
	else
	{
		generateArray(mas, N);
		return true;
	}
}

void readArray2(int mas[], int &N)
{
	cin.exceptions(ios_base::failbit);
	int i = 0;
	while (i < 1000)
	{
		try
		{
			cin >> mas[i];
		}
		catch (istream::failure e)
		{
			break;
		}
		i++;
	}
	N = i;
}


double printMas5(int mas[], int N)
{
	double max = mas[0], min = mas[0];
	for (int i = 1; i < N; ++i)
	{
		if (mas[i] > max) max = mas[i];
		if (mas[i] < min) min = mas[i];
	}
	return max + min;
}
