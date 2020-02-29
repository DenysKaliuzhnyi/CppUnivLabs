#include <iostream>
#include <string>
#include "Tests.h"
using namespace std;

const double TACT_PER_SECOND = CLOCKS_PER_SEC;
const unsigned OPERATIONS = 10;
void output(const string &ssign, const string &stype, double duration_sec, double BEST_TIME_EVER);
void print_table_stats();

int main()
{
	print_table_stats();
	system("PAUSE");
	return 0;
}


void print_table_stats()
{
	const double ADD_TIME_INT = INT_Tests().add_time();
	const double SUBTR_TIME_INT = INT_Tests().subtr_time();
	const double MULT_TIME_INT = INT_Tests().mult_time();
	const double DIV_TIME_INT = INT_Tests().div_time();

	const double ADD_TIME_LONG = LONG_Tests().add_time();
	const double SUBTR_TIME_LONG = LONG_Tests().subtr_time();
	const double MULT_TIME_LONG = LONG_Tests().mult_time();
	const double DIV_TIME_LONG = LONG_Tests().div_time();

	const double ADD_TIME_DOUBLE = DOUBLE_Tests().add_time();
	const double SUBTR_TIME_DOUBLE = DOUBLE_Tests().subtr_time();
	const double MULT_TIME_DOUBLE = DOUBLE_Tests().mult_time();
	const double DIV_TIME_DOUBLE = DOUBLE_Tests().div_time();

	const double ADD_TIME_FLOAT = FLOAT_Tests().add_time();
	const double SUBTR_TIME_FLOAT = FLOAT_Tests().subtr_time();
	const double MULT_TIME_FLOAT = FLOAT_Tests().mult_time();
	const double DIV_TIME_FLOAT = FLOAT_Tests().div_time();

	const double ADD_TIME_CHAR = CHAR_Tests().add_time();
	const double SUBTR_TIME_CHAR = CHAR_Tests().subtr_time();
	const double MULT_TIME_CHAR = CHAR_Tests().mult_time();
	const double DIV_TIME_CHAR = CHAR_Tests().div_time();

	const double BEST_TIME_INT = min(min(SUBTR_TIME_INT, MULT_TIME_INT), min(ADD_TIME_INT, DIV_TIME_INT));
	const double BEST_TIME_LONG = min(min(SUBTR_TIME_LONG, MULT_TIME_LONG), min(ADD_TIME_LONG, DIV_TIME_LONG));
	const double BEST_TIME_DOUBLE = min(min(SUBTR_TIME_DOUBLE, MULT_TIME_DOUBLE), min(ADD_TIME_DOUBLE, DIV_TIME_DOUBLE));
	const double BEST_TIME_FLOAT = min(min(SUBTR_TIME_FLOAT, MULT_TIME_FLOAT), min(ADD_TIME_FLOAT, DIV_TIME_FLOAT));
	const double BEST_TIME_CHAR = min(min(SUBTR_TIME_CHAR, MULT_TIME_CHAR), min(ADD_TIME_CHAR, DIV_TIME_CHAR));
	const double BEST_TIME_EVER = min(BEST_TIME_INT, min(min(BEST_TIME_LONG, BEST_TIME_DOUBLE), min(BEST_TIME_FLOAT, BEST_TIME_CHAR)));

	output("+", "int", ADD_TIME_INT, BEST_TIME_EVER);
	output("-", "int", SUBTR_TIME_INT, BEST_TIME_EVER);
	output("*", "int", MULT_TIME_INT, BEST_TIME_EVER);
	output("/", "int", DIV_TIME_INT, BEST_TIME_EVER);
	cout << endl << endl;
	output("+", "long", ADD_TIME_LONG, BEST_TIME_EVER);
	output("-", "long", SUBTR_TIME_LONG, BEST_TIME_EVER);
	output("*", "long", MULT_TIME_LONG, BEST_TIME_EVER);
	output("/", "long", DIV_TIME_LONG, BEST_TIME_EVER);
	cout << endl << endl;
	output("+", "double", ADD_TIME_DOUBLE, BEST_TIME_EVER);
	output("-", "double", SUBTR_TIME_DOUBLE, BEST_TIME_EVER);
	output("*", "double", MULT_TIME_DOUBLE, BEST_TIME_EVER);
	output("/", "double", DIV_TIME_DOUBLE, BEST_TIME_EVER);
	cout << endl << endl;
	output("+", "float", ADD_TIME_FLOAT, BEST_TIME_EVER);
	output("-", "float", SUBTR_TIME_FLOAT, BEST_TIME_EVER);
	output("*", "float", MULT_TIME_FLOAT, BEST_TIME_EVER);
	output("/", "float", DIV_TIME_FLOAT, BEST_TIME_EVER);
	cout << endl << endl;
	output("+", "char", ADD_TIME_CHAR, BEST_TIME_EVER);
	output("-", "char", SUBTR_TIME_CHAR, BEST_TIME_EVER);
	output("*", "char", MULT_TIME_CHAR, BEST_TIME_EVER);
	output("/", "char", DIV_TIME_CHAR, BEST_TIME_EVER);
}

void output(const string &ssign, const string &stype, double duration_sec, double BEST_TIME_EVER)
{
	double oper_per_sec = ITERATIONS * OPERATIONS * TACT_PER_SECOND / duration_sec;
	cout << ssign << '\t' << stype << "\t\t" << int(oper_per_sec) << '\t';
	double percent = BEST_TIME_EVER / duration_sec * 100;
	for (int i = 0; i < 50; i++)
	{
		if (i < int(percent) / 2) cout << 'X';
		else cout << ' ';
	}
	cout << '\t' << int(percent) << endl << endl;
}


