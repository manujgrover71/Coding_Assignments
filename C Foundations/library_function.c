/*
 * Implementation of library functions like strncmp, strncpy, strncat in C.
 * 
 * Compilation: gcc library_function.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Date: 28/07/2021
 * 
 * Resources:
 * https://www.tutorialspoint.com/c_standard_library/c_function_strncmp.htm (Strncmp function in c description.)
*/
#include <stdio.h>

/*
 * Function to get the smaller integer out of the arguments.
 * 
 * Parameters:
 * a: first integer.
 * b: second integer.
 * 
 * Returns: minimum from both.
 *
*/
int min(int a, int b) {
    return a < b ? a : b;
}

/*
 * Function to get string length.
 *
 * Parameters:
 * *str = string whose length need to be calculated.
 *
 * Returns: length of the string.
*/
int getLen(char *str) {
    int len = 0;

    while(*str != '\0') {
        len++;
        str++;
    }

    return len;
}

/*
 * Function that compare first n characters of given two strings.
 * 
 * Parameters:
 * s: first string.
 * t: second string.
 * n: maximum length till both strings are to be compared.
 * 
 * Returns:
 * -1: if first string is smaller than the second string in the first n characters.
 * 0: if first string is equal to the second string in the first n characters.
 * 1: if first string is greater than the second string in the first n characters.
*/
int strncmp(char *s, char *t, size_t n) {
    
    // get length of both strings.
    int lenS = getLen(s);
    int lenT = getLen(t);
    
    // run the loop till the minimum lengths or n is smaller than both lengths.
    for(int i = 0; i < min(min(lenS, lenT), n); i++) {
        if(s[i] < t[i]) {
            return -1;
        }else if(s[i] > t[i]) {
            return 1;
        }
    }
    
    // if n is smaller than length of both strings, return 0, as both are equal till n characters.
    if(n <= lenS && n <= lenT)
        return 0;
        
    // else check whose length is greater.
    if(lenS < lenT) {
        return -1;
    }else {
        return 1;
    }
}

/*
 * Function to concatinate upto n character from second string to the first string.
 * 
 * Parameters:
 * s: first string.
 * t: second string.
 * n: maximum number of characters to be concatinated
 * 
 * Returns: nothing.
*/ 
void strncat(char *s, char *t, size_t n) {
    
    // get length of both strings.
    int lenS = getLen(s);
    int lenT = getLen(t);
    
    // string iterating from the last of first string and try to add n characters from the second string.
    for(int i = lenS; i < min(lenS + lenT, lenS + n); i++) {
        s[i] = t[i - lenS];
    }
    
    // at the last, add a null character.
    s[min(lenS + lenT, lenS + n)] = '\0';
}

/*
 * Function to copy first n character from second string to the first string.
 * 
 * Parameters:
 * s: first string.
 * t: second string.
 * n: maximum characters to be copied from second string to first string.
 * 
 * Returns: nothing.
*/
void strncpy(char *s, char *t, size_t n) {
    // get length of second string.
    int lenT = getLen(t);
    
    // copy first n characters or till the end of second string.
    for(int i = 0; i < min(n, lenT); i++) {
        s[i] = t[i];
    }
    
    // add null character at last.
    s[n] = '\0';
}

int main() {
    char s[100];
    char t[100];
    
    // testing strncpy function
    scanf("%s", t);
    strncpy(s, t, 10);
    printf("%s\n", s);
    
    // testing strncat function
    scanf("%s %s", s, t);
    strncat(s, t, 5);
    printf("%s\n", s);
    
    // testing strncmp function
    scanf("%s %s", s, t);
    int res = strncmp(s, t, 5);
    
    if(res < 0) {
        printf("String s is smaller than string t");
    }else if(res == 0) {
        printf("String s and t are equal");
    }else {
        printf("String is greater than string t");
    }
}