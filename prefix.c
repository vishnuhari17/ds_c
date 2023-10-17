#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100
void pf(char reverse[MAX_SIZE]);
void push(char s);
char pop();
int precedance(char s);
void reverseString(char *str);
int top=-1;
char stack[MAX_SIZE], infix[MAX_SIZE],reverse[MAX_SIZE];
void main()
{
    char prefix[MAX_SIZE];
    printf("Enter the infix expression\n");
    fgets(infix,MAX_SIZE-1,stdin);
    infix[strlen(infix) - 1] = '\0';
    pf(infix);
}
void pf(char infix[MAX_SIZE])
{
    int i,j=0,l,k,len;
    char next, symbol, prefix[MAX_SIZE],rev[50];
    reverseString(infix);
	len=strlen(infix);
    for(i=0;i<len;i++)
    {
        symbol=infix[i];
        switch(symbol)
        {
            case ')':   push(symbol);
                        break;

            case '(':   while((next=pop())!=')')
                        {
                            prefix[j]=next;
                            j++;
                        }
                        break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':   while(precedance(stack[top])>precedance(symbol))
                        {
                            prefix[j]=pop();
                            j++;
                        }
                        push(symbol);
                        break;

            default:    prefix[j]=symbol;
                        j++;
                        break;
        }
    }
    while(top!=-1)
    {
        prefix[j]=pop();
        j++;
    }
    prefix[j]='\0';
    reverseString(prefix);
    puts(prefix);
}

void push(char s)
{
    top++;
    stack[top]=s;
}
char pop()
{
    char del_item;
    del_item=stack[top];
    top--;
    return del_item;
}
int precedance(char s)
{
    switch(s)
    {
        case '^': return 3;
                  break;

        case '*':
        case '/': return 2;
                  break;

        case '+':
        case '-': return 1;
                  break;

        default:  return 0;
                  break;
    } 
}

void reverseString(char *str) 
{
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) 
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}


