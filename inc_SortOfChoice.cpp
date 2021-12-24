#include <iostream>

void SortOfChoice(double* array, char answer, int lenght)
{
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
}