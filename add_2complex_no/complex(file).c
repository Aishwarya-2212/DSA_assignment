#include <stdio.h>

#define max 25

int add(int a, int b);

int main() {
    int a[max];
    FILE *input, *output;
    input = fopen("input.txt", "r");
    if (input == NULL) {
        perror("\nError in opening input file\n");
        return 1;
    }

    int i = 0;
    int sum = 0;
    while (fscanf(input, "%d", &a[i]) != EOF && i < max) {
        sum += a[i];
        i++;
    }
    fclose(input);

    int r1, r2, i1, i2, r, imag;
    if (i >= 4) { // Assuming there are at least 4 integers in the input file for two complex numbers
        r1 = a[0];
        i1 = a[1];
        r2 = a[2];
        i2 = a[3];

        r = add(r1, r2);
        imag = add(i1, i2);

        output = fopen("output.txt", "w");
        if (output == NULL) {
            perror("\nError in opening output file\n");
            return 1;
        }

        if (imag >= 0) {
            fprintf(output, "Sum=%d+%di", r, imag);
        } else {
            fprintf(output, "Sum=%d%di", r, imag);
        }

        fclose(output);
    } else {
        printf("Insufficient data for complex numbers in the input file.\n");
    }

    return 0;
}

int add(int a, int b) {
    return a + b;
}

