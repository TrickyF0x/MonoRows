#include "pch.h"
#include <vector> //вектор (используем как динамический массив)
#include <Windows.h>
#include <iostream>

void monotonous_arr();
bool is_digit(const char *S, int size);

int main()
{
	SetConsoleCP(1251);//для корректного отображения в консоли кириллицы
	SetConsoleOutputCP(1251);
	monotonous_arr();

	std::system("pause");
	return 0;
}

bool is_digit(const char *S, int size) {
	const char *temp = "0123456789-";
	unsigned point_count = 0;

	for (int i = 0; i < strlen(S); i++) {
		if ((i > 0) && (S[i] == '+' || S[i] == '-')) return false;
		if (strlen(S) >= size) return false;
		if (size == 5)
		{
			if (S[0] == '0') return false;
			if (S[0] == '-') return false;
		}
		if (S[i] == '.') {
		/*	point_count++;
			if (point_count > 1)*/ return false;
		}
		if (!strchr(temp, S[i])) return false;
	}
	return true;
}

void monotonous_arr()
{
	int i, j, n;
	int flag = 0, rows = 0;
	char s[256];

	printf("Введите размер: ");
	std::cin.getline(s, 256);
	while (!is_digit(s, 5)) {
		std::cerr << "Некорректный ввод\nВведите размер: ";
		std::cin.getline(s, 256);
	}
	n = atof(s);

	int **mainArr = new int*[n];// создание двум. дин. массива
	std::vector<int> buffArr;
	for (i = 0; i < n; ++i)
	{
		mainArr[i] = new int[n];
	}
	/////////////////////////////////////заполнение и вывод основного
	for (i = 0; i < n; ++i)//заполнение основного массива
	{
		for (j = 0; j < n; ++j)
		{
			printf("Введите [%d][%d] элемент ", i + 1, j + 1);
			std::cin.getline(s, 256);
			while (!is_digit(s, 9)) {
				std::cerr << "Некорректный ввод\nВведите [" << i + 1 << "][" << j + 1 << "] элемент: ";
				std::cin.getline(s, 256);
			}
			mainArr[i][j] = atof(s);
		}
	}
	printf("Основной массив\n");
	for (i = 0; i < n; ++i)//вывод основного массива
	{
		printf("%d) ", i + 1);
		for (j = 0; j < n; ++j)
		{
			printf("%d\t", mainArr[i][j]);
		}
		printf("\n");
	}
	///////////////////////////////////////проверка на монотонность и вывод дополнительного
	i = 0;
	while (i < n)//проверка на монотонность
	{
		j = 0;
		while (j < n - 1)//возрастающий?
		{
			if (mainArr[i][j] < mainArr[i][j + 1])
			{
				++j;
			}
			else
			{
				break;
			}
			if (j == n - 1)
			{
				++rows;
				buffArr.push_back(i);
				break;
			}
		}
		j = 0;
		while (j < n - 1)//убывающий?
		{
			if (mainArr[i][j] > mainArr[i][j + 1])
			{
				++j;
			}
			else
			{
				break;
			}
			if (j == n - 1)
			{
				++rows;
				buffArr.push_back(i);
				break;
			}
		}
		++i;
	}
	if (rows == n)//если весь массив монотонный
	{
		printf("Все строки монотонны. (См. матрицу выше)\n");
	}
	else if (rows != 0)
	{
		printf("№ монотонных строк - ", buffArr[i]);
		for (i = 0; i < rows; ++i)
			printf("(%d) ", buffArr[i] + 1);// монотонные строки
	}
	if ((rows > 1) && (rows != n))//если строк больше 1 и не полностью монотонный
	{
		int **secArr = new int*[rows];// создание двум. дин. массива второго
		for (i = 0; i < n; ++i)
		{
			secArr[i] = new int[n];
		}
		for (i = 0; i < rows; ++i)//заполнение второго массива
		{
			for (j = 0; j < n; ++j)
			{
				secArr[i][j] = mainArr[buffArr[i]][j];
			}
		}
		printf("\nСозданный массив\n");
		for (i = 0; i < rows; ++i)//вывод второго массива
		{
			printf("%d) ", i + 1);
			for (j = 0; j < n; ++j)
			{
				printf("%d\t", secArr[i][j]);
			}
			printf("\n");
		}
		/*	for (int i = 0; i < n; ++i)//освобождение памяти второго
		{
		delete[] secArr[i];
		}
		delete[] secArr;*/
	}
	else if (rows == 1)//eсли строка 1
	{
		int *secArr = new int;//создание дин. второго

		for (i = 0; i < n; ++i)
		{
			secArr[i] = mainArr[buffArr[0]][i];
		}

		printf("Созданный массив\n");
		for (i = 0; i < n; ++i)//вывод второго
		{
			printf("%d\t", secArr[i]);
		}
		printf("\n");
		//	delete[] secArr;//освобождение памяти второго
	}
	else if (rows == 0)
		printf("Нет мнотонных строк\n");//если нет монотонных 
//////////////////////////////////////освобождение памяти доп. и основного
	for (int i = 0; i < n; ++i)
	{
		delete[] mainArr[i];
	}
	delete[] mainArr;
}