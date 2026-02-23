#include <stdio.h>

#define MAX 50

struct poly {
    int coeff;
    int exp;
};

int main() {
    struct poly A[MAX], B[MAX], C[MAX];
    int m, n, i = 0, j = 0, k = 0;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &m);

    printf("Enter coefficient and exponent (descending order):\n");
    for(i = 0; i < m; i++)
        scanf("%d %d", &A[i].coeff, &A[i].exp);

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent (descending order):\n");
    for(i = 0; i < n; i++)
        scanf("%d %d", &B[i].coeff, &B[i].exp);

    i = j = 0;

    while(i < m && j < n) {
        if(A[i].exp == B[j].exp) {
            C[k].coeff = A[i].coeff + B[j].coeff;
            C[k].exp = A[i].exp;
            i++; j++; k++;
        }
        else if(A[i].exp > B[j].exp)
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while(i < m)
        C[k++] = A[i++];

    while(j < n)
        C[k++] = B[j++];

    printf("\nResultant Polynomial:\n");
    for(i = 0; i < k; i++)
        printf("%dx^%d ", C[i].coeff, C[i].exp);

    return 0;
}
