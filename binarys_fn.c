#include<stdio.h>

void print_arr(int *arr,int size)
{
	int i;
	printf("Index\t:\tPosition ");
	printf("\n");
	for(i=0;i<size;i++)
	{
		printf("[%d]\t:\t%d\n",i,arr[i]);
	}
	printf("\n");
}

void scan_arr(int *arr,int n)
{
	int i;
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	print_arr(arr,n);
}

void bin_search(int *arr, int n, int ele)
{
	int low,high,mid;
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]==ele)
		{
			printf("Element found at index : %d\n",mid);
			break;
		}
		else if(arr[mid]<ele)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	if(low>high)
	{
		printf("Element not found\n");
	}
}

void main()
{
	int arr[50],n,low,high,ele,mid,i;
	printf("Enter the no of elements : ");
	scanf("%d",&n);
	scan_arr(arr,n);
	printf("Enter the element to be searched : ");
	scanf("%d",&ele);
	bin_search(arr,n,ele);
}
