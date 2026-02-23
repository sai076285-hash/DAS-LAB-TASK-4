#include <stdio.h>

#define MAX 100

int main() {
    int sparse[MAX][3], transpose[MAX][3];
    int i, j, k = 1;

    int rows, cols, terms;

    printf("Enter number of rows, columns and non-zero terms: ");
    scanf("%d %d %d", &rows, &cols, &terms);

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = terms;

    printf("Enter row, column and value for each non-zero term:\n");
    for(i = 1; i <= terms; i++) {
        scanf("%d %d %d", &sparse[i][0], &sparse[i][1], &sparse[i][2]);
    }

    // Transpose logic
    transpose[0][0] = cols;
    transpose[0][1] = rows;
    transpose[0][2] = terms;

    for(i = 0; i < cols; i++) {
        for(j = 1; j <= terms; j++) {
            if(sparse[j][1] == i) {
                transpose[k][0] = sparse[j][1];
                transpose[k][1] = sparse[j][0];
                transpose[k][2] = sparse[j][2];
                k++;
            }
        }
    }

    printf("\nTranspose Matrix (3-Tuple Form):\n");
    for(i = 0; i <= terms; i++) {
        printf("%d %d %d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }

    return 0;
}
