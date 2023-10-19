#include<stdio.h>
#define MAX_SIZE 5
int front = -1;
int rear = -1;
int queue[MAX_SIZE];
void enqueue(int item)
{
    if(rear== MAX_SIZE-1)
    {
        printf("The queue is full....Cannot insert more elements :(\n");
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        rear ++;
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
            front++;
        }
    }
}

void display()
{
    if(front==-1)
    {
        printf("The queue is empty :(\n");
    }
    else
    {
        printf("The queue is : ");
        for(int i=front;i<=rear;i++)
        {
            printf("%d  ",queue[i]);
        }
        printf("\n");
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
        else if(ch==2)
        {
            dequeue();
            if(front!=-1)
            {
                display();
            }
            
        }
        else if(ch==3)
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
Enter the no to be inserted : 1
The queue is : 1  
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 1
Enter the no to be inserted : 2
The queue is : 1  2  
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 1
Enter the no to be inserted : 3
The queue is : 1  2  3  
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 1
Enter the no to be inserted : 4
The queue is : 1  2  3  4  
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 1
Enter the no to be inserted : 5
The queue is : 1  2  3  4  5  
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 1
Enter the no to be inserted : 6
The queue is full....Cannot insert more elements :(
The queue is : 1  2  3  4  5  
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 2
The item 1 was deleted
The queue is : 2  3  4  5  
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 2
The item 2 was deleted
The queue is : 3  4  5  
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 2
The item 3 was deleted
The queue is : 4  5  
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 2
The item 4 was deleted
The queue is : 5  
1--Enqueue
2--Dequeue
3--Exit
Enter your choice: 2
The item 5 was deleted
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
