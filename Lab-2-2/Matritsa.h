//����� - �������� �����, �-13, ������ 156
#pragma once

class Matritsa
{
public:
	bool create(int N);
	//������� create � ��� �������� ��������� 
	//���������� ��, � ������ - ������ ������ false.
	//���� �������� �������� ������ �� ������� true, 
	int getSize() const;
	//������� getSize ������� ��������� �������.
	bool null(int N) const;
	//������� null �������� �� ������� �������. ������� false, ���� ���.
	int &get_i_j(int i, int j);
	//������� get_i_j ���� ������ ������ �� (i, j)-�� �������� �������.
private:
	static const int dim = 30;
	int mas[dim][dim]{};
	int N = 0;
};

void writeMatritsa(Matritsa &m);
//������� writeMatritsa �������� �������� �������.

void findSpiral(Matritsa &m);
//������� friteSpiral ������� ������� ����� ������
//�� ������ ����� �������� ������� ����������� � writeSpiral.

//������� writeSpiral ������ �������� ������� �� findSpiral ��� �����. 
//���� ������ ���� �������, ������� ��������� ��������, ���������
//"��������� ����������" �� ������ ����� ��� �������� break �� continue

//������� output �������� ������� ����� � �������� ����������
