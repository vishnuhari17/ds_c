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

struct node *array[100];
int top = -1;
void push(struct node *ptr)
{
    array[++top] = ptr;
}

struct node* pop()
{
    if(top>-1)
    {
        return array[top--];
    }
}

void non_reccursive_preorder(struct node *root)
{
    if(root==NULL)
    {
        printf("The Binary tree is empty\n");
    }
    else
    {
        ptr = root;
        push(ptr);
        while(top!=-1)
        {
            ptr = pop();
            printf("%d\t",ptr->data);
            if(ptr->rchild!=NULL)
                push(ptr->rchild);
            if(ptr->lchild!=NULL)
                push(ptr->lchild);
        }
    }
}

void non_recursive_postorder(struct node *root)
{
    ptr = root;
    while (ptr != NULL && top != -1)
    {
        if(ptr!=NULL)
        {
            push(ptr);
            ptr=ptr->lchild;
        }
        else
        {
            ptr = pop();
            if(ptr->rchild!=NULL)
                ptr=ptr->rchild;
            printf("%d",ptr->data);
        }
    }
    
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
    // printf("Enter the limits k1 and k2 : \n");
    // scanf("%d%d",&k1,&k2);
    // printf("The Bst elements between those limits is : ");
    // print_bst(root,k1,k2);
    printf("Binary Search tree is : \n");
    non_recursive_postorder(root);
    printf("\n");
}