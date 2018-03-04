Choletsky decomposition

files: main_lss_27_11.c lss_27_11.h lss_27_11.c

input values:
n - matrix's dimension
A - matrix of coefficients
B - matrix of free coefficients

output values:
X is matrix of answers

In this method we interpreter A := St * d * S
where:
S is matrix solved with formulas
S* is transposed S matrix
d is matrix contains 1 or -1

tmp[0..n-1] is matrix for d
tmp[n..2*n-1] is matrix for interim calculations

This method works only with symmetric matrix:
is_symmetric(double *A) checks if A is symmetric, returns 1 if it's not.

St is transposed matrix S.
transpose(double *A) transposes matrix A.

Exit codes:
0 - works correctly
1 - wrong command
2 - can’t open file
3 - can’t read n
4 - incorrect input (n < 0)
5 - incorrect input (can’t read A)
6 - incorrect input (can’t read B)

Output values:
 0 - works correctly. Wrote X matrix in output file.
 1 - works сorrectly, but problem has no solution. There's division by 0.
-1 - method doesn't usable for this problem, because matrix A is not symmetric.

Commands:
-d - prints ?
-e - prints errors for returned values from lss_27_11.c
-p - prints X matrix
-t - prints execution time
-h - prints help table of commands
