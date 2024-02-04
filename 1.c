// Write an algorithm and program that displays all the elements X in a binary
//  search tree such that k1x,k2 where k1 and k2 are two values supplied

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lchild , *rchild;
}*root, *parent, *ptr, *new;

void create_bst()
{
    int item;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted : ");
    scanf("%d",&item);
    new->data = item;
    new->lchild = NULL;
    new->rchild = NULL;
    if(root==NULL)
    {
        root = new;
    }
    else 
    {
        ptr = root;
        while(ptr!=NULL)
        {
            parent = ptr;
            if(ptr->data>item)
            {
                ptr = ptr->lchild;
            }
            else{
                ptr = ptr->rchild;
            }
        }
        if(parent->data>item)
        {
            parent->lchild = new;
        }
        else
        {
            parent->rchild = new;
        }
    }

}


void print_bst(struct node *head,int k1, int k2)
{
    if(head->lchild!=NULL)
        print_bst(head->lchild,k1,k2);
    if(head->data>k1 && head->data<k2)
        printf("%d\t",head->data);
    if(head->rchild!=NULL)
        print_bst(head->rchild,k1,k2);
}

void main()
{
    int choice,k1,k2;
    do{
        create_bst();
        printf("Press 1 to enter more elements :");
        scanf("%d",&choice);
    }while(choice==1);
    printf("Binary Search tree created successfully!\n");
    printf("Enter the limits k1 and k2 : \n");
    scanf("%d%d",&k1,&k2);
    printf("The Bst elements between those limits is : ");
    print_bst(root,k1,k2);
    printf("\n");
}