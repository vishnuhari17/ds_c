#include<stdio.h>
#define MAX 15
int x;

int a[MAX] = {1,2,3,4,5,5,6,7,8};

int searchtree(int a[], int i, int val) {
    if (i > MAX || a[i] == 0) {
        return 0;
    }

    if (a[i] == val) {
        return i;
    }

    x = searchtree(a, 2 * i, val);
    if (x != 0) {
        return x;
    }

    x = searchtree(a, 2 * i + 1, val);
    return x;
}


void main()
{
    int item,x;
    printf("Enter the element to search : ");
    scanf("%d",&item);
    x = searchtree(a,1,item);
    if(x==0)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element found at index %d \n",x);
    }
}

