#include<stdio.h>
#include<stdlib.h>

struct node
{
	char data;
	struct node *lptr, *rptr;
};

struct node *ptr, *root,*new,*x;


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

struct node *  search(struct node *ptr,char val)
{
	if(ptr->data == val)
	{
		return ptr;
	}
    	else
    	{
    		if(ptr->lptr!=NULL)
    		{
		       x=search(ptr->lptr,val);
		}
		if(ptr->rptr!=NULL)
	    	{
		        x=search(ptr->rptr,val);
		}
		return ;
    	}
}

void insert(struct node *root,char val)
{
	x=search(root,val);
	if(x!=NULL)
	{
		printf("Element not found...can't insert'\n");
	}
	else
	{
		new = (struct node *) malloc (sizeof(struct node));
		new->lptr = NULL;
		new->rptr = NULL;
		printf("Do you want to enter the element as a left or right child? : ");
        	scanf(" %c",&ch);
       	 if(ch=='l')
        	{
        		if(x->lptr==NULL)
        		{
        			printf("Enter the value to be inserted : ");
        			scanf(" %c",new->data);
        			x->lptr = new;
        		}
        	}
        	else
        	{
        		printf("Cant insert\n");
        	}
        	if(ch=='r')
        	{
        		if(x->rptr==NULL)
        		{
        			printf("Enter the value to be inserted : ");
        			scanf(" %c",new->data);
        			x->rptr = new;
        		}
        	}
        	else
        	{
        		printf("Cant insert\n");
        	}
	}
}


void main()
{
	printf("Enter the value of the root node : ");
	root = (struct node *) malloc (sizeof(struct node));
	buildtree(root);
	printf("The tree is : ");
	preorder(root);
	printf("\n");
	printf("Enter the element to be searched :  ");
	scanf(" %c",&val);
	x=search(root,val);
	if(x==NULL)
	{
		printf("Element not found\n");
	}
	else
	{
		printf("Element found\n");
	}
	
	
	printf("Enter the node to which the element is to be inserted : ");
	scanf(" %c",&val);
	insert(root,val);
	
}
