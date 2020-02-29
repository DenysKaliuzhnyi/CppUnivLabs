#include "Tests.h"
using namespace std;

double INT_Tests::add_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++)
	{
		a1 = 111 % i + 1; a2 = 22 % i + 1;

		a3 = a1 + a2; a4 = a2 + a3; a5 = a3 + a4; a6 = a4 + a5;
		a7 = a5 + a6; a8 = a6 + a7; a9 = a7 + a8; a10 = a8 + a9;
		a1 = a9 + a10; a2 = a10 + a1;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double INT_Tests::subtr_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++)
	{
		a1 = 111 % i + 1; a2 = 22 % i + 1;

		a3 = a1 - a2; a4 = a2 - a3; a5 = a3 - a4; a6 = a4 - a5;
		a7 = a5 - a6; a8 = a6 - a7; a9 = a7 - a8; a10 = a8 - a9;
		a1 = a9 - a10; a2 = a10 - a1;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double INT_Tests::mult_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++)
	{
		a1 = 111 % i + 1; a2 = 22 % i + 1;

		a3 = a1 * a2; a4 = a2 * a3; a5 = a3 * a4; a6 = a4 * a5;
		a7 = a5 * a6; a8 = a6 * a7; a9 = a7 * a8; a10 = a8 * a9;
		a1 = a9 * a10; a2 = a10 * a1;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double INT_Tests::div_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++) {
		a1 = 10 % i + 1; a2 = 100 % i + 1; a3 = 10; a4 = 100; a5 = 1000; a6 = 10000; a7 = 100000; a8 = 1000000; a9 = 10000000; a10 = 100000000;

		a3 = a2 / a1; a6 = a5 / a4; a9 = a8 / a7; a2 = a1 / a10; a4 = a5 / a6;
		a5 = a7 / a6; a7 = a5 / a6; a8 = a7 / a6; a10 = a8 / a9; a1 = a10 / a9;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double INT_Tests::empty_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++)
	{
		a1 = 111 % i + 1; a2 = 22 % i + 1;
	}
	clock_t end = clock();
	return end - start;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

