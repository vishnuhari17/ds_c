#include <stdio.h>
#define MAX 50

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

void insert(int a[], int val)
{
    i=search(a,1,val);
    if(i==0)
    {
        printf("Node doesnt exist\n");
    }
    else
    {
        printf("Do you want to enter the element as a left or right child? : ");
        scanf(" %c",&ch);
        if(ch=='l')
        {
            printf("Enter the value to be inserted : ");
            scanf("%d",&lval);
            if(a[2*i]==-1)
            {
                a[2*i]=lval;
            }
            else
            {
                printf("Insertion not possible\n");
            }
        }
        if(ch=='r')
        {
            printf("Enter the value to be inserted : ");
            scanf("%d",&rval);
            if(a[2*i+1]==-1)
            {
                a[2*i+1]=rval;
            }
            else
            {
                printf("Insertion not possible\n");
            }
        }
    }
}


void delete(int a[],int val)
{
    i=search(a,1,val);
    if (i == 0)
    {
        printf("Element not found..\n");
    }
    else if( a[2*i]==-1 &&a[2*i+1]==-1)
    {
        a[i]=-1;
        printf("Element deleted..\n");
    }
    else
    {
    	printf("Deletion not possible\n");
    }
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
            printf("  ");
        }
    }
    printf("\n");
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
    printf("Enter the element to which we need to insert the node : ");
    scanf("%d",&key);
    insert(a,key);
    for (i = 1; i < MAX; i++)
    {
        if (a[i] != -1)
        {
            printf("%d ", a[i]);
        }
        else
        {
            printf("  ");
        }
    }
    printf("\n");
    printf("Enter the element to be deleted : ");
    scanf("%d",&key);
    delete(a,key);
    for (i = 1; i < MAX; i++)
    {
        if (a[i] != -1)
        {
            printf("%d ", a[i]);
        }
        else
        {
            printf("  ");
        }
    }
    printf("\n");
}

