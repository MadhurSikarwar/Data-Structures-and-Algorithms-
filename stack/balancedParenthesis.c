#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop
char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

// Check matching pair
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    return 0;
}

int main() {
    char exp[MAX];
    int i;

    printf("Enter expression: ");
    scanf("%s", exp);

    for (i = 0; i < strlen(exp); i++) {

        // If opening bracket → push
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }

        // If closing bracket
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {

            if (top == -1) {
                printf("Not Balanced\n");
                return 0;
            }

            char popped = pop();

            if (!isMatchingPair(popped, exp[i])) {
                printf("Not Balanced\n");
                return 0;
            }
        }
    }

    if (top == -1)
        printf("Balanced Parenthesis\n");
    else
        printf("Not Balanced\n");

    return 0;
}
