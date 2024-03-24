#include <stdio.h>

void readMatrix(FILE*, int[][10], int, int);
void initializeMatrix(int[][10], int, int);
void printMatrix(FILE*, int[][10], int, int);
void multiplyMatrix(int[][10], int[][10], int[][10], int, int, int, int);

int main() {
    int a[10][10], b[10][10], c[10][10];
    int m, n, x, y;

    // Open input file for matrix A
    FILE *input= fopen("matrix_a.txt", "r");
    if (input == NULL) {
        perror("Error in opening matrix_a.txt");
        return 1;
    }

    // Read order of matrix A
    fscanf(input, "%d%d", &m, &n);

    // Read matrix A
    readMatrix(input, a, m, n);

    // Close input file for matrix A
    fclose(input);

    // Open input file for matrix B
    FILE *input= fopen("matrix_b.txt", "r");
    if (input == NULL) {
        perror("Error in opening matrix_b.txt");
        return 1;
    }

    // Read order of matrix B
    fscanf(input, "%d%d", &x, &y);

    // Read matrix B
    readMatrix(input, b, x, y);

    // Close input file for matrix B
    fclose(input);

    // Initialize matrix C
    initializeMatrix(c, m, y);

    // Open output file for writing
    FILE *output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("Error in opening output.txt");
        return 1;
    }

    // Print matrices A and B to output file
    fprintf(output, "Matrix A:\n");
    printMatrix(output, a, m, n);
    fprintf(output, "Matrix B:\n");
    printMatrix(output, b, x, y);

    // Multiply matrices A and B
    multiplyMatrix(c, a, b, m, n, x, y);

    // Print result matrix to output file
    fprintf(output, "Product:\n");
    printMatrix(output, c, m, y);

    // Close output file
    fclose(output);

    printf("Matrix multiplication completed. Result written to output.txt.\n");

    return 0;
}

void readMatrix(FILE *input, int a[][10], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(input, "%d", &a[i][j]);
        }
    }
}

void initializeMatrix(int a[][10], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
}

void printMatrix(FILE *output, int a[][10], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(output, "%d ", a[i][j]);
        }
        fprintf(output, "\n");
    }
}

void multiplyMatrix(int c[][10], int a[][10], int b[][10], int m, int n, int x, int y) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < x; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
