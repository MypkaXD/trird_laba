#include <iostream>

void SortOfBubble(double* array, char answer, int lenght)
{
	for (int startIndex = 1; startIndex < lenght; ++startIndex)
	{
		for (int curretIndex = 0; curretIndex < lenght - 1; ++curretIndex)
		{
			if (answer == 'l')
			{
				if (array[curretIndex] < array[startIndex])
				{
					double temp = array[startIndex];
					array[startIndex] = array[curretIndex];
					array[curretIndex] = temp;
				}
			}
			if (answer == 'h')
			{
				if (array[curretIndex] > array[startIndex])
				{
					double temp = array[startIndex];
					array[startIndex] = array[curretIndex];
					array[curretIndex] = temp;
				}
			}
		}
	}
}