/*
 * Program to check if a string is palindrome or not.
 *
 * Compilation: gcc check_palindrome.c
 * Execution: ./a.out
 *
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Date: 23/07/2021
 *
*/

#include <stdio.h>
#include <string.h>

/*
 * Function to check if a character is either a number or a alphabet.
 *
 * Parameters:
 * ch: the character to be checked.
 *
 * Returns: 1 is the character is a letter or alphabet, 0 otherwise.
*/
int checkAlphaNumeric(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

/*
 * Function that check if the two characters are same (case insensitive).
 *
 * Parameters:
 * a: first character
 * b: second character
 *
 * Returns: 1 if both characters are same(case insensitive), 0 otherwise.
*/
int matchCharacters(char a, char b) {
    if(a >= 'A' && a <= 'Z')
	a += 32;

    if(b >= 'A' && b <= 'Z')
	b += 32;

    return a == b;
}

/*
 * Function that checks if a string is a palindrome or not.
 *
 * Parameters;
 * str: the string to be checked.
 * len: the length of the string.
 *
 * Returns: 1 if the string is a palindrome, 0 otherwise.
*/
int checkPalindrome(char str[], int len) {
    // use two pointers, one from start, one from the end.
    int i = 0, j = len - 1;

    while(i <= j) {

	// check if the i-th character is an alphanumeric character.
	if(!checkAlphaNumeric(str[i])) {
	    i++;
	    continue;
	}	

	// check if the j-th character is an alphanumeric character.
	if(!checkAlphaNumeric(str[j])) {
	    j--;
	    continue;
	}

	// check if both are same(case insensitive).
	if(!matchCharacters(str[i], str[j]))
	    return 0;

	// move the pointers.
	i++, j--;
    }

    return 1;
}

int main() {
    char str[100];

    // scan the string(including spaces)
    scanf("%[^\n]%*c", str);

    // get the length of string.
    int len = strlen(str);

    // get the result of whether the string is a palindrome or not.
    int res = checkPalindrome(str, len);

    // if res is 1, the string is palindrome.
    if(res == 1) {
	printf("true\n");
    } else {
	printf("false\n");
    }
}

