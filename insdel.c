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

void insert(int *arr,int size)
{
	int a,pos,i;
	printf("Enter the element to be inserted : ");
	scanf("%d",&a);
	printf("Enter the position to be inserted : ");
	scanf("%d",&pos);
	for(i=size;i>=pos;i--)
	{
		arr[i+1]=arr[i];
	}
	arr[pos]=a;
	print_arr(arr,size+1);
	
}

int delete(int *arr,int size)
{
	int a,ele,i,pos,flag=0;
	printf("Enter the element to be deleted : ");
	scanf("%d",&ele);
	for(i=0;i<size;i++)
	{
		if(ele==arr[i])
		{
			pos=i;
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		for(i=pos;i<size;i++)
		{
		arr[i]=arr[i+1];
		}
		print_arr(arr,size-1);
		return size-1;
	}
	else
	{
		printf("Element to be deleted not found!!\n");
		return size;
	}
	
	
}

void main()
{
	int arr[50],n,i,choice,ch=1,c;
	printf("Enter the no of elements : ");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	print_arr(arr,n);
	do
	{
		printf("1--Insertion\n2--Deletion\n3--Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert(arr,n);
							n++;
							break;
			case 2: n=delete(arr,n);
							break;
			case 3: printf("Exiting the program....\n");
							ch=0;
							break;
			default: printf("Error!! Invalid choice\n");
							 break;
		}
	}while(ch);
	
}
