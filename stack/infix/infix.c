#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

struct stack {
    char data[SIZE];
    int top;
};

int isOperator(char c);
int precedence(char c);
void infixToPostfix(struct stack *s, char infix[], char postfix[]);
void push(struct stack *s, char item);
char pop(struct stack *s);
char peek(struct stack *s);
int isEmpty(struct stack *s);
int isFull(struct stack *s);

int main() {
    struct stack s;
    char infix[SIZE], postfix[SIZE];

    FILE *input, *output;

    // Open input file
    input = fopen("input.txt", "r");
    if (input == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Read infix expression from input file
    fscanf(input, "%s", infix);
    fclose(input);

    // Convert infix to postfix
    infixToPostfix(&s, infix, postfix);

    // Open output file
    output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("Error opening output file");
        return 1;
    }

    // Write postfix expression to output file
    fprintf(output, "Postfix expression: %s\n", postfix);

    fclose(output);
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

void infixToPostfix(struct stack *s, char infix[], char postfix[]) {
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(s, infix[i]);
        } else if (infix[i] == ')') {
            while (peek(s) != '(' && !isEmpty(s)) {
                postfix[j++] = pop(s);
            }
            pop(s); // Discard '('
        } else {
            while (!isEmpty(s) && precedence(infix[i]) <= precedence(peek(s))) {
                postfix[j++] = pop(s);
            }
            push(s, infix[i]);
        }
        i++;
    }

    while (!isEmpty(s)) {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
}

void push(struct stack *s, char item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = item;
}

char pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

char peek(struct stack *s) {
    return s->data[s->top];
}

int isEmpty(struct stack *s) {
    return s->top == -1;
}

int isFull(struct stack *s) {
    return s->top == SIZE - 1;
}
