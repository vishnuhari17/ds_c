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

void bubble_sort(int a[],int n) 
{
    for(int i=0;i<n-1;i++) 
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
            }
        }
        printf("Pass %d : ",i+1);
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
    bubble_sort(a,n);
    print_arr(a,n);
}