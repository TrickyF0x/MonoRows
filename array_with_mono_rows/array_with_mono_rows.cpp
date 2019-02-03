#include "pch.h"
#include "monorows.h"
#include <Windows.h>
#include <iostream>

int main()
{
	SetConsoleCP(1251);//для корректного отображения в консоли кириллицы
	SetConsoleOutputCP(1251);

	int size, matrix_size, **matrix;

	MonoRows sample_matrix;

	sample_matrix.set_size();
	sample_matrix.set_values();

	size = sample_matrix.get_size();
	matrix = sample_matrix.get_values();

	printf("Введенная матрица:\n");
	for (int i = 0; i < size; ++i)//вывод основного массива
	{
		printf("%d) ", i + 1);
		for (int j = 0; j < size; ++j)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	matrix = sample_matrix.get_mono_rows(size, matrix);

	if (matrix == 0)
	{
		printf("Нет мнотонных строк\n");//если нет монотонных 
		return 0;
	}
	else if (size == sizeof(matrix) / sizeof(*matrix))
	{
		printf("Все строки монотонны.\n");
	}
	else
	{
		printf("\nСозданная матрица\n");
		for (int i = 0; i <= sizeof(matrix) / sizeof(*matrix); ++i)
		{
			printf("%d) ", i + 1);
			for (int j = 0; j < size; ++j)
			{
				//printf("i j %d %d ", i, j);
				printf("%d\t", matrix[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}