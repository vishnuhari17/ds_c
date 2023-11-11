#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *prev,*next;
}*head=NULL,*tail=NULL,*new=NULL,*temp=NULL,*ptr=NULL,*ptr1=NULL;

void insert()
{
	int item;
	printf("enter the element to be inserted:\n");
	scanf("%d",&item);
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->prev=NULL;
	new->next=NULL;
}

void insertbeg()
{
	insert();
	if(head==NULL)
	{
		head=tail=new;
	}
	else
	{
		head->prev=new;
		new->next=head;
		head=new;
	}
}

void insertend()
{
	insert();
	if(head==NULL)
	{
		head=tail=new;
	}
	else
	{
		tail->next=new;
		new->prev=tail;
		tail=new;
	}
}

void insertpos()
{
	int pos,i;
	insert();
	printf("enter the position at which node is to be inserted:\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		if(head==NULL)
		{
			head=tail=new;
		}
		else
		{
			head->prev=new;
			new->next=head;
			head=new;
		}
	}
	else
	{
		ptr=head;
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->next;
		}
		ptr1=ptr->next;
		new->next=ptr1;
		new->prev=ptr;
		ptr->next=new;
		ptr1->prev=new;
	}
}

void delbeg()
{
	if(head==NULL)
	{
		printf("LL is empty!,deletion not possible\n");
	}
	else
	{
		temp=head;
		printf("Deleted item is %d\n",temp->data);
		head=temp->next;
		head->prev=NULL;
		free(temp);
	}
}

void delend()
{
	if(head==NULL)
	{
		printf("LL is empty!,deletion not possible\n");
	}
	else
	{
		if(head->next==NULL)
		{
			temp=head;
			printf("Deleted item is %d\n",temp->data);
			head=NULL;
			free(temp);
		}
		else
		{
			temp=tail;
			printf("Deleted item is %d\n",temp->data);
			tail=tail->prev;
			tail->next=NULL;
			free(temp);
		}
	}
}

void delpos()
{
	int pos,i;
	if(head==NULL)
	{
		printf("LL is empty!,deletion not possible\n");
	}
	else
	{
		printf("enter the position from which node is to deleted:\n");
		scanf("%d",&pos);
		if(pos==1)
		{
			temp=head;
			printf("Deleted item is %d\n",temp->data);
			if(head->next==NULL)
			{
				head=NULL;
			}
			else
			{
				head=temp->next;
				head->prev=NULL;
			}
			free(temp);
		}
		else
		{
			ptr=head;
			for(i=1;i<pos-1;i++)
			{
				ptr=ptr->next;
			}
			temp=ptr->next;
			printf("Deleted item is %d\n",temp->data);
			ptr1=temp->next;
			ptr->next=ptr1;
			if(ptr1!=NULL)
			{
				ptr1->prev=ptr;
			}
			free(temp);
		}
	}
}

void display()
{
	if(head==NULL)
	{
		printf("Linked List is empty!\n");
	}
	else
	{
		ptr=head;
		printf("Elements in the Linked List are: ");
		while(ptr->next!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
		printf("%d\n",ptr->data);
	}
}

void main()
{
	int ch,op;
	do
	{
		printf("choose the operation to be performed:\n1-insertbeg()\n2-insertend()\n3-insertpos()\n4-delbeg()\n5-delend()\n6-delpos()\n7-display()\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insertbeg();
						break;
			case 2: insertend();
						break;
			case 3: insertpos();
						break;
			case 4: delbeg();
						break;
			case 5: delend();
						break;
			case 6: delpos();
						break;
			case 7: display();
						break;
			default: printf("invalid operation!\n");
		}
		printf("do you want to continue?\nif yes press 1\n");
		scanf("%d",&op);
	}while(op==1);
}



/*
choose the operation to be performed:
1-insertbeg()
2-insertend()
3-insertpos()
4-delbeg()
5-delend()
6-delpos()
7-display()
1
enter the element to be inserted:
6
do you want to continue?
if yes press 1
1
choose the operation to be performed:
1-insertbeg()
2-insertend()
3-insertpos()
4-delbeg()
5-delend()
6-delpos()
7-display()
2
enter the element to be inserted:
5
do you want to continue?
if yes press 1
1
choose the operation to be performed:
1-insertbeg()
2-insertend()
3-insertpos()
4-delbeg()
5-delend()
6-delpos()
7-display()
6
enter the position from which node is to deleted:
2
Deleted item is 5
do you want to continue?
if yes press 1
1
choose the operation to be performed:
1-insertbeg()
2-insertend()
3-insertpos()
4-delbeg()
5-delend()
6-delpos()
7-display()
7
Elements in the Linked List are: 6
do you want to continue?
if yes press 1
1
choose the operation to be performed:
1-insertbeg()
2-insertend()
3-insertpos()
4-delbeg()
5-delend()
6-delpos()
7-display()
3
enter the element to be inserted:
9
enter the position at which node is to be inserted:
2
do you want to continue?
if yes press 1
1
choose the operation to be performed:
1-insertbeg()
2-insertend()
3-insertpos()
4-delbeg()
5-delend()
6-delpos()
7-display()
7
Elements in the Linked List are: 6	9
*/