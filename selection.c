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

void selection_sort(int a[],int n)
{
    for(int i = 0; i<n-1 ; i++)
    {
        int min = a[i];
        int loc = i;
        for(int j= i+1 ; j<n ; j++)
        {
            if(min>a[j])
            {
                min = a[j];
                loc = j;
            }
        }
        if(loc!=i)
        {
            swap(&a[loc],&a[i]);
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
    selection_sort(a,n);
    printf("The sorted array is : ");
    print_arr(a,n);
}