//Автор - Калюжний Денис, К-13, Варіант 156
#include <iostream>
#include "Matritsa.h"
#include "../copyright/copyright.h"
using namespace std;

void info();
void generate(Matritsa &m);
//Функція generate заповнює матрицю послідовними числами від 0.

int main()
{
	int N;
	setlocale(LC_CTYPE, "rus");
	copyright();
	info();
	cin >> N;
	Matritsa m;
	if (!m.create(N)) cout << "Недопустимий розмiр матрицi." << endl;
	else
	{
		try
		{
			generate(m);
			writeMatritsa(m);
			cout << "***** Input" << endl;
			cout << "N = " << m.getSize() << endl;
			cout << "***** Output, 156" << endl;
			findSpiral(m);
			cout << "*****" << endl;
		}
		catch (out_of_range &error)
		{
			cout << error.what() << endl;
		}
	}
	system("pause");
	return 0;
}

void generate(Matritsa &m)
{
	int a = 0;
	for (int i = 0; i < m.getSize(); i++)
		for (int j = 0; j < m.getSize(); j++)
			m.get_i_j(i, j) = a++;
}

void info()
{
	cout << "Вона заповнює матрицю N*N послiдовними числами, починаючи з 0, де N вводить користувач." << endl
		<< "Виводить елементи масива обходом трикутника пiд головною дiагоналлю" << endl
		<< "матрицi спрiаллю вiд нижнього правого кута проти годинникової стрiлки" << endl;
	cout << "Ведiть розмiрнiсть матрицi N = ";
}