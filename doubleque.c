#include<stdio.h>
#define MAX 5
void enqueuefront();
void enqueuerear();
void dequeuefront();
void dequeuerear();
void displayDeque();
int c,d,item,front=-1,rear=-1,q[MAX],i,temp,del,d=1;
void main()
{
    int ch;
    printf("1--Enqueuefront\n--Enqueurear\n3--Dequeuefront\n4--Dequeuerear\n5--Exit");
    do{
        printf("Enter your choice : ");
        scanf("%d",&ch);
        if(ch==1)
        {
            enqueuefront();
            displayDeque();
        }
        else if(ch==2)
        {
            enqueuerear();
        }
        else if(ch==3)
        {
            dequeuefront();
            if(front!=-1)
            {
                displayDeque();
            }
        }
        else if(ch==4)
        {
            dequeuerear();
            if(front!=-1)
            {
                displayDeque();
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
void enqueuefront()
{
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
            printf("STACK OVERFLOW !\n");
        }
        else
        {
            front=temp;
            q[front]=item;
        }
    }
}
void enqueuerear()
{
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
         printf("STACK OVERFLOW !\n");
    }
    else
    {
        rear=(rear+1)%MAX;
        q[rear]=item;
       
    }
}
void dequeuefront()
{
    if(front==-1)
    {
        printf("STACK UNDERFLOW !\n");
    }
    else
    {
        del=q[front];
        printf("%d is the deleted item\n",del);
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
void dequeuerear()
{
    if(front==-1)
    {
        printf("STACK UNDERFLOW !\n");
    }
    else
    {
        del=q[rear];
        printf("%d is the deleted item\n",del);
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
void displayDeque()
{
    int i;
    if (front == -1) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque elements from front to rear: ");
        for (i = front; i != rear; i = (i + 1) % MAX) {
            printf("%d ", q[i]);
        }
        printf("%d\n", q[rear]);
    }
}
