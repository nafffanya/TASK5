// TASK 5 коробова.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <locale>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	//Локализация программы
	setlocale(LC_ALL, "rus");

	//Ввод размера массива с проверкой ввода
	//(если будет неккоректный ввод, то выведется предупреждение и ввод продолжится)
	cout << "Условие задачи:Дан массив ненулевых целых чисел размера N.\n Проверить, чередуются ли в нем четные и нечетные числа.\n Если чередуются, то вывести 0, если нет, то вывести номер первого элемента, нарушающего закономерность.\n ";
	char menu = 0;
	cout << "Если хотите запустить программу, введите 1. Если хотите завершить программу, введите 0 \n";
	cin >> menu; // Ввожу 1 или 0
	while (menu == '1')
	{
		cout << "Введите размер массива N=";
		int(N);
		cin >> N;
		while (cin.fail() || N < 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << ("\tНеверный ввод, повторите.(N>0)\n");
			cout << ("размер массива N= ");
			cin >> N;
		}

		//Ввод левой гарницы рандомных значений с проверкой ввода
		cout << "Введите левую границу диапозона,min=";
		int mind;
		cin >> mind;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << ("\tНеверный ввод, повторите.\n");
			cin >> mind;
		}

		//Ввод правой гарницы рандомных значений с проверкой ввода
		cout << "Введите правую границу диапозона,max=";
		int maxd;
		cin >> maxd;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << ("\tНеверный ввод, повторите.\n");
			cin >> maxd;
		}
		cout << endl;

		//создание динамического массива
		int* arr = new int[N];

		//задаем начальную точку для функции rand()
		srand(time(0));

		// задаём рандомно массив(без нулевых элементов)
		for (int i = 0; i < N; i++)
		{
			int temp = (double)rand() * (maxd - mind) / RAND_MAX + mind;
			while (temp == 0)
			{
				temp = (double)rand() * (maxd - mind) / RAND_MAX + mind;
			}
			arr[i] = temp;
		}

		//вывод массива на экран
		cout << "Исходный массив :\n";

		for (int i = 0; i < N; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;


		//Определение чередования строк
		//1)Определяем чётность первого элемента
		//2)В зависимости от чётности первого элемента начинаем дальнейшую проверку

		bool flag = bool(arr[0] % 2);
		int position = 0;

		if (flag)
		{
			for (int i = 1; i <= N - 1; i += 2)
			{
				if (arr[i] % 2 == 0)
				{
					if (N > 2)
					{
						if (arr[i + 1] % 2 == 1)
						{
							continue;
						}
						else
						{
							position = i + 2;
							break;
						}
					}
				}
				else
				{
					position = i + 1;
					break;
				}
			}
		}
		else
		{
			for (int i = 1; i <= N - 1; i += 2)
			{
				if (arr[i] % 2 == 1)
				{
					if (N > 2)
					{
						if (arr[i + 1] % 2 == 0)
						{
							continue;
						}
						else
						{
							position = i + 2;
							break;
						}
					}
				}
				else
				{
					position = i + 1;
					break;
				}
			}
		}

		//вывод результата
		if (position == 0)
		{
			cout << "Числа в массиве чередуются, 0";
		}
		else
		{
			cout << "Номер элемента , который нарушает чередование , " << position << "\n";
		}

		//освобождение выделенной памяти под динамический массив
		delete[]arr;

		cout << "Если хотите запустить программу, введите 1. Если хотите завершить программу, введите 0 \n";
		cin >> menu;
		if (menu != '1') break;
	}
}