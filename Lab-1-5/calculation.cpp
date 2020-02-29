//Автор - Калюжний Денис, К-13, Варіант 156
#include <cmath>
double f_156(double x)
{
	double part = 1 + 16 * x * x;
	return sqrt((1 + sqrt(part)) / (2 * part));
}

double S_156(double x, double eps)
{
	int n = 1; 
    double last = 1, sum = 0;
	double x_pow = -2*x*x;
	while (abs(last) >= eps)
	{
		sum = sum + last;
		last *= x_pow*(4 * n - 3)*(4 * n - 1) / (n*(2 * n - 1));
		n++;

	}
	return sum;
}
