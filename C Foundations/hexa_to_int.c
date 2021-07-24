/*
 * Program to convert string of hexadecimal digits into its equivalent integer value.
 *
 * Compilation: gcc hexa_to_int.c
 * Execution: ./a.out
 *
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Date: 24/07/2021
 *
*/

#include <stdio.h>

/*
 * Function to convert hex character to its equivalent decimal value.
 *
 * Parameters:
 * ch: the hex character whose equivalent decimal value is to find.
 *
 * Returns: decimal equivalent value of hex character.
*/
int getDecimalVal(char ch) {
    
    // if character is between [0 - 9], the decimal value is [0 - 9].
    if(ch >= '0' && ch <= '9')
        return (ch - '0');

    // convert upper case to lower case.
    if(ch >= 'A' && ch <= 'Z')
        ch += 32;

    // return the equivalent value;
    return (ch - 'a') + 10;
}

/*
 * Function to find the length of string.
 *
 * Parameters:
 * *str = character array (string) whose length is to find.
 *
 * Returns: Length of string.
*/
int getLen(char *str) {
    int len = 0;
    int i = 0;

    while(str[i] != '\0') {
	i++;
	len++;
    }

    return len;
}

/*
 * Function to convert hexadecimal string to its equivalent decimal value.
 *
 * Parameters:
 * *str: hexadecimal character array (string) whose decimal equivalent is to be find.
 *
 * Returns: Decimal equivalent of hexadecimal string.
*/
int htoi(char *str) {

    // get the length.
    int len = getLen(str);    

    int powStart = 1;

    int res = 0;
    
    for(int i = len - 1; i >= 0; i--) {
        if(str[i] == 'X' || str[i] == 'x') {
            break;
        }

        // get decimal equivalent of this character.
	// example: '0' = 0, '9' = 9, 'A' = 10, 'F' = 15.
        int val = getDecimalVal(str[i]);

        res += powStart * val;
        powStart *= 16;
    }

    // return the result.
    return res;
}

int main() {
    char str[100];
    
    // take the string input
    scanf("%[^\n]%*c", str);

    // get the decimal value.
    int res = htoi(str);

    // print the decimal value.
    printf("%d\n", res);
}
