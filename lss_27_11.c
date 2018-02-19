#include "lss_27_11.h"

int lss_27_11(int n, double* A, double* B, double* X, double* tmp) {

    return 0;
}


int lss_memsize_27_11(int n) {
    return n;
}

void solve()
{
    int n;

    FILE *input = fopen("in.txt", "r");
    fscanf(input, "%d", &n);
    double A[n * n], B[n], X[n], tmp[2 * lss_memsize_27_11(n)], temp, sum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fscanf(input, "%lf", &temp);
            A[i * n + j] = temp;
        }
    }
    for (int k = 0; k < n; ++k) {
        fscanf(input, "%lf", &B[k]);
//        B[k] = temp;
    }
    fclose(input);

    // A = St * tmp * S
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < i; ++k) {
            sum += A[k * n + i] * A[k * n + i] * tmp[k];
        }
        tmp[i] = sgn(A[i * n + i] - sum);
        sum = 0;

        for (int j = 0; j < n; ++j) {
            if (i == j) {
                for (int k = 0; k < i; ++k) {
                    sum += A[k * n + i] * A[k * n + i] * tmp[k];
                }
                temp = sqrt(abs(A[i * n + i] - sum));
                A[i * n + i] = temp;
                sum = 0;
            } else if (i < j) {
                for (int k = 0; k < i; ++k) {
                    sum += A[k * n + i] * tmp[k] * A[k * n + j];
                }
                temp = (A[i * n + j] - sum) / A[i * n + i] * tmp[i];
                A[i * n + j] = temp;
                sum = 0;
            } else {
                A[i * n + j] = 0;
            }
        }
    }

    // St * tmp = b
    transpose(n, A);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            sum += A[i * n + j] * tmp[n + j] * tmp[j];
        }
        tmp[n + i] = (B[i] - sum) / A[i * n + i] * tmp[i];
        sum = 0;
    }

    // tmp * S * X = tmp
    transpose(n, A);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; --j) {
            sum += A[i * n + j] * X[j];
        }
        X[i] = (tmp[n + i] - sum) / A[i * n + i];
        sum = 0;
    }

    FILE *out = fopen("out_27_11.txt", "w");
    for (int i = 0; i < n; ++i) {
        fprintf(out, "%lf\n", X[i]);
    }
    fclose(out);
}

void transpose(int n, double *A)
{
    double  tmp;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            tmp = A[j * n + i];
            A[j * n + i] = A[i * n + j];
            A[i * n + j] = tmp;
        }
    }
}
