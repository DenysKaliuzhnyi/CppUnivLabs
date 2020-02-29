//Автор - Калюжний Денис, К-13, Варіант 156
#include <iostream>
#include <time.h>
using namespace std;


void coutArray(int mas[], int N)
{
	if (N > 0)
	{
		cout << "Кiлькiсть елементiв в масивi N = " << N << endl;
		cout << "Елементи масива: ";
		cout << mas[0];
		for (int i = 1; i < N; i++)
		{
			cout << ", ";
			cout << mas[i];
		}
		cout << '.' << endl;
	}
	else cout << "Масив порожнiй!"<<endl;
}

void generateArray(int mas[], int N)
{
	int change;        //змінна для створення від'ємних елементів
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
	cout << "Введiть кiлькiсть елементiв масиву N = ";
	cin >> N;
	if ((N > 1000) || (N <= 0))
	{
		cout << "Розмiр масиву до 1000 елементiв!" << endl;
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
