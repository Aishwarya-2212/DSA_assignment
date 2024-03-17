#include <stdio.h>

int main() {
    int num, fact = 1;
    FILE *input, *output;

    // Open input file
    input = fopen("input.txt", "r");
    if (input == NULL) {
        perror("Error in opening the input file");
        return 1;
    }

    // Read integer from input file
    if (fscanf(input, "%d", &num) != 1) {
        perror("Error reading from input file");
        fclose(input);
        return 1;
    }

    // Close input file
    fclose(input);

    // Calculate factorial
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }

    // Open output file
    output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("Error in opening the output file");
        return 1;
    }

    // Write factorial to output file
    fprintf(output, "%d", fact);

    // Close output file
    fclose(output);

    printf("Factorial calculated and written to output file successfully.\n");

    return 0;
}
