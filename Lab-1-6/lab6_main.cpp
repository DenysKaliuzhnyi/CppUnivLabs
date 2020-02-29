//Автор - Калюжний Денис, К-13, Варіант 156
#include <iostream>
#include "sortmas.h"
#include "../copyright/copyright.h"
using namespace std;

bool choose(int mas[], int &N)
{
	int type;
	cout << "Оберiть режим заповнення масиву. Натиснiть \"1\", якщо бажаєте заповнити масив "
		<< "автоматично або \"2\", якщо бажаєте заповнити масив вручну: ";
	cin >> type;
	if (type == 1)
	{
		return readArray1(mas, N);
	}
	else if (type == 2)
	{
		readArray2(mas, N);
		return true;
	}
	else cout << "Натиснiть 1 або 2!" << endl;
	return false;
}

int main()
{
	int mas[1000], N;
	setlocale(LC_CTYPE, "rus");
	copyright();
	cout << "Ця програма обчислює суму мiнiмального та максимального елементiв масива, "
		<< "який був введений користувачем самостiйно або сгенерован автоматично." << endl;
	if (choose(mas, N))
	{
		coutArray(mas, N);
		cout << "Сумa мiнiмального та максимального елементiв масива sum = " << printMas5(mas, N)<<endl;
	}
	system("pause");
}