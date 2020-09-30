//#include "stdafx.h"
#include "Header.h"
#include <cassert>
using namespace std;
Polynom::Polynom()//Конструктор по умолчанию
{
	koef = NULL;
}
double& Polynom::operator[] (const int index)//перегрузка []
{
	return koef[index];
}
double* Polynom::operator->() const //?
{
	return koef;
}
Polynom::Polynom(int an)//Конструктор с параметрами
{
	n = an;
	x = 0;
	y = 0;
	koef = new double[n + 1];
	for (int i = 0; i <= n; i++)
	{
		koef[i] = 0;
	}
}
Polynom::Polynom(const Polynom& f)//Конструктор копирования
{
	n = f.n;
	x = f.x;
	y = f.y;
	koef = new double[n + 1];
	for (int i = 0; i <= n; i++)
		koef[i] = f.koef[i];
}
Polynom::~Polynom()//Деструктор
{
	delete[]koef;
}
Polynom Polynom::operator+(const Polynom& t)//оператор сложения A+B
{
	Polynom Z = *this;
	for (int i = 0; i <= n; i++)
		Z.koef[i] = koef[i] + t.koef[i];
	return Z;

}
Polynom Polynom::operator/(Polynom& t)//Оператор деления А/В
{

	bool inAlgoritm = true;

	Polynom temp;
	Polynom ob_1;
	Polynom ob_2;
	Polynom ob_4;

	temp.n = n - t.n;
	temp.koef = new double[temp.n + 1];
	memset(temp.koef, 0, (temp.n + 1) * sizeof(double));

	ob_1.n = n;
	ob_1.koef = new double[n + 1];
	for (int i = n; i >= 0; i--)
		ob_1.koef[i] = koef[i];

	ob_2.n = t.n;
	ob_2.koef = new double[t.n + 1];
	for (int i = t.n; i >= 0; i--)
		ob_2.koef[i] = t.koef[i];

	ob_4.n = ob_1.n;
	ob_4.koef = new double[ob_1.n + 1];

	double mnojnik;
	int k = 0;
	int i, j;
	while (inAlgoritm)
	{
		for (int i = t.n; i >= 0; i--)
			ob_4.koef[i] = t.koef[i];
		if (ob_2.n < ob_1.n)
		{
			for (i = ob_1.n, j = ob_2.n; i >= 0; i--, j--)
				if (j < 0)
					ob_4.koef[i] = 0;
				else
					ob_4.koef[i] = ob_2.koef[j];
		}
		mnojnik = ob_1.koef[ob_1.n] / ob_4.koef[ob_1.n];
		temp.koef[temp.n - k] = mnojnik;
		k++;
		for (int i = 0; i <= ob_1.n; i++)
			ob_4.koef[i] *= mnojnik;
		for (int i = 0; i <= ob_1.n; i++)
			ob_1.koef[i] -= ob_4.koef[i];
		ob_1.n--;
		if (ob_2.n > ob_1.n) inAlgoritm = false;
	}

	return temp;

}
Polynom Polynom::operator*(const Polynom& t)//оператор умножения А*В
{
	//s=0;
	Polynom Y(n + t.n);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= t.n; j++)
			Y.koef[i + j] += koef[i] * t.koef[j];
	return Y;
}
Polynom Polynom::operator= (const Polynom& t)//Оператор присваивания
{
	if (this != &t)
	{
		delete[] koef;
		n = t.n;
		x = t.x;
		y = t.y;
		koef = new double[n + 1];
		for (int i = 0; i <= n; i++)
			koef[i] = t.koef[i];
	}
	return *this;
}
Polynom Polynom::operator= (int an)
{
	Polynom X(n);
	X = *this;
	for (int i = n; i >= 0; i--)
	{
		if (i >= X.x && i <= X.y)
		{
			X.koef[i] = an;
		}
	}
	return X;
}
Polynom Polynom::operator()(int i, int j)
{
	Polynom X(n);
	X = *this;
	X.x = i;
	X.y = j;
	return X;
}
istream& operator>>(istream& s, Polynom& c)// перегруженный оператор ввода
{
	for (int i = 0; i <= c.n; i++)
	{
		s >> c.koef[i];
	}
	return s;
}
ostream& operator<<(ostream& s, const Polynom& c)// перегруженный оператор вывода
{
	int i, n = 0;
	for (i = 0; i <= c.n; i++)
	{
		if (c.koef[i] != 0)
			n++;
	}
	if (n != 0)
	{
		if (c.koef[0] != 0)
		{
			s << c.koef[0];
		}
		for (i = 1; i <= c.n; i++)
		{
			if (c.koef[i] < 0)
			{
				if (c.koef[i] != -1)
					s << c.koef[i] << "X^" << i;
				else
					s << "-" << "X^" << i;
			}
			else
			{
				if (c.koef[i] != 0)
				{
					if (c.koef[i] != 1)
						s << "+" << c.koef[i] << "X^" << i;
					else
						s << "+" << "X^" << i;
				}
			}
		}

		s << '\n';
	}
	else
	{
		s << 0;
	}
	return s;
}
Polynom Polynom::operator^(double no)//Оператор возведения в степень
{
	Polynom Y(n * no);
	Y = *this;
	for (int i = 0; i < no - 1; i++)
		Y = *this * Y;
	return Y;
}