/*
 * Program to multiply two matrices of size nxn.
 *
 * Compilation: gcc matrix_multiplication.c
 * Execution: ./a.out
 *
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Date: 23/07/2021
 *
*/

#include <stdio.h>


/*
 * Function to scan the given matrix of size nxn.
 *
 * Parameters:
 * n: dimension of matrix.
 * matrix: matrix whose input is to be taken.
 *
 * Returns: nothing.
*/
void scan_matrix(int n, int matrix[n][n]) {
    for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	    scanf("%d", &matrix[i][j]);
	}
    }
}

/*
 * Function to multiply two matrices and put the result into another matrix.
 *
 * Parameters:
 * n: dimenstion of matrix.
 * matrix1: first matrix.
 * matrix2: second matrix.
 * res_matrix: resultant matrix.
 *
 * Returns: nothing.
*/
void multiply_matrix(int n, int matrix1[n][n], int matrix2[n][n], int res_matrix[n][n]) {
    
    for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	    res_matrix[i][j] = 0;
	    for(int k = 0; k < n; k++) {
		res_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
	    }
	}
    }
}

/*
 * Function to print the given matrix.
 *
 * Parameters:
 * n: dimensions of nxn matrix.
 * matrix: matrix whose is to be printed.
 *
 * Returns: nothing.
*/
void print_matrix(int n, int matrix[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
	    printf("%d ", matrix[i][j]);
	}
	printf("\n");
    }
}

int main() {
    int n;
    // take the input of dimensions of matrix.
    scanf("%d", &n);

    int matrix1[n][n], matrix2[n][n];

    // scan the first matrix.
    scan_matrix(n, matrix1);

    // scan the second matrix.
    scan_matrix(n, matrix2);
   
    // resultant matrix.
    int res_matrix[n][n];

    // multiply the matrices.
    multiply_matrix(n, matrix1, matrix2, res_matrix);

    // print the resultant matrix.
    print_matrix(n, res_matrix);
}
