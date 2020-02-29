#pragma once
#include <iomanip>
#include <string>
#include <algorithm>

const unsigned long long ITERATIONS = 10000000;
class INT_Tests
{
	int a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	double empty_time();
public:
	double add_time();
	double subtr_time();
	double mult_time();
	double div_time();
};

class LONG_Tests
{
	long a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	double empty_time();
public:
	double add_time();
	double subtr_time();
	double mult_time();
	double div_time();
};

class DOUBLE_Tests
{
	double a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	double empty_time();
public:
	double add_time();
	double subtr_time();
	double mult_time();
	double div_time();
};

class FLOAT_Tests
{
	float a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	double empty_time();
public:
	double add_time();
	double subtr_time();
	double mult_time();
	double div_time();
};


class CHAR_Tests
{
	char a1 = 111, a2 = 22, a3 = 333, a4 = 4444, a5 = 555, a6 = 666, a7 = 77, a8 = 888888, a9 = 9999999, a10 = 101;
	double empty_time();
public:
	double add_time();
	double subtr_time();
	double mult_time();
	double div_time();
};
