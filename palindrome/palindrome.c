#include <stdio.h>

int main() {
    int n;
    FILE *input, *output;

    input = fopen("input.txt", "r");
    if (input == NULL) {
        perror("Error in opening the input file");
        return 1;
    }

    fscanf(input, "%d", &n);
    fclose(input);

    int rev = 0;
    int temp;
    int num = n;

    while (n != 0) {
        temp = n % 10;
        rev = (rev * 10) + temp;
        n = n / 10;
    }

    output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("Error in opening the output file");
        return 1;
    }

    if (num == rev) {
        fprintf(output, "Is a Palindrome");
    } else {
        fprintf(output, "Is not a Palindrome");
    }

    fclose(output);

    return 0;
}