double LONG_Tests::add_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++)
	{
		a1 = 111 % i + 1; a2 = 22 % i + 1;

		a3 = a1 + a2; a4 = a2 + a3; a5 = a3 + a4; a6 = a4 + a5;
		a7 = a5 + a6; a8 = a6 + a7; a9 = a7 + a8; a10 = a8 + a9;
		a1 = a9 + a10; a2 = a10 + a1;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double LONG_Tests::subtr_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++)
	{
		a1 = 111 % i + 1; a2 = 22 % i + 1;

		a3 = a1 - a2; a4 = a2 - a3; a5 = a3 - a4; a6 = a4 - a5;
		a7 = a5 - a6; a8 = a6 - a7; a9 = a7 - a8; a10 = a8 - a9;
		a1 = a9 - a10; a2 = a10 - a1;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double LONG_Tests::mult_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++)
	{
		a1 = 111 % i + 1; a2 = 22 % i + 1;

		a3 = a1 * a2; a4 = a2 * a3; a5 = a3 * a4; a6 = a4 * a5;
		a7 = a5 * a6; a8 = a6 * a7; a9 = a7 * a8; a10 = a8 * a9;
		a1 = a9 * a10; a2 = a10 * a1;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double LONG_Tests::div_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++) {
		a1 = 10 % i + 1; a2 = 100 % i + 1; a3 = 10; a4 = 100; a5 = 1000; a6 = 10000; a7 = 100000; a8 = 1000000; a9 = 10000000; a10 = 100000000;

		a3 = a2 / a1; a6 = a5 / a4; a9 = a8 / a7; a2 = a1 / a10; a4 = a5 / a6;
		a5 = a7 / a6; a7 = a5 / a6; a8 = a7 / a6; a10 = a8 / a9; a1 = a10 / a9;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double LONG_Tests::empty_time()
{
	clock_t start = clock();
	unsigned long long i;
	for (i = 1; i < ITERATIONS; i++);
	{
		a1 = 111 % i + 1; a2 = 22 % i + 1;
	}
	clock_t end = clock();
	return end - start;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


double FLOAT_Tests::add_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++)
	{
		a1 = 111.3 + i + 1; a2 = 22.2 + i + 1;

		a3 = a1 + a2; a4 = a2 + a3; a5 = a3 + a4; a6 = a4 + a5;
		a7 = a5 + a6; a8 = a6 + a7; a9 = a7 + a8; a10 = a8 + a9;
		a1 = a9 + a10; a2 = a10 + a1;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double FLOAT_Tests::subtr_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++)
	{
		a1 = 111.3 + i + 1; a2 = 22.2 + i + 1;

		a3 = a1 - a2; a4 = a2 - a3; a5 = a3 - a4; a6 = a4 - a5;
		a7 = a5 - a6; a8 = a6 - a7; a9 = a7 - a8; a10 = a8 - a9;
		a1 = a9 - a10; a2 = a10 - a1;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double FLOAT_Tests::mult_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++)
	{
		a1 = 111.3 + i + 1; a2 = 22.2 + i + 1;

		a3 = a1 * a2; a4 = a2 * a3; a5 = a3 * a4; a6 = a4 * a5;
		a7 = a5 * a6; a8 = a6 * a7; a9 = a7 * a8; a10 = a8 * a9;
		a1 = a9 * a10; a2 = a10 * a1;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double FLOAT_Tests::div_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++) {
		a1 = 10 % i + 1; a2 = 100 % i + 1; a3 = 10; a4 = 100; a5 = 1000; a6 = 10000; a7 = 100000; a8 = 1000000; a9 = 10000000; a10 = 100000000;

		a3 = a2 / a1; a6 = a5 / a4; a9 = a8 / a7; a2 = a1 / a10; a4 = a5 / a6;
		a5 = a7 / a6; a7 = a5 / a6; a8 = a7 / a6; a10 = a8 / a9; a1 = a10 / a9;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double FLOAT_Tests::empty_time()
{
	clock_t start = clock();
	unsigned long long i;
	for (i = 1; i < ITERATIONS; i++);
	{
		a1 = 111.3 + i + 1; a2 = 22.2 + i + 1;
	}
	clock_t end = clock();
	return end - start;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double DOUBLE_Tests::add_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++)
	{
		a1 = 111.3 + i + 1; a2 = 22.2 + i + 1;

		a3 = a1 + a2; a4 = a2 + a3; a5 = a3 + a4; a6 = a4 + a5;
		a7 = a5 + a6; a8 = a6 + a7; a9 = a7 + a8; a10 = a8 + a9;
		a1 = a9 + a10; a2 = a10 + a1;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double DOUBLE_Tests::subtr_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++)
	{
		a1 = 111.3 + i + 1; a2 = 22.2 + i + 1;

		a3 = a1 - a2; a4 = a2 - a3; a5 = a3 - a4; a6 = a4 - a5;
		a7 = a5 - a6; a8 = a6 - a7; a9 = a7 - a8; a10 = a8 - a9;
		a1 = a9 - a10; a2 = a10 - a1;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double DOUBLE_Tests::mult_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++)
	{
		a1 = 111.3 + i + 1; a2 = 22.2 + i + 1;

		a3 = a1 * a2; a4 = a2 * a3; a5 = a3 * a4; a6 = a4 * a5;
		a7 = a5 * a6; a8 = a6 * a7; a9 = a7 * a8; a10 = a8 * a9;
		a1 = a9 * a10; a2 = a10 * a1;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double DOUBLE_Tests::div_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++) {
		a1 = 10 % i + 1; a2 = 100 % i + 1; a3 = 10; a4 = 100; a5 = 1000; a6 = 10000; a7 = 100000; a8 = 1000000; a9 = 10000000; a10 = 100000000;

		a3 = a2 / a1; a6 = a5 / a4; a9 = a8 / a7; a2 = a1 / a10; a4 = a5 / a6;
		a5 = a7 / a6; a7 = a5 / a6; a8 = a7 / a6; a10 = a8 / a9; a1 = a10 / a9;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double DOUBLE_Tests::empty_time()
{
	clock_t start = clock();
	unsigned long long i;
	for (i = 1; i < ITERATIONS; i++);
	{
		a1 = 111.3 + i + 1; a2 = 22.2 + i + 1;
	}
	clock_t end = clock();
	return end - start;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double CHAR_Tests::add_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++)
	{
		a1 = 111 % i + 1; a2 = 22 % i + 1;

		a3 = a1 + a2; a4 = a2 + a3; a5 = a3 + a4; a6 = a4 + a5;
		a7 = a5 + a6; a8 = a6 + a7; a9 = a7 + a8; a10 = a8 + a9;
		a1 = a9 + a10; a2 = a10 + a1;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double CHAR_Tests::subtr_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++)
	{
		a1 = 111 % i + 1; a2 = 22 % i + 1;

		a3 = a1 - a2; a4 = a2 - a3; a5 = a3 - a4; a6 = a4 - a5;
		a7 = a5 - a6; a8 = a6 - a7; a9 = a7 - a8; a10 = a8 - a9;
		a1 = a9 - a10; a2 = a10 - a1;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double CHAR_Tests::mult_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++)
	{
		a1 = 111 % i + 1; a2 = 22 % i + 1;

		a3 = a1 * a2; a4 = a2 * a3; a5 = a3 * a4; a6 = a4 * a5;
		a7 = a5 * a6; a8 = a6 * a7; a9 = a7 * a8; a10 = a8 * a9;
		a1 = a9 * a10; a2 = a10 * a1;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double CHAR_Tests::div_time()
{
	clock_t start = clock();
	for (unsigned long long i = 1; i < ITERATIONS; i++) {
		a1 = 111 % i + 1; a2 = 22 % i + 1; a3 = 333; a4 = 4444; a5 = 555; a6 = 666; a7 = 77; a8 = 888888; a9 = 9999999; a10 = 101;

		a4 = a2 / a10; a5 = a3 / a1; a4 = a5 / a1; a3 = a6 / a2; a3 = a8 / a1;
		a1 = a10 / a2; a10 = a9 / a1; a7 = a6 / a1; a8 = a7 / a1; a6 = a8 / a2;
	}
	clock_t end = clock();
	return end - start - empty_time();
}

double CHAR_Tests::empty_time()
{
	clock_t start = clock();
	unsigned long long i;
	for (i = 1; i < ITERATIONS; i++);
	{
		a1 = 111 % i + 1; a2 = 22 % i + 1;
	}
	clock_t end = clock();
	return end - start;
}

