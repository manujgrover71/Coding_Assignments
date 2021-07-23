/*
 * Program to find count of vowels and consonants in the given string.
 * Compilation: gcc count_vowel_consonants.c
 * Execution: ./a.out
 *
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Date: 23/07/2021
 *
*/

#include <stdio.h>

/*
 * Function that returns whether a character is vowel or not.
*/
int isVowel(char ch) {
    // if character is uppercase, convert it to lowercase.
    if(ch >= 'A' && ch <= 'Z')
        ch += 32;

    // check if the character is either of these: ['a', 'e', 'i', 'o', 'u']
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    char str[100]; // string limit is 100 initially, please set accordingly.

    // take the string with space included.
    scanf("%[^\n]%*c", str);

    int vowels = 0, consonants = 0;

    for(int i = 0; str[i] != '\0'; i++) {
        if(isVowel(str[i])) vowels++;
        else consonants++;
    }

    // print the count of vowels and consonants.
    printf("Vowels = %d, Consonants = %d\n", vowels, consonants);
}
