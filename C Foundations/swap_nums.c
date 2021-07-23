/*
 * Program to swap two numbers without using third variable.
 * Compilation: gcc -o swap_nums swap_nums.c
 * Exection: ./swap_nums
 *
 * @autor: Manuj, @Roll_Number: 1910990170
 * Date: 23/07/2021
*/

#include <stdio.h>

/*
 * Function that take two variables by reference and swap them.
 *
 * Parameters:
 *
 * a: first number
 * b: second number
 *
 * Returns: nothing.
*/ 
void swap(int *a, int *b) {
    (*a) += (*b);
    (*b) = (*a) - (*b);
    (*a) -= (*b);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    // print the numbers before swapping.
    printf("Before swap\n a=%d, b=%d\n", a, b);

    // pass the number by reference.
    swap(&a, &b);

    // print the numbers after swapping.
    printf("After swap\n a=%d, b=%d\n", a, b);
}
