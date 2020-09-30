#pragma once
#include <iostream>
#include<iomanip>
#include<fstream>
using namespace std;
class Polynom
{
private:
	int x, y;//��� ��������
	int n; //������� ��������
	double* koef; //��������� �� ������ ������������� �������� koef[i] - ����������� ��� i-� �������
public:
	Polynom();
	Polynom(int an);//����������� � �����������
	Polynom(const Polynom&); //�����������
	~Polynom();//����������
	Polynom operator+(const Polynom&);   //�������� �������� ���� ���������
	Polynom operator*(const Polynom&);// �������� ���������
	Polynom operator/(Polynom&);// �������� �������
	Polynom operator^(double no);// �������� �������
	Polynom operator=(const Polynom&);   //�������� ������������
	Polynom operator = (int an);
	friend ostream& operator<< (ostream& s, const Polynom& c); // ������������� �������� ������
	friend istream& operator >> (istream& s, Polynom& c); // ������������� �������� �����
	double& operator[] (const int index);//���������� ��������� []
	double* operator->() const;
	Polynom operator()(int i, int j);
};