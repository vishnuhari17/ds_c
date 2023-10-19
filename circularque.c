#include<stdio.h>
#define MAX_SIZE 5
int front = -1;
int rear = -1;
int queue[MAX_SIZE];
void enqueue(int item)
{
    if(front==(rear+1)%MAX_SIZE)
    {
        printf("The queue is full....Cannot insert more elements :(\n");
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        rear = (rear+1)%MAX_SIZE;
        queue[rear] = item;
    }
}

void dequeue()
{
    int del_item;
    if(front==-1)
    {
        printf("The queue is empty\n");
    }
    else 
    {
        del_item = queue[front];
        printf("The item %d was deleted\n",del_item);
        if(front==rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front+1)%MAX_SIZE;
        }
    }
}

void display()
{
	if(front==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
 		printf("The current queue is :");
		int i=front;
		while(i!=rear)
		{
			printf("%d ",queue[i]);
			i=(i+1)%MAX_SIZE;
		}
		printf("%d\n",queue[rear]);
    }
}

void main()
{
    int i=0;
    while(i==0)
    {
        int ch,item;
        printf("1--Enqueue\n2--Dequeue\n3--Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter the no to be inserted : ");
            scanf("%d",&item);
            enqueue(item);
            display();
        }
        if(ch==2)
        {
            dequeue();
            if(front!=-1)
            {
                display();
            }
            
        }
        if(ch==3)
        {
            printf("Exiting.....\n");
            break;
        }

    }
}

/*
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 1
Enter the no to be inserted : 5
The current queue is :5
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 1
Enter the no to be inserted : 7
The current queue is :5 7
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 1
Enter the no to be inserted : 3
The current queue is :5 7 3
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 1
Enter the no to be inserted : 8
The current queue is :5 7 3 8
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 1
Enter the no to be inserted : 3
The current queue is :5 7 3 8 3
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 1
Enter the no to be inserted : 7
The queue is full....Cannot insert more elements :(
The current queue is :5 7 3 8 3
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 2
The item 5 was deleted
The current queue is :7 3 8 3
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 2
The item 7 was deleted
The current queue is :3 8 3
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 2
The item 3 was deleted
The current queue is :8 3
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 2
The item 8 was deleted
The current queue is :3
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 2
The item 3 was deleted
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 2
The queue is empty
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 3
Exiting.....

*/
