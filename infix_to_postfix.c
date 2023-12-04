// infix to prefix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[20];
char infix[20], postfix[20];
int top = -1;

void convert() {
    int i, j = 0;
    char symbol;

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        switch (symbol) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (top != -1 && precedence(stack[top]) >= precedence(symbol)) {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void display() {
    int i = 0;
    printf("\nThe equivalent postfix expression is : ");
    while (postfix[i]) {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

void push(char c) {
    if (top == 19) {
        printf("\nstack overflow.\n");
    } else {
        top++;
        stack[top] = c;
    }
}

char pop() {
    char c;
    if (top == -1) {
        printf("\nstack underflow.\n");
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c;
}


int main() {
    printf("\nEnter the Infix Expression : ");
    gets(infix);

    convert();
    display();
}

