//Автор - Калюжний Денис, К-13, Варіант 156
#include <iostream>
#include "Matritsa.h"
#include <stdexcept>
using namespace std;

int Matritsa::getSize() const
{
	return N;
}

bool Matritsa::null(int N) const
{
	return N != 0;
}

int &Matritsa::get_i_j(int i, int j) 
{
	if (i >= 0 && i < N && j >= 0 && j < N) return mas[i][j];
	else throw std::out_of_range("out_of_range, check your code");
}


bool Matritsa::create(int N)
{
	bool f = false;
	if ((N > dim) || (!null(N)) || N < 0) return f;
	this->N = N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			mas[i][j] = 0;
	f = true;
	return f;
}

void output(int a)
{
	cout << a << ' ';
	if (a < 10) cout << ' ';
	if (a < 100) cout << ' ';
}

void writeMatritsa(Matritsa &m)
{
	for (int i = 0; i < m.getSize(); i++)
	{
		for (int j = 0; j < m.getSize(); j++)
			output(m.get_i_j(i, j));
		cout << endl;
	}
	cout << endl;
}

void writeSpiral(bool &d1, int i, int j, Matritsa &m, int N)
{
	static int count = 0;
	if (N == 1)
	{
		output(m.get_i_j(i, j));
		d1 = false;
	}
	else if (N < 2) d1 = false;
	else
	{
		output(m.get_i_j(i, j));
		if (++count % 10 == 0)  cout << endl;
	}
}

void findSpiral(Matritsa &m)
{
	enum status { DIAGONAL, VERIKAL, GORIZONTAL };
	status s = DIAGONAL;
	int n = m.getSize();
	int N = n, i = n, j = n;
	int min_i = 0, max_i = n - 1, max_j = n - 2;
	//останні змінні використовуються для встановлення "рамок"
	//нової матриці (після проходження одного трикутника)
	bool d1 = true, d2 = true;
	//ці змінні замінюють break та continue
	while (d1)
	{
		switch (s)
		{
		case DIAGONAL:
			if (i == min_i) { s = VERIKAL; d2 = false; break; }
			else { i--;	j--; break; }
		case VERIKAL:
			if (i == max_i) { s = GORIZONTAL;	d2 = false; break; }
			else { i++; break; }
		default:
			if (j == max_j)
			{
				s = DIAGONAL;
				i--;
				j--;
				min_i += 2;
				max_i -= 1;
				max_j -= 2;
				N -= 3;
			}
			else j++;
		}
		if (d2) writeSpiral(d1, i, j, m, N);
		d2 = true;
	}
	cout << endl;
}
