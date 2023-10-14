#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100

char stack[size];
char postfix[size];
int top = -1;

void push(char character)
{
    top++;
    stack[top] = character; 
}

char pop()
{
    char del_element;
    del_element = stack[top];
    top--;
    return del_element;
}

int is_operator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    return 0;
}

void main()
{
    char infix[size];
    printf("Enter the infix expression:\n");
    fgets(infix, size - 1, stdin); 

    infix[strlen(infix) - 1] = '\0';

    int i,j=0;
    for (i = 0; infix[i] != '\0'; i++)
    {
        char symbol = infix[i];
        if (symbol == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j]=pop();
                j++;
            }
            pop();
        }
        else if (symbol == '(')
        {
            push(symbol);
        }
        else if (symbol == '^')
        {
            while (precedence(stack[top]) > precedence(symbol))
            {
                postfix[j]=pop();
                j++;
            }
            push(symbol);
        }
        else if (is_operator(symbol))
        {
            while (precedence(stack[top]) >= precedence(symbol))
            {
                postfix[j]=pop();
                j++;
            }
            push(symbol);
        }
        else
        {
            postfix[j]=symbol;
            j++;
        }
    }

    while (top >= 0)
    {
        postfix[j]=pop();
        j++;
    }
    puts(postfix);
}
