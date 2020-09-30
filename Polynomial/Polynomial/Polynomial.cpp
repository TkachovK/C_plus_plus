#include <windows.h>
#include "Header.h"
int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, m, number, count, q;
	double p;
	cout << "Выберите : 1--ввод/вывод данных с помощью текстовых файлов\n 2--ввод/вывод данных с помощью консоли : "; cin >> count;
	switch (count)
	{
	case 1:
	{

		ifstream fin("E:\\test\\input.txt");
		if (fin)
		{
			while (!fin.eof())
			{

				cout << "Степень полинома A: ";
				fin >> n;
				cout << n << endl;
				cout << "Степень полинома B: ";
				fin >> m;
				cout << m << endl;
			}
			fin.close();
		}
		Polynom A(n), B(m), C(0), D, Y, X, Z, W, Q;
		ifstream fin2("E:\\test\\input2.txt");
		if (fin2)
		{
			while (!fin2.eof())
			{
				cout << "Коэфициенты полинома A: ";
				fin2 >> A;
				cout << A << endl;
				cout << "Коэфициенты полинома B: ";
				fin2 >> B;
				cout << B << endl;
				cout << "Константа С для умножения на полином A: " << endl;
				fin2 >> C;
				cout << C << endl;
				cout << "Константа о для возведения в степень полинома А:" << endl;
				fin2 >> p;
				cout << p << endl;
				cout << "Константа q для импользования псевдопеременной типа А(3, 5) = q:" << endl;
				fin2 >> q;
				cout << q << endl;
			}
			fin2.close();
		}
		ofstream fout;
		fout.open("E:\\test\\output.txt");
		do
		{
			cout << "1. Полином А" << endl;
			cout << "2. Полином В" << endl;
			cout << "3. Сумма полиномов" << endl;
			cout << "4. Произведение полиномов А и В" << endl;
			cout << "5. Умножение полинома на константу" << endl;
			cout << "6. Возведение полинома в степень" << endl;
			cout << "7. Деление полинома А на В" << endl;
			cout << "8. Псевдопеременная А(3, 5) = 9" << endl;
			cout << "9. Выход" << endl;
			cout << "Номер команды > "; cin >> number;
			switch (number)
			{
			case 1:
				cout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				fout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				break;
			case 2:
				cout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				fout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				break;
			case 3:
				cout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				cout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				cout << setw(17) << "Многочлен D=A+B:" << setw(5) << (D = A + B) << endl;
				fout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				fout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				fout << setw(17) << "Многочлен D=A+B:" << setw(5) << (D = A + B) << endl;
				break;
			case 4:
				cout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				cout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				cout << setw(17) << "Многочлен Y=A*B:" << setw(5) << (Y = A * B) << endl;
				fout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				fout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				fout << setw(17) << "Многочлен Y=A*B:" << setw(5) << (Y = A * B) << endl;
				break;
				break;
			case 5:
				cout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				cout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				cout << setw(17) << "Константа c:" << setw(5) << C << endl;
				cout << setw(17) << "Многочлен X=A*c:" << setw(5) << (X = A * C) << endl;
				fout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				fout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				fout << setw(17) << "Константа c:" << setw(5) << C << endl;
				fout << setw(17) << "Многочлен X=A*c:" << setw(5) << (X = A * C) << endl;
				break;
			case 6:
				cout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				cout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				cout << setw(17) << "Константа o:" << setw(5) << p << endl;
				cout << setw(17) << "Многочлен Z=A^o:" << setw(5) << (Z = A ^ p) << endl;
				fout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				fout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				fout << setw(17) << "Константа o:" << setw(5) << p << endl;
				fout << setw(17) << "Многочлен Z=A^o:" << setw(5) << (Z = A ^ p) << endl;
				break;
			case 7:
				cout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				cout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				cout << setw(17) << "Многочлен W=A/B:" << setw(5) << (W = A / B) << endl;
				fout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				fout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				fout << setw(17) << "Многочлен W=A/B:" << setw(5) << (W = A / B) << endl;
				break;
			case 8:
				cout << "Введите константу q для импользования псевдопеременной типа А(3, 5) = q:" << endl;
				Q = A(3, 5) = q;
				cout << Q << endl;
				break;
			case 9:
				break;
			default:
				cout << endl << "Команда не определена\n\n";
				break;
			}
		} while (number != 9);
		fout.close();
		break;
	}
	case 2:
	{
		cout << "Введите степень полинома A:" << endl;
		cin >> n;
		cout << "Введите степень полинома B:" << endl;
		cin >> m;
		Polynom A(n), B(m), C(0), D, Y, X, Z, W, Q;
		cout << "Введите коэфициенты полинома A: " << endl;
		cin >> A;
		cout << "Введите коэфициенты полинома B: " << endl;
		cin >> B;
		system("cls");
		do
		{
			cout << "1. Полином А" << endl;
			cout << "2. Полином В" << endl;
			cout << "3. Сумма полиномов" << endl;
			cout << "4. Произведение полиномов А и В" << endl;
			cout << "5. Умножение полинома на константу" << endl;
			cout << "6. Возведение полинома в степень" << endl;
			cout << "7. Деление полинома А на В" << endl;
			cout << "8. Псевдопеременная А(3, 5) = 9" << endl;
			cout << "9. Выход" << endl;
			cout << "Номер команды > "; cin >> number;
			switch (number)
			{
			case 1:
				cout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				break;
			case 2:
				cout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				break;
			case 3:
				cout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				cout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				cout << setw(17) << "Многочлен D=A+B:" << setw(5) << (D = A + B) << endl;
				break;
			case 4:
				cout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				cout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				cout << setw(17) << "Многочлен Y=A*B:" << setw(5) << (Y = A * B) << endl;
				break;
			case 5:
				cout << "Введите константу С для умножения на полином A: " << endl;
				cin >> C;
				cout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				cout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				cout << setw(17) << "Константа c:" << setw(5) << C << endl;
				cout << setw(17) << "Многочлен X=A*c:" << setw(5) << (X = A * C) << endl;
				break;
			case 6:
				cout << "Введите константу о для возведения в степень полинома А:" << endl;
				cin >> p;
				cout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				cout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				cout << setw(17) << "Константа o:" << setw(5) << p << endl;
				cout << setw(17) << "Многочлен Z=A^o:" << setw(5) << (Z = A ^ p) << endl;
				break;
			case 7:
				cout << setw(17) << "Многочлен А:" << setw(5) << A << endl;
				cout << setw(17) << "Многочлен B:" << setw(5) << B << endl;
				cout << setw(17) << "Многочлен W=A/B:" << setw(5) << (W = A / B) << endl;
				break;
			case 8:
				cout << "Введите константу q для импользования псевдопеременной типа А(3, 5) = q:" << endl;
				cin >> q;
				Q = A(3, 5) = q;
				cout << Q << endl;
				break;
			case 9:
				break;
			default:
				cout << endl << "Команда не определена\n\n";
				break;
			}
		} while (number != 9);
		break;
	}
	default:
	{
		cout << endl << "Команда не определена\n\n";
		break;
	}
	}
	return 0;
}