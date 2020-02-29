//Автор - Калюжний Денис, К-13, Варіант 156
#pragma once

class Matritsa
{
public:
	bool create(int N);
	//Функція create у разі коректної розмірності 
	//встановлює її, а інакше - поверає одразу false.
	//Потім заповнює маттрицю нулями та повертає true, 
	int getSize() const;
	//Функція getSize повертає розмірність матриці.
	bool null(int N) const;
	//Функція null перевіряє чи порожня матриця. Повератє false, якщо так.
	int &get_i_j(int i, int j);
	//Функція get_i_j надає прямий доступ до (i, j)-го елемента матриці.
private:
	static const int dim = 30;
	int mas[dim][dim]{};
	int N = 0;
};

void writeMatritsa(Matritsa &m);
//Функція writeMatritsa виводить отриману матрицю.

void findSpiral(Matritsa &m);
//Функція friteSpiral обходть матрицю згідно варінту
//та передає кожен поточний елемент послідовності у writeSpiral.

//Функція writeSpiral отримує елементи матриці від findSpiral для друку. 
//Вона приймає саму матрицю, індекси поточного елемента, розмірність
//"поточного трикутника" та булеву змінну щоб уникнути break та continue

//Функція output виводить елемент спіралі з потрібним інтервалом
