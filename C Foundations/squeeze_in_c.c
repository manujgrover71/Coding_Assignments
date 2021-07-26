/* 
 * Program to that deletes each character in first string that matches any character in the second string.
 * 
 * Compilation: gcc squeeze_in_c.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * C Fundamentals
 * Date: 26/07/2021
*/

#include <stdio.h>

/* 
 * Function the left shift element by 1 from a given starting index in the given string.
 * 
 * Parameters:
 * str: string whose characters are to be left shift by 1.
 * start: starting index.
 * 
 * Returns: Nothing.
*/ 
void shift(char *str, int start) {
    for(int i = start; str[i] != '\0'; i++) {
        str[i] = str[i + 1];
    }
}

/*
 * Function that deletes each character in first string that matches any character in the second string.
 *
 * Parameters:
 * s1: first string.
 * s2: second string.
 * 
 * Returns: Nothing.
*/
void squeeze(char *s1, char *s2) {

    // keep track of character present in s2.
    int vis[256] = {0};

    // mark present elements.
    for(int i = 0; s2[i] != '\0'; i++) {
        vis[s2[i]] = 1;
    }
    
    // if we find any present elements, just make left shift.
    for(int i = 0; s1[i] != '\0'; i++) {
        while(s1[i] != '\0' && vis[s1[i]]) {
            shift(s1, i);
        }
    }
}

int main() {
    char s1[100], s2[100];
    // scan the strings.
    scanf("%s %s", s1, s2);

    // squeeze s1.
    squeeze(s1, s2);
    
    // print the squeezed s1 string.
    printf("%s\n", s1);
}
