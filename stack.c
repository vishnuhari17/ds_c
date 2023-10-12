#include<stdio.h>
#define max_size 5
int top=-1;
int stack[max_size];
void push(int number)
{
    if(top>=max_size-1)
    {
        printf("Stack overflow insertion not possible!!\n");
    }
    else
    {
        top++;
        stack[top] = number;
        printf("Successfully pushed %d\n",number);
    }
}

void pop()
{
    int del_element;
    if(top==-1)
    {
        printf("Cannot pop.The stack is empty!!\n");
    }
    else
    {
        del_element=stack[top];
        top--;
        printf("The element %d was deleted\n",del_element);
    }
}

void display()
{
    if(top==-1)
    {
        printf("The stack is empty!!\n");
    }
    else
    {
        printf("The stack is: ");
        for(int i=0;i<=top;i++)
        {
            printf("%d  ",stack[i]);
        }
        printf("\n");
    }
}

void main()
{
    int ch,flag=0,number;
    do
    {
        printf("1--Push\n2--Pop\n4--Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                printf("Enter the element to be pushed :");
                scanf("%d",&number);
                push(number);
                display();
                break;
            case 2:
                pop();
                display();
                break;
            case 4:
                printf("Exiting...\n");
                flag=1;
                break;
        
            default:printf("Invalid choice!!\n");
                    break;
        }
    
    }while(flag==0);
}
