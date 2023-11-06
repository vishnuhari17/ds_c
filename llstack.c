#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node *top=NULL,*temp=NULL,*new=NULL,*ptr=NULL;
void push(int item)
{
	new=(struct node *)malloc(sizeof(struct node));
	new->data = item;
	new->link = NULL;
	if(top==NULL)
	{
		top=new;
	}
	else
	{
		new->link=top;
		top=new;
	}
}
void pop()
{
	int del_item;
	if(top==NULL)
	{
		printf("Linked list is empty...Can't delete\n");
	}
	else
	{
		temp=top;
		del_item=temp->data;
		printf("The deleted item is %d\n",del_item);
		if(top->link==NULL)
		{
			top=NULL;
		}
		else
		{
			top=temp->link;
		}
		free(temp);
	}
}

void display()
{
	if(top==NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("The current stack is : ");
		ptr=top;
		while(ptr->link!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr = ptr->link;
		}
		printf("%d\n",ptr->data);
	}
}

void main()
{
	int opt,item;
	do{
	printf("1--Push\t2--Pop\t3--Exit\n");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1 :printf("Enter the element to be inserted : ");
			   scanf("%d",&item);
			   push(item);
			   display();
			   break;
		case 2 :pop();
			   display();
			   break;
			   
	}
	}while(opt!=3);
}
