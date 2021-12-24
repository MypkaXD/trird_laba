#include <iostream>

void SecondMerg(double* array, int begin, int end, int lenght)
{
	int i = begin;
	int mid = begin + (end - begin) / 2;
	int j = mid + 1;
	int k = 0;
	double* arr = new double[lenght];
	while (i <= mid && j <= end)
	{
		if (array[i] <= array[j])
		{
			arr[k] = array[i];
			i++;
		}
		else
		{
			arr[k] = array[j];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		arr[k] = array[i];
		i++;
		k++;
	}
	while (j <= end)
	{
		arr[k] = array[j];
		j++;
		k++;
	}
	for (int count = 0; count < k; count++)
	{
		array[begin + count] = arr[count];
	}
	delete[] arr;
	arr = nullptr;
}

void FirstMergeSort(double* array, int left, int right, int lenght)
{
	double temp;
	if (left < right)
	{
		if (left - right == 1)
		{
			if (array[left] > array[right])
			{
				temp = array[left];
				array[left] = array[right];
				array[right] = temp;
			}
		}
		else
		{
			FirstMergeSort(array, left, left + (right - left) / 2, lenght);
			FirstMergeSort(array, left + (right - left) / 2 + 1, right, lenght);
			SecondMerg(array, left, right, lenght);
		}
	}
}