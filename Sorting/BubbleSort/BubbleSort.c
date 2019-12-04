#include <stdio.h>
#include <Windows.h>

void BubbleSort(int arr[], int n)
{
	int i,j;
	int temp;

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<(n-i)-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int main(void)
{
	int arr[7]={5,9,8,2,4,2,6};
	int i;

	BubbleSort(arr,sizeof(arr)/sizeof(int));

	for(i=0;i<7;i++)
		printf("%d ",arr[i]);
	system("pause");
	return 0;
}