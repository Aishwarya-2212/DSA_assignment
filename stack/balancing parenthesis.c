#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct stack {
    int data[SIZE];
    int top;
};

int balanced_parenthesis(struct stack *s, char str[]);
int isFull(struct stack *s);
int pop(struct stack *s);
int isempty(struct stack *s);
void push(struct stack *s, int e);

int main() {
    struct stack s;
    int b;
    s.top = -1;
    char str[SIZE];

    FILE *input, *output;

    // Open input file
    input = fopen("input.txt", "r");
    if (input == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Read expression from input file
    fscanf(input, "%s", str);
    fclose(input);

    // Check balanced parenthesis
    b = balanced_parenthesis(&s, str);

    // Open output file
    output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("Error opening output file");
        return 1;
    }

    // Write result to output file
    if (b == 1) {
        fprintf(output, "The equation is balanced.\n");
    } else {
        fprintf(output, "The equation is not balanced.\n");
    }

    fclose(output);
    return 0;
}

int isFull(struct stack *s) {
    return s->top == SIZE - 1;
}

int pop(struct stack *s) {
    int e = s->data[s->top];
    s->top--;
    return e;
}

int isempty(struct stack *s) {
    return s->top == -1;
}

void push(struct stack *s, int e) {
    s->top++;
    s->data[s->top] = e;
}

int balanced_parenthesis(struct stack *s, char str[]) {
    char x;
    int i = 0;

    while (str[i] != '\0') {
        switch (str[i]) {
            case '[':
            case '{':
            case '(':
                if (isFull(s)) {
                    printf("Stack overflow! Expression too large.\n");
                    exit(EXIT_FAILURE);
                }
                push(s, str[i]);
                break;

            case ')':
                if (isempty(s))
                    return 0;
                x = pop(s);
                if (x != '(')
                    return 0;
                break;

            case '}':
                if (isempty(s))
                    return 0;
                x = pop(s);
                if (x != '{')
                    return 0;
                break;

            case ']':
                if (isempty(s))
                    return 0;
                x = pop(s);
                if (x != '[')
                    return 0;
                break;
        }
        i++;
    }

    if (isempty(s))
        return 1;

    return 0;
}




