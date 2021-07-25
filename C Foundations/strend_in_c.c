/*
 * Program to check if the second string occur at the end in the first string.
 *
 * Compilation: gcc strend_in_c.c
 * Execution: ./a,out
 *
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Date: 25/07/2021
*/

#include <stdio.h>

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
 * Function that check if the second string occurs at the end of the first string.
 *
 * Parameters:
 * *s: first string.
 * *t: second string.
 *
 * Returns: 1 if the second string is present at the end of first string, 0 otherwise.
*/
int strend(char *s, char *t) {

    int lenS = getLen(s);
    int lenT = getLen(t);

    if(lenT > lenS)
	return 0;

    lenS--, lenT--;

    while(lenS >= 0 && lenT >= 0 && s[lenS] == t[lenT]) {
	lenS--, lenT--;
    }

    return lenT == -1;
}

int main() {
    char s[100], t[100];

    scanf("%s %s", s, t);

    printf("%d\n", strend(s, t));
}
