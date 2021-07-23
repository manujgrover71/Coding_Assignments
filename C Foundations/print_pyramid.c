/*
 * Program to print pyramid pattern using C.
 * Compilation: gcc -o print_pyramid.out print_pyramind.c
 * Execution: ./print_pyramid.out
 *
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Date: 23/07/2021
 *
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // Iterate n times.
    for(int i = 0; i < n; i++) {
	// print appropriate spaces.
        for(int j = n - i - 1; j >= 0; j--) {
	    printf(" ");
	}

	// print appropriate '#'.
	for(int j = 0; j <= i; j++) {
	    printf("# ");
	}
	
	printf("\n");
    }
}
