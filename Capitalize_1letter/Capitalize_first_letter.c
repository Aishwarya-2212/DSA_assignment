#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    FILE *input, *output;
    char s[MAX_SIZE];
    int i;

    input = fopen("input.txt", "r");
    if (input == NULL) {
        perror("\nError in opening input file\n");
        return 1;
    }

    if (fgets(s, MAX_SIZE, input) == NULL) {
        perror("\nError reading input from file\n");
        return 1;
    }

    fclose(input);

    // Convert first letter of each word to uppercase
    for (i = 0; s[i] != '\0'; i++) {
        if (i == 0 || s[i - 1] == ' ') {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = s[i] - 32;
            }
        }
    }

    output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("\nError in opening output file\n");
        return 1;
    }

    fprintf(output, "%s\n", s); // Corrected this line

    fclose(output);

    return 0;
}
