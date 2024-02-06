#include<stdio.h>
#include<stdlib.h>
void insert(int val);
void delete(int delval);
struct node* search(int searchval);
void display();
struct node*inorder_succ(struct node*ptr);
int choice,n,insval,flag,delval,item,searchval;
struct node
{
    int data;
    struct node*lptr,*rptr;
};
    struct node*head,*ptr,*new,*parent,*root,*ptr1,*inorder_succ_ptr;

void insert(int insval)
{
    new=(struct node*)malloc(sizeof(struct node));
    new->data=insval;
    new->lptr=NULL;
    new->rptr=NULL;
    if(root==NULL)
    {
        root=new;
    }
    else
    {
        ptr=root;
        while(ptr!=NULL)
        {
            parent=ptr;
            if(ptr->data<insval)
            {
                ptr=ptr->rptr;
            }
            else
            {
                ptr=ptr->lptr;
            }
        }
        if(parent->data>insval)
        {
            parent->lptr=new;
        }
        else
        {
            parent->rptr=new;
        }
   
    }
}


void delete(int delval)
{
    ptr=root;
    flag=0;
    while(ptr!=NULL)
    {
        if(ptr->data==delval)
        {
            flag=1;
            break;
        }
        else if(delval<ptr->data)
        {
            parent=ptr;
            ptr=ptr->lptr;

        }
        else
        {
            parent=ptr;
            ptr=ptr->rptr;
        }
    }
    if(flag==0)
    {
        printf("deletion not possible...node doesn't exist\n");
    }
    else //deletion possible
    {
        if((ptr->lptr==NULL) && (ptr->rptr==NULL) )   //ptr is the leaf node
        {
            if(parent->lptr==ptr)
            {
                parent->lptr=NULL;
            }
            else
            {
                parent->rptr=NULL;
            }
        }
        else if((ptr->lptr!=NULL) && (ptr->rptr!=NULL))
        {
            inorder_succ_ptr=inorder_succ(ptr);
            item=inorder_succ_ptr->data;
            delete(inorder_succ_ptr->data);
            ptr->data=item;
        }
        else
        {
            if(parent->lptr == ptr)
            {
                parent->lptr = (ptr->lptr != NULL) ? ptr->lptr : ptr->rptr;
            }
            else
            {
                parent->rptr = (ptr->lptr != NULL) ? ptr->lptr : ptr->rptr;
            }
        }

        
    }
}          
       
struct node*inorder_succ(struct node*ptr)
{
    ptr1=ptr->rptr;
    while(ptr1->lptr!=NULL)
    {
        ptr1=ptr1->lptr;
    }
    return ptr1;
}

struct node* search(int searchval)
{
    ptr=root;
    while(ptr!=NULL)
    {
        if(ptr->data==searchval)
        {
            printf("element found\n..");
            break;
        }
        else
        {
            if(searchval<ptr->data)
            {
                ptr=ptr->lptr;
            }
            else
            {
                ptr=ptr->rptr;
            }
        }
    }
    if(ptr==NULL)
    {
        printf("element doesn't exist\n");
    }
}
       
   
void preorder(struct node*ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        printf("%d\t",ptr->data);
        preorder(ptr->lptr);
        preorder(ptr->rptr);
    }
}


void inorder(struct node*ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        inorder(ptr->lptr);
        printf("%d\t",ptr->data);
        inorder(ptr->rptr);
    }
}


void postorder(struct node*ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        postorder(ptr->lptr);
        postorder(ptr->rptr);
        printf("%d\t",ptr->data);
    }
}



void display()
{
    if(root==NULL)
    {
        printf("tree is empty\n");
    }
    else
    {
        printf("preorder representation is\n");
        preorder(root);
        printf("\n");
        printf("inorder representation is\n");
        inorder(root);
        printf("\n");
        printf("postorder representation is\n");
        postorder(root);
        printf("\n");
    }
}


void main()
{
    int n=1;
    do
    {
   
    printf("1:INSERTION\n2:DELETION\n3:SEARCH\n4:DISPLAY\n5:EXIT\n");
    printf("Enter the operation u need to perform:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("insertion\n");
                printf("Enter the value u need to insert\n");
                scanf("%d",&insval);
                insert(insval);
                break;
        case 2:printf("deletion\n");
                printf("Enter the value to be deleted\n");
                scanf("%d",&delval);
                delete(delval);
                break;
        case 3:printf("search\n");
                printf("Enter the value to be searched\n");
                scanf("%d",&searchval);
                search(searchval);
                break;
        case 4:printf("display\n");
                display();
                break;
        case 5:break;
        default:printf("invalid input\n");
                break;

    }
    }while(n==1);

}    



