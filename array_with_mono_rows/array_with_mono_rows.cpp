#include "pch.h"
#include "monorows.h"
#include <Windows.h>
#include <iostream>

int main()
{
	SetConsoleCP(1251);//для корректного отображения в консоли кириллицы
	SetConsoleOutputCP(1251);

	int size, **matrix;

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

	if (sample_matrix.size == 0)
		printf("Нет монотонных строк\n");//если нет монотонных 
	else 
		if (size == sample_matrix.size)
			printf("Все строки монотонны.\n");
	else 
		if(sample_matrix.size > 1)
		{	
		    printf("\nСозданная матрица\n");
		    for (int i = 0; i < sample_matrix.size; ++i)
		    {
		      printf("%d) ", i + 1);
		      for (int j = 0; j < size; ++j)
		      {
		      	printf("%d\t", matrix[i][j]);
		      }
		      printf("\n");
		    }
		}
	
	/*for (int i = 0; i < size; ++i)
		delete matrix[i];
	delete[] matrix;*/

	system("pause");
	return 0;
};