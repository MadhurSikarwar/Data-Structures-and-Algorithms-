#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

typedef struct
{
    char arr[SIZE];
    int top;
} Stack;

void initializeStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == SIZE - 1;
}

void push(Stack *s, char ch)
{
    if (isFull(s))
    {
        printf("Error: Stack Overflow! Cannot push '%c'\n", ch);
        exit(1); // stop program safely
    }
    s->arr[++(s->top)] = ch;
}

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Error: Stack Underflow! Nothing to pop.\n");
        exit(1);
    }
    return s->arr[(s->top)--];
}

char peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Error: Stack is empty! No top element.\n");
        exit(1);
    }
    return s->arr[s->top];
}

int precedence(char op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToPostfix(char infix[], char postfix[])
{
    Stack s;
    initializeStack(&s);
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(&s, ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty(&s) && peek(&s) != '(')
                postfix[j++] = pop(&s);
            pop(&s); // remove '('
        }
        else if (isOperator(ch))
        {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch))
                postfix[j++] = pop(&s);
            push(&s, ch);
        }
    }

    while (!isEmpty(&s))
        postfix[j++] = pop(&s);

    postfix[j] = '\0';
}

int main()
{
    char infix[SIZE], postfix[SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
