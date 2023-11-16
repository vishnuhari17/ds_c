#include <stdio.h>
#define MAX 15

int a[MAX], val;
char ch;

void buildtree(int a[], int i, int val) {
    if (i == 0) 
    {
        return;
    } 
    else 
    {
        a[i] = val;
        printf("Do you want to enter a left child? (y/n): ");
        scanf(" %c", &ch); 
        if (ch == 'y') 
        {
            printf("Enter the value to be inserted: ");
            scanf("%d", &val);
            buildtree(a, 2 * i, val);
        } 
        else 
        {
            buildtree(a, 0, 0);
        }
        printf("Do you want to enter a right child? (y/n): ");
        scanf(" %c", &ch);
        if (ch == 'y') 
        {
            printf("Enter the value to be inserted: ");
            scanf("%d", &val);
            buildtree(a, 2 * i + 1, val);
        } 
        else 
        {
            buildtree(a, 0, 0);
        }
    }
}

void main() 
{
    printf("Enter the value to be inserted as the root node: ");
    scanf("%d", &val);
    buildtree(a, 1, val);
    for(int i=1;i<MAX;i++)
    {
        printf("%d ",a[i]);
    }
}
