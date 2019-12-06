#include <stdio.h>
#include <Windows.h>

void SelSort(int arr[],int n)
{
	int i, j;
	int minIdx;
	int temp;

	for(i=0;i<n-1;i++)
	{
		minIdx=i;

		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[minIdx])
				minIdx=j;
		}

		temp=arr[i];
		arr[i]=arr[minIdx];
		arr[minIdx]=temp;
	}
}

int main(void)
{
	int arr[7]={5,9,8,2,4,2,6};
	int i;

	SelSort(arr,sizeof(arr)/sizeof(int));

	for(i=0;i<7;i++)
		printf("%d ",arr[i]);
	system("pause");
	return 0;
}
