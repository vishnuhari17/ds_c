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

int bin_search(int *arr,int low,int high,int ele)
{
	int mid;
	mid=(low+high)/2;
	if(low>high)
	{
		return -1;
	}
	else if(arr[mid]==ele)
	{
		return mid;
	}
	else if(arr[mid]<ele)
	{
			low=mid+1;
			bin_search(arr,low,high,ele);
			
	}
	else
	{
			high=mid-1;
			bin_search(arr,low,high,ele);
	}
}

void main()
{
	int arr[50],n,low,high,ele,a;
	printf("Enter the no of elements : ");
	scanf("%d",&n);
	scan_arr(arr,n);
	printf("Enter the element to be searched : ");
	scanf("%d",&ele);
	low=0;
	high=n-1;
	a = bin_search(arr,low,high,ele);
	if(0<=a)
	{
		printf("Element found at index : %d\n",a);
	}
	else
	{
		printf("Element not found!!\n");
	}
}


/* 
Enter the no of elements : 5
Enter the elements:
1
2
3
4
5
Index	:	Position 
[0]	:	1
[1]	:	2
[2]	:	3
[3]	:	4
[4]	:	5

Enter the element to be searched : 4 
Element found at index : 3
*/

