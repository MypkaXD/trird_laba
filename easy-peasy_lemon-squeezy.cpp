#include <iostream>
#include <ctime>
#include <cstdlib>

void SecondMerg(double* array, int begin, int end, int lenght);

void FirstMergeSort(double* array, int left, int right, int lenght);

int getValue()//получаю количество эл-тов + проверяю на их правильность
{
GetOfInput:
	std::cout << "Сколько элeментов в массиве?" << std::endl;
	int lenght;
	std::cin >> lenght;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Что-то пошло не так, попробуйте заново" << std::endl;
		goto GetOfInput;
	}
	std::cin.ignore(32767, '\n');
	return lenght;
}


void fillingTheArray(int lenght, double* array)
{
GetOfQuestionOfFilling:
	std::cout << "Вы сами введете данные? Да/нет - y/n" << std::endl;
	char questionOfFilling;
	std::cin >> questionOfFilling;
	while (questionOfFilling != 'y' && questionOfFilling != 'n')
	{
		std::cout << "Что-то пошло не так, попробуйте заново" << std::endl;
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		goto GetOfQuestionOfFilling;
	}
	if (questionOfFilling == 'y')
	{
		for (int count = 0; count < lenght; ++count)
		{
		reloadInPut:
			if (count + 1 == 1 || count + 1 > 3)
				std::cout << "Введите " << count + 1 << "-ый элемент массива" << std::endl;
			else if (count + 1 == 2)
				std::cout << "Введите " << count + 1 << "-ой элемент массива" << std::endl;
			else if (count + 1 == 3)
				std::cout << "Введите " << count + 1 << "-ий элемент массива" << std::endl;
			std::cin >> array[count];
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "Что-то пошло не так, попробуйте заново" << std::endl;
				goto reloadInPut;
			}
		}
	}
	else if (questionOfFilling == 'n')
	{
		srand(static_cast<int>(time(0)));
		for (int count = 0; count < lenght; ++count)
		{
			array[count] = rand();
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");//русский текст

	int lenght = getValue();//получаю и проверяю колчиство элементов в массиве

	double* array = new double[lenght];//создаю массив длинной lenght

	fillingTheArray(lenght, array);

	FirstMergeSort(array, 0, lenght - 1, lenght);

	for (int count = 0; count < lenght; ++count)//вывод данных
	{
		std::cout << array[count] << " ";
	}

	delete[] array;
	array = nullptr;

	return 0;
}

