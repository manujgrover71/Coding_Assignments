/*
 * Program to find the rightmost occurrence of second string in first string.
 *
 * Compilation: gcc strindex_in_c.c
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
 * Function that returns the rightmost occurence of t in s.
 *
 * Parameters:
 * *s: first string.
 * *t: second string.
 *
 * Returns: rightmost occurence of t in s, -1 if there is none.
*/
int strrindex(char *s, char *t) {

    int lenS = getLen(s);
    int lenT = getLen(t);

    if(lenT > lenS)
	return -1;

    for(int i = lenS - lenT; i >= 0; i--) {
	
	int j = i, k = 0;

	while(j < lenS && k < lenT && s[j] == t[k]) {
	    j++, k++;
	}

	if(k == lenT)
	    return i;
    }

    return -1;
}

int main() {
    char s[100], t[100];

    // take string input
    scanf("%s %s", s, t);

    // get result.
    int res = strrindex(s, t);

    // print
    printf("%d\n", res);
}
