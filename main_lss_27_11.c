//
// Created by Oysha on 18/02/2018.
//

#include "lss_27_11.h"


void print_help();

void print_matrix(double *X, int n);

int main(int argc, char *argv[]) {

    char input_filename[64];
    char output_filename[64];
    strcpy(input_filename,"lss_27_11_in.txt");
    strcpy(output_filename,"lss_27_11_out.txt");
    int p = 0, d = 0, h = 0, e = 0, t = 0;
    if (argc > 1) for (int i = 1 ; i < argc; i++) {
            if (strcmp(argv[i],"-p") == 0) p = 1;
            else if (strcmp(argv[i], "-t") == 0) t = 1;
            else if (strcmp(argv[i], "-e") == 0) e = 1;
            else if (strcmp(argv[i], "-d") == 0) d = 1;
            else if (strcmp(argv[i], "-h") == 0) h = 1;
            else if (i == 1 && argv[i][0] != '-') strcpy(input_filename, argv[1]);
            else if (i == 2 && argv[i][0] != '-') strcpy(output_filename, argv[2]);
            else exit(5);
        }

    int n;
    double *A, *B, *X, *tmp;
    FILE *input = fopen(input_filename, "r");
    if (input == NULL) {
        exit(1);
    }
    fscanf(input, "%d", &n);

    A = (double *)malloc(n * n * sizeof(double));
    B = (double *)malloc(n * sizeof(double));
    X = (double *)malloc(n * sizeof(double));
    tmp = (double *)malloc(2 * lss_memsize_27_11(n)* sizeof(double));

    // read matrix A and B
    for (int i = 0; i < n * n; ++i) {
        fscanf(input, "%lf", A + i);
    }
    for (int k = 0; k < n; ++k) {
        fscanf(input, "%lf", B + k);
    }
    fclose(input);

    clock_t begin = clock();
    int answ = lss_27_11(n, A, B, X, tmp);
    clock_t end = clock();
    double time = (double)(end - begin) / CLOCKS_PER_SEC;

    // print result
    FILE *output = fopen(output_filename, "w");
    if (output == NULL)
        exit(1);
    if (answ == 0) {
        fprintf(output, "%d\n", n);
        for (int i = 0; i < n; ++i) {
            fprintf(output, "%1.9lf\n", X[i]);
        }
        if (e)
            printf("Solved correctly.\n");
    } else if (answ == 1) {
        fprintf(output, "0");
        if (e)
            printf("No solution.\n");
    } else {
        fprintf(output, "-1");
        if (e)
            printf("Method is not usable.\n");
    }
    fclose(output);

    if (p)
        print_matrix(X, n);
    if (h)
        print_help();

    if (t)
        printf("Execution time: %lf", time);

    // free memory
    free(A);
    free(B);
    free(X);
    free(tmp);
    exit(0);
    return 0;
}

void print_help()
{
    printf("Usage: lss [input_file_name] [output_file_name] [options]\n"
                   "Where options include:\n"
                   "  -d   print debug messages [default OFF]\n"
                   "  -e   print errors [default OFF]\n"
                   "  -p   print matrix [default OFF]\n"
                   "  -t   print execution time [default OFF]\n"
                   "  -h,  help	print this and exit\n"
                   "Default input_file_name value is lss_27_11_in.txt, \n"
                   "default output_file_name value is lss_27_11_out.txt.\n"
    );
}

void print_matrix(double *X, int n)
{
    for (int i = 0; i < n; ++i) {
        printf("X[%i] = %lf", i, X[i]);
    }
}
