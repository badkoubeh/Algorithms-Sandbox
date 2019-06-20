#include"Header.h"

void mergeSort(int arr[], int arr_size)
{
	mergeSort(arr, 0, arr_size - 1);
}

void mergeSort(int arr[], int left_start, int right_end)
{
	if (left_start < right_end)
	{
		int middle = left_start + (right_end - left_start) / 2;
		//cout << "left" << endl;
		mergeSort(arr, left_start, middle);
		//cout << "right" << endl;
		mergeSort(arr, middle + 1, right_end);
		//cout << "merge" << endl;
		mergeHalves(arr, left_start, right_end, middle);
	}
}

void mergeHalves(int arr[], int left_start, int right_end, int mid)
{
	int left_end = mid;
	int right_start = mid +1;

	size_t size = right_end - left_start + 1;

	int *temp_arr = new int[size*10];



	int left_index = left_start;
	int right_index = right_start;
	int temp_index = left_start;

	while (left_index <= left_end && right_index <= right_end)
	{
		if (arr[left_index] <= arr[right_index])
		{
			temp_arr[temp_index] = arr[left_index];
			left_index++;
		}
		else
		{
			temp_arr[temp_index] = arr[right_index];
			right_index++;
		}
		temp_index++;
	}

	while (left_index <= left_end)
	{
		temp_arr[temp_index] = arr[left_index];
		left_index++;
		temp_index++;
	}

	while (right_index <= right_end)
	{
		temp_arr[temp_index] = arr[right_index];
		right_index++;
		temp_index++;
	}
		
	for (int i = left_start; i < temp_index; i++)
	{
		arr[i] = temp_arr[i];
	}
	delete [] temp_arr;
}