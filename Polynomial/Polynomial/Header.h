#pragma once
#include <iostream>
#include<iomanip>
#include<fstream>
using namespace std;
class Polynom
{
private:
	int x, y;//дл€ функтора
	int n; //степень полинома
	double* koef; //указатель на массив коэффициентов полинома koef[i] - коэффициент при i-й степени
public:
	Polynom();
	Polynom(int an);//конструктор с параметрами
	Polynom(const Polynom&); //копировани€
	~Polynom();//деструктор
	Polynom operator+(const Polynom&);   //оператор сложени€ двух полиномов
	Polynom operator*(const Polynom&);// оператор умножени€
	Polynom operator/(Polynom&);// оператор делени€
	Polynom operator^(double no);// оператор степени
	Polynom operator=(const Polynom&);   //оператор присваивани€
	Polynom operator = (int an);
	friend ostream& operator<< (ostream& s, const Polynom& c); // перегруженный оператор вывода
	friend istream& operator >> (istream& s, Polynom& c); // перегруженный оператор ввода
	double& operator[] (const int index);//перегрузка оператора []
	double* operator->() const;
	Polynom operator()(int i, int j);
};