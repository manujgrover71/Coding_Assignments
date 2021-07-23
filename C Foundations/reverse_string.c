/*
 * Program to reverse a string using character pointers.
 *
 * Compilation: gcc reverse_string.c
 * Execution: ./a.out
 *
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Date: 23/07/2021
 *
*/

#include <stdio.h>

/*
 * Function to get string length using character pointer
 *
 * Parameters:
 * *str = character pointer to the string whose length need to be calculated.
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
 * Function used to swap two characters using pointers.
 *
 * Parameters:
 * *a: pointer pointing to the first character.
 * *b: pointer pointing to the second character.
 *
 * Returns: nothing.
*/
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Function that reverse the string using character pointer.
 *
 * Parameters:
 * *s: pointer pointing to the string.
 *
 * Returns: nothing.
*/
void reverse(char *s) {
    // take the length of string.
    int len = getLen(s);

    for(int i = 0; i < len / 2; i++) {
	swap(s + i, s + (len - i - 1));
    }
}

int main() {
   char str[100];

   // take the string input (including spaces).
   scanf("%[^\n]%*c", str);

   // reverse the string.
   reverse(str);

   // print the string.
   printf("%s\n", str);
}
