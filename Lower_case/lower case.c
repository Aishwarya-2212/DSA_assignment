#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *input, *output;
    char s[100];

    // Open input file
    input = fopen("input.txt", "r");
    if (input == NULL) {
        perror("Error in opening the input file");
        return 1;
    }

    // Read string from input file
    if (fgets(s, sizeof(s), input) == NULL) {
        perror("Error reading from input file");
        fclose(input);
        return 1;
    }

    // Close input file
    fclose(input);

    // Convert uppercase letters to lowercase
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = tolower(s[i]);
    }

    // Open output file
    output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("Error in opening the output file");
        return 1;
    }

    // Write modified string to output file
    if (fputs(s, output) == EOF) {
        perror("Error writing to output file");
        fclose(output);
        return 1;
    }

    // Close output file
    fclose(output);

    printf("Output file successfully created with the lowercase string.\n");

    return 0;
}
