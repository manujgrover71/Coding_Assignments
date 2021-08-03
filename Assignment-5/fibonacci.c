/*
 * Program to print the n times every third element of the fibonacci series.
 * 
 * Compilation: gcc fibonacci.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Recursion (Assignment - 5)
 * Date: 03/08/2021
*/
#include <stdio.h>

/*
 * Function that prints n times every third element of the fibonacci series.
 *
 * Parameters:
 * n: the number of times every third element of fibonacci series is to be printed.
 * 
 * Returns: nothing.
*/
void fib(int n) {
    // first two numbers of fibonacci [1, 1].
    int a = 1, b = 1;
    int c;
    
    // limit till fibonacci series is calculated.
    int count = 0;
    
    // calculating using the relation: fib[i] = fib[i - 1] + fib[i - 2];
    while(count < n) {
        c = a + b;
        a = b;
        b = c;
        
        if((i + 1) % 3 == 0) {
            printf("%d ", c);
            count++;
        }
    }
}

int main() {
    int n;
    // take n from user.
    scanf("%d", &n);
    
    // print the series.
    fib(n);
}