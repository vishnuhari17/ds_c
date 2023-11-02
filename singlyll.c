#include<stdio.h>
#include<stdlib.h>
void insert();
void insert_beg();
void insert_end();
void insert_pos();
void del_beg();
void del_end();
void del_pos();
void display();
struct node
{
	int data;
	struct node*link;
};
struct node *head,*new,*ptr,*ptr1,*temp;
int item,pos,op,ch,i;

void insert()
{
	new=(struct node*) malloc (sizeof(struct node));
	printf("Enter the data to be stored\n");
	scanf("%d",&item);
	new->data=item;
	new->link=NULL;
	
}
void insert_beg()
{
	insert();
	if(head==NULL)
	{
		head=new;
	}
	else
	{
		new->link=head;
		head=new;
	}
}
void insert_end()
{
	insert();
	if(head==NULL)
	{
		head=new;
	}
	else
	{
		ptr=head;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=new;
	}
}
void insert_pos()
{
	
	printf("Enter the position to which item to be inserted\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		insert_beg();
	}
	else
	{
		insert();
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->link;
		}
		new->link=ptr->link;
		ptr->link=new;
	}
	
}
void del_beg()
{
	if(head==NULL)
	{
	printf("The LL is empty\nDeletion not possible\n");
	}
	else
	{
		temp=head;
		printf("The deleted item is %d\n",temp->data);
		head=temp->link;
		free(temp);
	}
}

void del_end()
{
	if(head==NULL)
	{
		printf("The LL is empty\nDeletion not possible\n");
	}
	else
	{
		ptr=head;
		while(ptr->link!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->link;
		}
		temp=ptr;
		printf("The deleted item is %d",temp->data);
		ptr1->link=NULL;
		free(temp);
	}
}
void del_pos()
{
	printf("Enter the position of item to be deleted\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		del_beg();
	}
	else
	{
		ptr=head;
		for(i=1;i<pos-1;i++)
		{
		
			ptr1=ptr;
			ptr=ptr->link;
		}
		temp=ptr;
		printf("The deleted item is %d ",temp->data);
		ptr1->link=temp->link;
		free(temp);
		
	}
}
void display()
{
	printf("The current LL is \n");
	ptr=head;
	while(ptr->link!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->link;
	}
	printf("%d\t",ptr->data);
}

void main()
{
	do{
	printf("1--Insert at beg\t2--Insert at end\t3--Insert at pos\n4--Deletion at beg\t5--Deletion at end\t6--Deletion from pos\n7--Display\n");
	printf("Enter choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: insert_beg();
					break;
		case 2: insert_end();
					break;
		case 3: insert_pos();
					break;
		case 4: del_beg();
					break;
		case 5: del_end();
					break;
		case 6: del_pos();
					break;
		case 7:display();
				break;
	}
	printf("\n");
	printf("DO YOU WANT TO CONTINUE?\n");
	printf("1--YES\t2--NO\n");
	scanf("%d",&op);
	}while(op==1);
}