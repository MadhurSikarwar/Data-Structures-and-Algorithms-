#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

typedef struct{
    char arr[SIZE];
    int top;
} Stack;

void initializeStack(Stack *s){
    s->top = -1;
}

int isFull(Stack *s){
    return(s->top == SIZE-1);
}

int isEmpty(Stack *s){
    return (s->top == -1);
}

void push(Stack *s, char ch){
    if(isFull(s)){
        printf("Stack Overflow Error\n");
        exit(1);
    }
    s->arr[++(s->top)] = ch; // increment top before assigning
}

char pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow Error\n");
        exit(1);
    }
    char ch = s->arr[s->top];
    s->top--;
    return ch;
}

char peek(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty, cannot peek\n");
        exit(1);
    }
    return s->arr[s->top];
}

void reverse(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}

void swapBrackets(char str[]) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ')') {
            str[i] = '('; // Corrected: assignment instead of comparison
        }
        else if(str[i] == '(') {
            str[i] = ')'; // Corrected: assignment instead of comparison
        }
    }
}

int isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' );
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}


void InfixToPostfix(char infix[],char postfix[]){
    int i,j = 0;
    char ch;
    Stack s;
    initializeStack(&s);
    //varaible i is for traversing through the infix string 
    //variable j is for traversing through the postfix string
    for(int i = 0;infix[i] != '\0';i++){
        ch = infix[i];
        if(isalnum(ch)){
            postfix[j++] = ch;
        }
        else if(ch == '('){
            push(&s,ch);
        }
        else if(ch == ')'){
            while(!isEmpty(&s) && ch != '('){
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }
        else if(isOperator(ch)){
            while(!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)){
                postfix[j++] = pop(&s);
            }
            push(&s,ch);
        }
    }
    while(!isEmpty(&s)){
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';

}

int main() {
    char infix[SIZE];
    char prefix[SIZE];
    printf("Enter the infix expression\n");
    scanf("%s",infix);
    reverse(infix);
    swapBrackets(infix);
    InfixToPostfix(infix,prefix);
    reverse(prefix);
    printf("The prefix text is\n");
    printf("%s",prefix);
    
}
