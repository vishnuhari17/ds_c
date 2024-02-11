#include <stdio.h>

int a[10], n;

void swap(int *a, int *b)
{
    int temp = *a;
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


void quick_sort(int low, int high, int a[])
{
    if (low < high)
    {
        int pivot = a[low];
        int i = low+1;
        int j = high;
        while (i <= j)
        {
            while (i <= high && a[i] <= pivot)
            {
                i++;
            }
            while (a[j] >= pivot && j > low)
            {
                j--;
            }
            if(i<j)
            {
                swap(&a[i], &a[j]);
            }
            
        }
        swap(&a[low], &a[j]);
        quick_sort(low, j - 1, a);
        quick_sort(j + 1, high, a);
    }
}
void main()
{
    printf("Enter the no of elements in the array : ");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The unsorted array is : ");
    print_arr(a, n);
    int low = 0;
    int high = n - 1;
    quick_sort(low, high, a);
    printf("The sorted array is : ");
    print_arr(a,n);
}