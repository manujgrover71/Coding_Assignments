/*
 * Program to find GCD of two numbers.
 *
 * Compilation: gcc gcd.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Recursion (Assignment - 5)
 * Date: 03/08/2021
*/
#include <stdio.h>

/*
 * Function that finds the GCD of the given two numbers.
 * 
 * Parameters:
 * a: first number.
 * b: second number.
 * 
 * Returns: GCD of a and b.
*/
int gcd(int a, int b) {
    if(b == 0)
        return a;
        
    return gcd(b, a % b);
}


int main() {    
    int a, b;
    // take input.
    scanf("%d %d", &a, &b);
    
    // print gcd.
    printf("%d", gcd(a, b));
}