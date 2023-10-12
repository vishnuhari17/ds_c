#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 30
void push(char symbol);
char stack[MAX_SIZE],postfix[MAX_SIZE];
char pop();
void display();
int precedence(char symbol);
int top=-1;
int main()
{
    int ch,i,j=0;
    char symbol,infix[MAX_SIZE],next,op;
    printf("Enter the infix to be evaluated\n");
    fgets(infix,MAX_SIZE-1,stdin);
    infix[strlen(infix) - 1] = '\0';
    ch=strlen(infix);
    for(i=0;i<ch;i++)
    {
        symbol= infix[i];
        switch(symbol)
        {
            case '(': push(symbol);
                      break;
            case '+' :
            case '-' :
            case '*' :
            case '/' :
            case '^' :  if ((precedence(stack[top]))<precedence(symbol))
                        {
                            push(symbol);
                            display();
                        }
                        else
                        {         
                            while(precedence(stack[top])>=precedence(symbol))
                            {
                                next=pop();
                                postfix[j]=next;
                                j++;
                            }                       
                            push(symbol);
                        
        
                        }
                        break;
            case ')':   while(next=pop()!='(')
                        {
                            postfix[j]=next;
                            j++;
                            
                        }
                        break;
            default : postfix[j]=symbol;
                      j++;
                      break;
        }   
    }
    while(infix[i]=='\0'&&top!=-1)
    {
        next=pop();
        postfix[j]=next;
        j++;
    }
    postfix[j]='\0';
    puts(postfix);
}

void push(char symbol)
{
    top=top+1;
    stack[top]=symbol;
}

char pop()
{
    char post;
    post=stack[top];
    top=top-1;
    return post;
}  

int precedence(char op)
{
    switch(op)
    {
        case '^': return 3;
        case '/': return 2;
        case '*': return 2;
        case '+': return 1;
        case '-': return 1;
        default  : return 0;
    }
}

void display()
{
    if(top==-1)
    {
        printf("The stack is empty!!\n");
    }
    else
    {
        printf("The stack is: ");
        for(int i=0;i<=top;i++)
        {
            printf("%c  ",stack[i]);
        }
        printf("\n");
    }
}


 
