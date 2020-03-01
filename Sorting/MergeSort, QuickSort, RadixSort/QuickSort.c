#include <stdio.h>
#include <stdlib.h>

void Swap(int arr[], int low, int high)
{
	int temp = arr[low];
	arr[low] = arr[high];
	arr[high] = temp;
}

int Partition(int arr[], int left, int right)
{
	int high = right;
	int pivot = arr[left];
	int low = left + 1; 

	while (low <= high)
	{

		while (pivot >= arr[low] && low <= right) 	//increase the low index till it meets the value higher than pivot
			low++;

		while (pivot <= arr[high] && high >= left + 1)	//	decrease the high index till it meets the value lower than pivot
			high--;

		if (low <= high)
			Swap(arr, low, high);

	}

	// if high points the lower index than low Swap pivot and high
	Swap(arr, left, high);

	return high;	
}



void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

int main(void)
{
	int i;
	int arr1[7] = { 1,2,3,4,5,6,7};
	int arr2[4] = { 3,3,3,2 };
	
	QuickSort(arr1, 0, 6);
	for (i = 0; i < 7; i++)
		printf("%d ", arr1[i]);

	printf("\n");


	QuickSort(arr2, 0, 3);
	for (i = 0; i < 4; i++)
		printf("%d ", arr2[i]);

	return 0;
}