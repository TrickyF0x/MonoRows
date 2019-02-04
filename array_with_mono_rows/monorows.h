#pragma once
#include <vector>
#include <iostream>

class MonoRows
{
public:
	MonoRows();

	int size;
	char s[256];
	int** mainArr = new int*[size];

	void set_size()//set input array size
	{
		printf("Введите размер: ");
		std::cin.getline(s, 256);
		while (!is_digit(s, 5)) 
		{
			std::cerr << "Некорректный ввод\nВведите размер: ";
			std::cin.getline(s, 256);
		}
		size = atof(s);
	};

	int get_size() // get input array size
	{
		return size;
	};

	void set_values()//set input array values
	{
		int i, j, n = size;
		for (i = 0; i < n; ++i)
			mainArr[i] = new int[n];

		for (i = 0; i < n; ++i)//array input
		{
			for (j = 0; j < n; ++j)
			{
				printf("Введите [%d][%d] элемент ", i + 1, j + 1);
				std::cin.getline(s, 256);
				while (!is_digit(s, 9)) 
				{
					std::cerr << "Некорректный ввод\nВведите [" << i + 1 << "][" << j + 1 << "] элемент: ";
					std::cin.getline(s, 256);
				}
				mainArr[i][j] = atof(s);
			}
		}
	};

	int** get_values()//get inputed array
	{
		return mainArr;
	};

	int ** get_mono_rows(int n_size, int** input_array)
	{
		int i, j, n = n_size;
		int flag = 0, rows = 0;		
		std::vector<int> buffArr;

		i = 0;
		while (i < n)//monotonous checking
		{	
			j = 0;
			while (j < n - 1)//raise?
			{
				if (mainArr[i][j] < mainArr[i][j + 1])
					++j;
				else
					break;
				if (j == n - 1)
				{
					++rows;
					buffArr.push_back(i);
					break;
				}
			}
			j = 0;
			while (j < n - 1)//decrease?
			{
				if (mainArr[i][j] > mainArr[i][j + 1])
					++j;
				else
					break;
				if (j == n - 1)
				{
					++rows;
					buffArr.push_back(i);
					break;
				}
			}
			++i;
		}
		if (rows == n)//all rows are monotonous
		{
			return mainArr;
		}
		else if (rows != 0)
		{
			printf("№ монотонных строк - ", buffArr);
			for (i = 0; i < rows; ++i)
				printf("(%d) ", buffArr[i] + 1);// mono rows
		}
		size = rows;
		
		if (rows > 1)//если строк больше 1 и не полностью монотонный
		{			
			int **secArr = new int*[rows];// создание двум. дин. массива второго
			for (i = 0; i < n; ++i)
				secArr[i] = new int[n];

			for (i = 0; i < rows; ++i)//заполнение второго массива
				for (j = 0; j < n; ++j)
					secArr[i][j] = mainArr[buffArr[i]][j];

		/*	for (int i = 0; i < n; ++i)
				delete secArr[i];
			delete[] secArr;*/

			return secArr;
		}
		else if (rows == 1)//eсли строка 1
		{
			int *secArr = new int[n];
			for (i = 0; i < n; ++i)
			{
				secArr[i] = mainArr[buffArr[0]][i];
			}

			printf("\nСозданная матрица\n");
			for (j = 0; j < n; ++j)
			{
				printf("%d\t", secArr[j]);
			}
			printf("\n");
			//delete[] secArr;

			//return &secArr;
		}
		else if (rows == 0)
			return 0;

		/*for (int i = 0; i < n; ++i)
			delete mainArr[i];
		delete[] mainArr;*/

		//buffArr.clear();
		return 0;
	}

	~MonoRows();

private:

	bool is_digit(const char *S, int sz) {
		const char *temp = "0123456789-";
		unsigned point_count = 0;
		int len = strlen(S);

		for (int i = 0; i < len; i++) {
			if ((i > 0) && (S[i] == '+' || S[i] == '-')) return false;
			if (len >= sz) return false;
			if (sz == 5)
			{
				if (S[0] == '0') return false;
				if (S[0] == '-') return false;
			}
			if (S[i] == '.') 
				return false;
			if (!strchr(temp, S[i])) return false;
		}
		return true;
	}

};

MonoRows::MonoRows()
{
};

MonoRows::~MonoRows()
{
};