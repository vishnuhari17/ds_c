#include <stdio.h>
#define MAX 9

int a[MAX], lval, rval, root, i, key, m, n, x;
char ch;

int search(int a[], int i, int key);

void buildtree(int a[],int i,int m)
{
    a[i]=m;
    printf("Do u want left node (y/n) : ");
    scanf(" %c",&ch);
    if(ch=='y')
    {
        printf("Enter the value to be inserted : ");
        scanf("%d",&lval);
        buildtree(a,2*i,lval);
    }
    printf("Do u want right node (y/n) : ");
    scanf(" %c",&ch);
    if(ch=='y')
    {
        printf("Enter the value to be inserted : ");
        scanf("%d",&rval);
        buildtree(a,(2*i)+1,rval);
    }
    return;
}

void main()
{
    for (i = 1; i < MAX; i++)
    {
        a[i] = -1;
    }
    printf("Enter the root value : ");
    scanf("%d", &root);
    buildtree(a, 1, root);
    printf("the array elements are\n");
    for (i = 1; i < MAX; i++)
    {
        if (a[i] != -1)
        {
            printf("%d ", a[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\nEnter the key u need to search\n");
    scanf("%d", &key);
    x = search(a, 1, key);
    if (x == 0)
    {
        printf("Element not found..\n");
    }
    else
    {
        printf("element found at index %d\n", x);
    }
}

int search(int a[], int i, int key)
{
    if (a[i] == key)
    {
        return i;
    }
    else
    {
        if (2 * i <= MAX)
        {
            n = search(a, 2 * i, key);
        }
        else
        {
            return 0;
        }
        if (n == 0 && (2 * i + 1) <= MAX)
        {
            n = search(a, 2 * i + 1, key);
        }
        return n;
    }
}
