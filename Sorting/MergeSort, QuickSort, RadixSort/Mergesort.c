#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx=left;
	int rIdx=mid+1;
	int i;

	int *sortArr=(int*)malloc(sizeof(int)*(right+1));
	int sIdx=left;

	while(fIdx<mid+1 && rIdx<right+1)
	{
		if(arr[fIdx]<arr[rIdx])
			sortArr[sIdx]=arr[fIdx++];

		else
			sortArr[sIdx]=arr[rIdx++];

		sIdx++;
	}

	if(fIdx>mid)	//if first part of the array is all moved to the sortArr
	{
		for(i=rIdx;i<right+1;i++,sIdx++)
			sortArr[sIdx]=arr[i];		//move all the data left in the rear part to the sort Arr
	}
		
	else
	{
		for(i=fIdx;i<mid+1;i++,sIdx++)
			sortArr[sIdx]=arr[i];
	}

	for(i=left;i<right+1;i++)
		arr[i]=sortArr[i];

	free(sortArr);
}




void MergeSort(int arr[], int left, int right)
{
	int mid;

	if(left<right)
	{
		mid=(left+right)/2;
		MergeSort(arr,left,mid);
		MergeSort(arr,mid+1,right);

		MergeTwoArea(arr,left,mid,right);
	}
}

int main(void)
{
	int arr[7]={3,5,7,8,6,2,9};
	int i;

	MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);


	for(i=0;i<7;i++)
		printf("%d ",arr[i]);

	printf("\n");
	
	system("pause");

	return 0;
}