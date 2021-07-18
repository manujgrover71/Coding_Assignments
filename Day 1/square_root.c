/*
 * Program to find square root of any number upto to a given precision using binary search.
 * Return square root of a given number upto a given precision.
 * Compilation: gcc square_root.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover
 * Date: 18/07/2021
 *
*/
#include <stdio.h>

int main() {
    double num;
    int precision;
    
    // take num and precision from user.
    scanf("%lf %d", &num, &precision);
    
    double eps = 0.1;
    
    // create the epsilon value upto the precision.
    for(int i = 0; i < precision - 1; i++) {
        eps /= 10;
    }
    
    // binary search the sqaure root over the range [0, num].
    double left = 0, right = num;
    
    // run the binary search till the epsilon value is satisfied.
    while((right - left) > eps) {
        double mid = left + (right - left) / 2;
        
        if(mid * mid <= num) {
            left = mid;
        }else {
            right = mid;
        }
    }
    
    // print the square root of number with the precision.
    printf("%.*f", precision, left);
}