#include<stdio.h>
#define MAX 5
void enqueueFront();
void enqueueRear();
void dequeueFront();
void dequeueRear();
void display();
int front=-1,rear=-1,q[MAX];
void main()
{
    int ch,d=1;
    do
    {
    	printf("1--Enqueue (Front)\n2--Enqueue (Rear)\n3--Dequeue (Front)\n4--Dequeue (Rear)\n5--Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        if(ch==1)
        {
            enqueueFront();
            display();
        }
        else if(ch==2)
        {
            enqueueRear();
            display();
        }
        else if(ch==3)
        {
            dequeueFront();
            if(front!=-1)
            {
                display();
            }
        }
        else if(ch==4)
        {
            dequeueRear();
            if(front!=-1)
            {
                display();
            }
        }
        else if(ch==5)
        {
            printf("Exiting.....\n");
            d=0;
            break;
        }
    }while(d==1);
}

void enqueueFront()
{
	int item,temp;
    printf("Enter your item : ");
    scanf("%d",&item);
    if(front==-1)
    {
        front=0;
        rear=0;
        q[front]=item;
    }
    else
    {
        if(front==0)
        {
            temp=MAX-1;
        }
        else
        {
            temp=front-1;
        }
        if(temp==rear)
        {
            printf("Queue is full...Cannot Enqueue\n");
        }
        else
        {
            front=temp;
            q[front]=item;
        }
    }
}

void enqueueRear()
{
	int item;
    printf("Enter your item : ");
    scanf("%d",&item);
    if(front==-1)
    {
        front=0;
        rear=0;
        q[rear]=item;
    }
    else if(front==(rear+1)%MAX)
    {
         printf("Queue is full...Cannot Enqueue\n");
    }
    else
    {
        rear=(rear+1)%MAX;
        q[rear]=item;
       
    }
}

void dequeueFront()
{
	int del_item;
    if(front==-1)
    {
        printf("Queue is Empty...Cannot Dequeue\n");
    }
    else
    {
        del_item=q[front];
        printf("%d is the deleted item\n",del_item);
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%MAX;
        }
    }
}

void dequeueRear()
{
	int del_item;
    if(front==-1)
    {
        printf("Queue is Empty...Cannot Dequeue\n");
    }
    else
    {
        del_item=q[rear];
        printf("%d is the deleted item\n",del_item);
        if(front==rear)
        {
            front=rear=-1;
        }
        else if(rear==0)
        {
            rear=MAX-1;
        }
        else
        {
            rear=rear-1;
        }
    }
}

void display()
{
    int i;
    if (front == -1) 
    {
        printf("The queue is empty.\n");
    } 
    else 
    {
        printf("Queue elements are : ");
        for (i = front; i != rear; i = (i + 1) % MAX) 
        {
            printf("%d ", q[i]);
        }
        printf("%d\n", q[rear]);
    }
}
