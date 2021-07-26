/* 
 * Program to print all input lines that are longer than 80 characters.
 * 
 * Compilation: gcc read_file.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * C Fundamentals
 * Date: 26/07/2021
*/

#include <stdio.h>

/*
 * Function to get string length.
 *
 * Parameters:
 * str = string whose length need to be calculated.
 *
 * Returns: length of the string.
*/
int getLen(char *str) {
    int len = 0;
    
    while(str[len] != '\0') {
        len++;
    }
    
    return len;
}

int main() {
    // string to store filename.
    char filename[100];
    
    // take filename as input
    scanf("%s", filename);
    
    // create filePointer to access file.
    FILE *filePtr;
    
    // try opening the file.
    if((filePtr = fopen(filename, "r")) == NULL) {
        printf("Error in file opening!");
        exit(0);
    }
    
    // string to store each line of file.
    char input[1000];
    
    // keep on taking each line until you reach EOF(end of file).
    while(fscanf(filePtr, "%[^\n]%*c", input) != EOF) {
        // get the length of current line.
        int len = getLen(input);
        
        // if length of current line is greater than 80, print it.
        if(len > 80) {
            printf("%s\n", input);
        }
    }
    
    return 0;
}