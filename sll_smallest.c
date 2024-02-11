#include <stdio.h>
#include <stdlib.h>

int item;
char ch;

struct node
{
    int data;
    struct node *link;
} *head, *ptr, *new;

struct node *create_sll()
{
    do
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data to be inserted : ");
        scanf("%d", &item);
        new->data = item;
        new->link = NULL;
        if (head == NULL)
        {
            head = new;
            ptr = head;
        }
        else
        {
            ptr->link = new;
            ptr = ptr->link;
        }
        printf("Do you want to enter a new node ?(y/n) : ");
        scanf(" %c",&ch);
    }while(ch=='y');

    return head;
}

void find_smallest(struct node *head)
{
    ptr = head;
    int smallest = ptr->data;
    while(ptr!=NULL)
    {
        if(ptr->data<smallest)
        {
            smallest = ptr->data;
        }
        ptr=ptr->link;
    }
    printf("The smallest element in the linked list is : %d\n",smallest);
}

void main()
{
    head = create_sll();
    find_smallest(head);
}