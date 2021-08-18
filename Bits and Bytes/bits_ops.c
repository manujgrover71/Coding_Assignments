/*
 * Implementation of bitwise operators without using the actual operator.
 * 
 * Compilation: gcc bits_ops.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
*/

#include <stdio.h>


/* 
 * Function to extract byte y from int x.
 *
 * Parameters:
 * x: the integer whose byte is to be extracted.
 * y: the byte to be extracted.
 * 
 * Returns: y-th byte from int x.
 */
int getByte(int x, int y) {
    return (x >> (8 * y)) & 0xFF;
}

/*
 * Function to compute bitwise and between two numbers.
 * 
 * Paramters:
 * x: first number.
 * y: second number.
 * 
 * Returns: bitwise and between x and y.
*/ 
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

/*
 * Function to compute bitwise xor between two numbers.
 *
 * Parameters:
 * x: first number
 * y: second number
 * 
 * Returns: bitwise xor between x and y.
*/
int bitXor(int x, int y) {
    int first = ~(~x & ~y);
    int second = ~(x & y);
    
    return first & second;
}

/*
 * Function to get the sign of integer.
 * 
 * Paramters:
 * x: whose sign is to be calculated.
 * 
 * Returns:
 * 1 if positive, 0 if zero, -1 if negative.
*/
int sign(int x) {
    return ((!!x) | (x >> 31));
}

/*
 * Function to shift x to the right by n, using a logical shift.
 *
 * Parameters:
 * x: the number whose bits is to be shifted.
 * n: the times to be shifted.
 * 
 * Returns: x shifted by n.
*/
int logicalShift(int x, int n) {   
    return (x >> n) & (~(((1 << 31) >> n) << 1));
}

/*
 * Implementation of ternary operator without using ? or :
 * 
 * Parameters:
 * x: condition value
 * y: first value
 * z: second value.
 * 
 * Returns: if condition is true, returns first value else second value.
*/
int conditional(int x, int y, int z) {
    return (!!x) * y + (!x) * z;
}

/*
 * Function to compute !x without using !.
 * 
 * Parameters:
 * x: the integer whose ! is to be returned.
 * 
 * Returns: !x
*/
int bang(int x) {
    return (((~x + 1) | x) >> 31) + 1;
}

/*
 * Function to inverst n bits starting from position p of integer x.
 * 
 * Returns: x with the n bits that begin at position p inverted
*/ 
int invert(int x, int p, int n) { 
    return   x ^ (~(~0 << n) << (p + 1 - n));
}