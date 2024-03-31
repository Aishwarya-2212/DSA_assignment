#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // For isdigit function

#define SIZE 100

struct stack {
    int data[SIZE];
    int top;
};

int evaluate_postfix(struct stack *s, char expr[]);
int isFull(struct stack *s);
int pop(struct stack *s);
int isempty(struct stack *s);
void push(struct stack *s, int e);

int main() {
    struct stack s;
    int result;
    s.top = -1;
    char expr[SIZE];

    FILE *input, *output;

    // Open input file
    input = fopen("input.txt", "r");
    if (input == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Read postfix expression from input file
    fscanf(input, "%s", expr);
    fclose(input);

    // Evaluate postfix expression
    result = evaluate_postfix(&s, expr);

    // Open output file
    output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("Error opening output file");
        return 1;
    }

    // Write result to output file
    fprintf(output, "Result: %d\n", result);

    fclose(output);
    return 0;
}

int isFull(struct stack *s) {
    return s->top == SIZE - 1;
}

int pop(struct stack *s) {
    if (!isempty(s)) {
        int e = s->data[s->top];
        s->top--;
        return e;
    }
    return -1; // Indicate stack underflow
}

int isempty(struct stack *s) {
    return s->top == -1;
}

void push(struct stack *s, int e) {
    if (!isFull(s)) {
        s->top++;
        s->data[s->top] = e;
    }
}

int evaluate_postfix(struct stack *s, char expr[]) {
    int i = 0;
    int operand1, operand2, result;

    while (expr[i] != '\0') {
        if (isdigit(expr[i])) {
            push(s, expr[i] - '0');
        } else {
            operand2 = pop(s);
            operand1 = pop(s);
            switch (expr[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(EXIT_FAILURE);
            }
            push(s, result);
        }
        i++;
    }
    return pop(s);
}
