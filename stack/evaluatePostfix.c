#include <stdio.h>
#include <ctype.h>   // For isdigit()
#include <stdlib.h>  // For atoi() converts ASCII to integer

#define SIZE 50

typedef struct {
    float arr[SIZE];
    int top;
} Stack;

// Function to push element
void push(Stack *s, float value) {
    s->arr[++(s->top)] = value;
}

// Function to pop element
float pop(Stack *s) {
    return s->arr[(s->top)--];
}

// Function to perform the operation
float operate(float a, float b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': {
            float res = 1;
            for (int i = 0; i < (int)b; i++)
                res *= a;
            return res;
        }
        default: return 0;
    }
}

// Function to evaluate postfix expression
float evaluatePostfix(char *exp) {
    Stack s;
    s.top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        // If operand (digit), push it
        if (isdigit(ch)) {
            push(&s, ch - '0');  // Convert char to int
        }
        // If operator, pop 2 operands and apply operation
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            float b = pop(&s);
            float a = pop(&s);
            float result = operate(a, b, ch);
            push(&s, result);
        }
    }

    return pop(&s); // Final result
}

int main() {
    char exp[50];

    printf("Enter a postfix expression (e.g., 23*54*+9-): ");
    scanf("%s", exp);

    float result = evaluatePostfix(exp);
    printf("Result = %.2f\n", result);

    return 0;
}
