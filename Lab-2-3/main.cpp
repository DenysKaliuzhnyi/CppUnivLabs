//Автор - Калюжний Денис, К-13, Варіант 156
#include <iostream>
#include "input_output.h"
#include "Greenhouse_156.h"
#include "../copyright/copyright.h"

int main()
{
	setlocale(LC_CTYPE, "rus");
	copyright();
	Info();
	Greenhouse_156 a;
	if (a.check_start()) Do_action(a);
	else std::cout << "ERROR: unreal value in constructor!!!"<< std::endl;
	system("pause");
	return 0;
}


