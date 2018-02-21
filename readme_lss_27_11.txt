Choletsky decomposition

files: main_lss_27_11.c lss_27_11.h lss_27_11.cXX

in this method we interpreter A = St * d * S
where:
S is matrix solved with formulas
S* is transposed S matrix
d is matrix contains 1 or -1

A is matrix of coefficients.
B is matrix of free coefficients. 
X is matrix of answers.
tmp[0..n-1] is matrix for d
tmp[n..2*n-1] is matrix for interim calculations

This method works only with symmetric matrix:
is_symmetric(double *A) checks if A is symmetric, returnes 1 if not.

St is transposed matrix S.
transpose(double *A) transposes matrix A.

code 1 can be returned only if there is devision by 0.

Exit codes:
0 - works correctly 
1 - cannot open input/output file
2 - matrix A is incorrect
3 - dimension of matrix A is too small
4 - 
5 - incorrect command 

Output values:
 0 - works correctly. Wrote X matrix in output file.
 1 - works сorrectly, but problem has no solution. Wrote "0" in output file.
-1 - method doesn't usable for this problem, because matrix A is not symmetric.

Commands:
-d - prints ?
-e - prints errors for returned values from lss_27_11.c
-p - prints X matrix
-t - prints execution time
-h - prints help table of commands
