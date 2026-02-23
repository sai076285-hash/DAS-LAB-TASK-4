#include <stdio.h>

#define MAX 50

struct poly {
    int coeff;
    int exp;
};

int main() {
    struct poly A[MAX], B[MAX], C[100];
    int m, n, i, j, k = 0;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &m);

    printf("Enter coefficient and exponent:\n");
    for(i = 0; i < m; i++)
        scanf("%d %d", &A[i].coeff, &A[i].exp);

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent:\n");
    for(i = 0; i < n; i++)
        scanf("%d %d", &B[i].coeff, &B[i].exp);

    // Multiply
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            C[k].coeff = A[i].coeff * B[j].coeff;
            C[k].exp = A[i].exp + B[j].exp;
            k++;
        }
    }

    // Combine like terms
    for(i = 0; i < k; i++) {
        for(j = i + 1; j < k; j++) {
            if(C[i].exp == C[j].exp) {
                C[i].coeff += C[j].coeff;
                C[j].coeff = 0;
            }
        }
    }

    printf("\nResultant Polynomial after Multiplication:\n");
    for(i = 0; i < k; i++) {
        if(C[i].coeff != 0)
            printf("%dx^%d ", C[i].coeff, C[i].exp);
    }

    return 0;
}
