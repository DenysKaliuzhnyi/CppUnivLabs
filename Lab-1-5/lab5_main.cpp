//Автор - Калюжний Денис, К-13, Варіант 156
#include <iostream>
#include <iomanip>
#include "../copyright/copyright.h"
#include "calculation.h"
using namespace std;

void printHead(int w1, int w2, int w3, int w4)
{
	cout<< setw(w1) << "x" << setw(w2) << "f(x)" << setw(w3) << "S(x)" << setw(w4) << "S(x)-f(x)" ;
}

void printLine(double x, double f, double S, double S_f,
	int d1, int d2, int d3, int d4, int w1, int w2, int w3, int w4)
{
	cout << setw(w1) << setprecision(d1) << x <<
		setw(w2) << setprecision(d2) << f <<
		setw(w3) << setprecision(d3) << S <<
		setw(w4) << setprecision(d4) << S_f;
}

void tabulate(double a, double b, double h, double eps)
{
	cout.setf(ios::fixed);
	const int d1 = 5, d2 = 4, d3 = 3, d4 = 6, w1 = 13, w2 = 13, w3 = 13, w4 = 12;
	const double anti_double_line = b - h / 100000;
	double f, S;
	printHead(w1, w2, w3, w4);
	cout << endl;
	for (double x = a; x < anti_double_line; x += h)
	{
		f = f_156(x);
		S = S_156(x, eps);
		printLine(x, f, S, S-f, d1, d2, d3, d4, w1, w2, w3, w4);
		cout << endl;
	}
	f = f_156(b);
	S = S_156(b, eps);
	printLine(b, f, S, S-f, d1, d2, d3, d4, w1, w2, w3, w4);
	cout << endl;
}

int main()
{
	//Програма табулює функцii f(x), S(x) та S(x) - f(x) на вiдрiзку[a; b] з кроком h, де a >=-0.2, b <=0.2
	setlocale(LC_CTYPE, "rus");
	copyright();
	cout << "Програма табулює функцii f(x), S(x) та S(x)-f(x) на вiдрiзку [a;b] з кроком h, де a>="
		<<a0<<", b<="<<b0<< endl;
	double a, b, h, eps;
	cout << "Ведiть значення a та b з дiапозону [" << a0 << "," << b0 << "], (a<b):"<<endl;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "Ведiть значення h = ";
	cin >> h;
	cout << "Ведiть значення eps = ";
	cin >> eps;
	if (!((a0 <= a) && (a <= b0)) || !((a0 <= b) && (b <= b0)) || (a>b) || (eps <= 0) || (h <= 0))
	{
		cout << "Некоректно введенi значення"<<endl;
		system("pause");
		return 0;
	}
	cout << "При значеннях:" << endl << "a = " << a << endl << "b = " << b << endl << "h = " 
		<< h << endl << "eps = " << eps << endl << "Отримуємо результат..." << endl;
	tabulate(a, b, h, eps);
	system("pause");
}