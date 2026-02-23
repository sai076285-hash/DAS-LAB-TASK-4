#include <stdio.h>

#define MAX 100

int main() {
    int A[MAX][3], B[MAX][3], C[MAX][3];
    int i = 1, j = 1, k = 1;

    int termsA, termsB;

    printf("Enter rows, cols and non-zero terms of Matrix A: ");
    scanf("%d %d %d", &A[0][0], &A[0][1], &termsA);
    A[0][2] = termsA;

    printf("Enter elements of A (row col value):\n");
    for(i = 1; i <= termsA; i++)
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);

    printf("Enter rows, cols and non-zero terms of Matrix B: ");
    scanf("%d %d %d", &B[0][0], &B[0][1], &termsB);
    B[0][2] = termsB;

    printf("Enter elements of B (row col value):\n");
    for(i = 1; i <= termsB; i++)
        scanf("%d %d %d", &B[i][0], &B[i][1], &B[i][2]);

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    i = j = 1;

    while(i <= termsA && j <= termsB) {
        if(A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
        else if(A[i][0] < B[j][0] || 
               (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
    }

    while(i <= termsA) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }

    while(j <= termsB) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;

    printf("\nResultant Sparse Matrix:\n");
    for(i = 0; i < k; i++)
        printf("%d %d %d\n", C[i][0], C[i][1], C[i][2]);

    return 0;
}
