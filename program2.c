#include <stdio.h>
#define MAX 20

struct Sparse {
    int row;
    int col;
    int value;
};

void readSparse(struct Sparse a[], int *n) {
    int i, j, rows, cols, x;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter matrix elements:\n");
    *n = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &x);
            if (x != 0) {
                a[*n].row = i;
                a[*n].col = j;
                a[*n].value = x;
                (*n)++;
            }
        }
    }
}

void display(struct Sparse a[], int n) {
    int i;
    printf("\nRow\tColumn\tValue\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
}

void add(struct Sparse a[], int n1, struct Sparse b[], int n2) {
    struct Sparse c[MAX];
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (a[i].row == b[j].row && a[i].col == b[j].col) {
            c[k].row = a[i].row;
            c[k].col = a[i].col;
            c[k].value = a[i].value + b[j].value;
            k++; i++; j++;
        } else if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < n1)
        c[k++] = a[i++];
    while (j < n2)
        c[k++] = b[j++];
    printf("\nAddition of Sparse Matrices:");
    display(c, k);
}

void transpose(struct Sparse a[], int n) {
    struct Sparse t[MAX];
    int i;
    for (i = 0; i < n; i++) {
        t[i].row = a[i].col;
        t[i].col = a[i].row;
        t[i].value = a[i].value;
    }
    printf("\nTranspose of Sparse Matrix:");
    display(t, n);
}

int main() {
    struct Sparse a[MAX], b[MAX];
    int n1, n2;
    printf("Enter first sparse matrix\n");
    readSparse(a, &n1);
    printf("\nEnter second sparse matrix\n");
    readSparse(b, &n2);
    printf("\nFirst Sparse Matrix:");
    display(a, n1);
    printf("\nSecond Sparse Matrix:");
    display(b, n2);
    add(a, n1, b, n2);
    transpose(a, n1);
    return 0;
}