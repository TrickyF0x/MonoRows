#include "pch.h"
#include "monorows.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);//для корректного отображения в консоли кириллицы
	SetConsoleOutputCP(1251);

	MonotonousRow row;

	row.set_array();//создаем массив
	row.monotonous_arr();//проверяем его

	std::system("pause");
	return 0;
}