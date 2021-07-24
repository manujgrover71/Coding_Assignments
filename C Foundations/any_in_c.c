/*
 * Program to find the first location in first string of any character present in second string.
 *
 * Compilation: gcc any_in_c.c
 * Execution: ./a.out
 *
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Date: 24/07/2021
 *
*/

#include <stdio.h>

/*
 * Function that returns the first location in first string of any character present in second stirng.
 *
 * Parameters:
 * *s1 = first string
 * *s2 = second string
 *
 * Returns: The index if any character is found, -1 otherwise.
*/
int any(char *s1, char *s2) {
    
    int vis[256] = {0};

    for(int i = 0; s2[i] != '\0'; i++) {
        vis[s2[i]] = 1;
    }

    for(int i = 0; s1[i] != '\0'; i++) {
        if(vis[s1[i]])
            return i;
    }

    return -1;
}

int main() {
    char s1[100], s2[100];
    // input the string.
    scanf("%s %s", s1, s2);

    // print the location.
    printf("%d\n", any(s1, s2));
}
