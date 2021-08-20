/*
 * Program to print n even numbers from fibonacci series.
 * 
 * Compilation: gcc n_even_fibonacci.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
*/
#include <stdio.h>

int main() {
    
    int n;
    scanf("%d", &n);
    
    // it can be obeserved that every 3rd fibonacci number is even.
    // hence we can just print every 3rd fibonacci number till n numbers are reached.
    int first = 2; // 3rd fibonacci number.
    int second = 8; // 6th fibonacc number.
    
    if(n == 1) {
        printf("%d", first);
    }else if(n == 2) {
        printf("%d %d", first, second);
    }else {
        
        int count = 2;    
        int third;
        
        while(count < n) {
            // get the next element.
            third = 4 * second + first;
            
            // set the other elements.
            first = second;
            second = third;
            count++;
        }
        
        printf("%d", third);
    }
}