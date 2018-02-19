#include "lss_27_11.h"

int lss_27_11(int n, double* A, double* B, double* X, double* tmp) {

    return 0;
}


int lss_memsize_27_11(int n) {
    return n;
}

void solve()
{
    int n, *d;
    double **A, *B, *X, *Y, tmp, sum = 0;

    FILE *input = fopen("in.txt", "r");
    fscanf(input, "%d", &n);

    X = (double *)malloc(n * sizeof(double));
    Y = (double *)malloc(n * sizeof(double));
    d = (int *)malloc(n * sizeof(int));
    B = (double *)malloc(n * sizeof(double));
    A = (double **)malloc(n * sizeof(double*));
    for (int l = 0; l < n; ++l) {
        A[l] = (double *)malloc(n * sizeof(double));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fscanf(input, "%lf", &tmp);
            A[i][j] = tmp;
        }
    }
    for (int k = 0; k < n; ++k) {
        fscanf(input, "%lf", &B[k]);
//        B[k] = tmp;
    }
    fclose(input);

    // A = St * d * S
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < i; ++k) {
            sum += A[k][i] * A[k][i] * d[k];
        }
        d[i] = sgn(A[i][i] - sum);
        sum = 0;

        for (int j = 0; j < n; ++j) {
            if (i == j) {
                for (int k = 0; k < i; ++k) {
                    sum += A[k][i] * A[k][i] * d[k];
                }
                tmp = sqrt(abs(A[i][i] - sum));
                A[i][i] = tmp;
                sum = 0;
            } else if (i < j) {
                for (int k = 0; k < i; ++k) {
                    sum += A[k][i] * d[k] * A[k][j];
                }
                tmp = (A[i][j] - sum) / A[i][i] * d[i];
                A[i][j] = tmp;
                sum = 0;
            } else {
                A[i][j] = 0;
            }
        }
    }

    // St * Y = b
    transpose(n, A);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            sum += A[i][j] * Y[j] * d[j];
        }
        Y[i] = (B[i] - sum) / A[i][i] * d[i];
        sum = 0;
    }

    // d * S * X = Y
    // d * S
    transpose(n, A);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; --j) {
            sum += A[i][j] * X[j];
        }
        X[i] = (Y[i] - sum) / A[i][i];
        sum = 0;
    }

    FILE *out = fopen("out_27_11.txt", "w");
    for (int i = 0; i < n; ++i) {
        fprintf(out, "%lf\n", X[i]);
    }
    fclose(out);
}

void transpose(int n, double **A)
{
    double  tmp;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            tmp = A[j][i];
            A[j][i] = A[i][j];
            A[i][j] = tmp;
        }
    }
}
