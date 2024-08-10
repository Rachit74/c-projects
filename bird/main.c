#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// y = rows
// x = cols

int rows;
int cols;

int x;
int y;

void randomCordsGenerator() {
    x = rand() % rows;
    y = rand() % cols;
    printf("Generated coordinates: %d %d\n", y, x);
}

void printMatrix(char matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

void spawnBird(char matrix[rows][cols]) {
    randomCordsGenerator();

    // check cords limit
    if (x >= 0 && x < rows && y >= 0 && y < cols) {
        matrix[x][y] = '*';
        printMatrix(matrix);
    } else {
        printf("Invalid Cords\n");
        spawnBird(matrix);
    }
}

int main() {
    printf("Enter Rows: ");
    scanf("%d", &rows);
    printf("Enter Cols: ");
    scanf("%d", &cols);

    srand(time(NULL));

    char matrix[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = '-';
        }
    }

    printMatrix(matrix);
    spawnBird(matrix);

    return 0;
}
