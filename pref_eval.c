#include <stdio.h>
#include <string.h>
#include <math.h>

char prefix[100];
double stack[100];
int top = -1;

void push(double number) {
    top++;
    stack[top] = number;
}

double pop() {
    double del_element;
    del_element = stack[top];
    top--;
    return del_element;
}

int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void main() {
    char operand;
    double x, y, result;
    printf("Enter the prefix expression: ");
    fgets(prefix, 99, stdin);
    prefix[strlen(prefix) - 1] = '\0';
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        if (is_operator(prefix[i])) {
            operand = prefix[i];
            x = pop();
            y = pop();
            if (operand == '+') {
                result = x + y;
            } else if (operand == '-') {
                result = x - y;
            } else if (operand == '*') {
                result = x * y;
            } else if (operand == '/') {
                result = x / y;
            } else if (operand == '^') {
                result = pow(x, y);
            }
            push(result);
        } else {
            push((double)(prefix[i] - '0'));
        }
    }
    printf("The evaluated expression is: %f", pop());
}
