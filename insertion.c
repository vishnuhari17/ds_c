#include<stdio.h>

int a[10],n;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print_arr(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void insertion_sort(int a[],int n)
{
    int j;
    for(int i= 1 ; i<n ; i++)
    {
        int ele = a[i];
        for(j = i-1 ; j>=0 && ele<a[j]; j --)
        {
            a[j+1] = a [j];
        }
        a[j+1] = ele;
        printf("Pass %d : ",i);
        print_arr(a,n);
    }
}

void main()
{
    printf("Enter the no of elements in the array : ");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&a[i]);
    }
    printf("The unsorted array is : ");
    print_arr(a,n);
    insertion_sort(a,n);
    printf("The sorted array is : ");
    print_arr(a,n);
}