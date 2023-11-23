#include<stdio.h>
#include<stdlib.h>

struct node
{
	char data;
	struct node *lptr, *rptr;
};

struct node *ptr, *root,*new;


char ch,val;

void buildtree(struct node *ptr)
{
	scanf(" %c",&val);
	ptr->data = val;
	ptr->lptr = NULL;
	ptr->rptr = NULL;
	printf("Do u want left node (y/n) : ");
    	scanf(" %c",&ch);
    	if(ch=='y')
    	{
	        printf("Enter the value to be inserted : ");
	        new = (struct node *) malloc (sizeof(struct node));
	        ptr->lptr = new;
	        buildtree(new);
	}
	printf("Do u want right node (y/n) : ");
    	scanf(" %c",&ch);
    	if(ch=='y')
    	{
	        printf("Enter the value to be inserted : ");
	        new = (struct node *) malloc (sizeof(struct node));
	        ptr->rptr = new;
	        buildtree(new);
	}
	return;
}

void  preorder(struct node *ptr)
{
	printf("%c  ",ptr->data);
    	if(ptr->lptr!=NULL)
    	{
	       preorder(ptr->lptr);
	}
	if(ptr->rptr!=NULL)
    	{
	       preorder(ptr->rptr);
	}
	return;
}

void  inorder(struct node *ptr)
{
    	if(ptr->lptr!=NULL)
    	{
	       inorder(ptr->lptr);
	}
	printf("%c  ",ptr->data);
	if(ptr->rptr!=NULL)
    	{
	       inorder(ptr->rptr);
	}
	return;
}

void  postorder(struct node *ptr)
{
    	if(ptr->lptr!=NULL)
    	{
	       postorder(ptr->lptr);
	}
	if(ptr->rptr!=NULL)
    	{
	       postorder(ptr->rptr);
	}
	printf("%c  ",ptr->data);
	return;
}

void main()
{
	printf("Enter the value of the root node : ");
	root = (struct node *) malloc (sizeof(struct node));
	buildtree(root);
	printf("The tree in preorder traversal is : ");
	preorder(root);
	printf("\n");
	printf("The tree in inorder traversal is : ");
	inorder(root);
	printf("\n");
	printf("The tree in postorder traversal is : ");
	postorder(root);
	printf("\n");
}
