#include <iostream>

int getValue()//������� ���������� ��-��� + �������� �� �� ������������
{
reload:
	std::cout << "������� ��e������ � �������?" << std::endl;
	int lenght;
	std::cin >> lenght;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "���-�� ����� �� ���, ���������� ������" << std::endl;
		goto reload;
	}
	else
	{
		std::cin.ignore(32767, '\n');
		return lenght;
	}
}

char answerLH()
{
refresh:
	std::cout << "���������� ��������� � ������� ��������/����������� - l/h" << std::endl;
	char answer;
	std::cin >> answer;
	while (answer != 'l' && answer != 'h')
	{
		std::cout << "���-�� ����� �� ���, ���������� ������" << std::endl;
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		goto refresh;
	}
	return answer;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int lenght = getValue();

	double* array = new double[lenght];

	for (int count = 0; count < lenght; ++count)
	{
	tuda:
		if (count + 1 == 1 || count + 1 > 3)
			std::cout << "������� " << count + 1 << "-�� ������� �������" << std::endl;
		else if (count + 1 == 2)
			std::cout << "������� " << count + 1 << "-�� ������� �������" << std::endl;
		else if (count + 1 == 3)
			std::cout << "������� " << count + 1 << "-�� ������� �������" << std::endl;
		std::cin >> array[count];
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "���-�� ����� �� ���, ���������� ������" << std::endl;
			goto tuda;
		}
	}

	char answer = answerLH();

	for (int startIndex = 0; startIndex < lenght - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int curretIndex = startIndex + 1; curretIndex < lenght; ++curretIndex)
		{
			if (answer == 'h')
			{
				if (array[curretIndex] < array[smallestIndex])
					smallestIndex = curretIndex;
			}
			else if (answer == 'l')
			{
				if (array[curretIndex] > array[smallestIndex])
					smallestIndex = curretIndex;
			}
		}
		int temp = array[startIndex];
		array[startIndex] = array[smallestIndex];
		array[smallestIndex] = temp;
	}
	for (int count = 0; count < lenght; ++count)
	{
		std::cout << array[count] << " ";
	}

	delete[] array;
	array = nullptr;
	return 0;
}