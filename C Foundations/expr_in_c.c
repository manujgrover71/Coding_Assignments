/*
 * Program to evaluate a given reverse polish expression in C.
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
 * Function to evaluate reverse polish expression.
 *
 * Parameters:
 * input: string in reverse polish notation to be evaluated.
 * 
 * Returns: the result of expression.
*/
int expr(char *input) {
    // operator stack.
    char op[100];
    
    // num stack.
    int nums[100];
    
    // operator stack counter, num stack counter.
    int opIndex = 0, numIndex = 0;
    
    // for taking current num.
    int currNum = 0;
    
    // flag variable to see if a number is encountered.
    int numFound = 0;
    
    for(int i = 0; input[i] != '\0'; i++) {
        // skip space and add number of num stack.
        if(input[i] == ' ') {
            if(numFound) {
                nums[numIndex++] = currNum;
                numFound = 0;
                currNum = 0;
            }
            continue;
        }
        
        // if there are 2 or more numbers present in num stack and an operator is also present.
        if(opIndex && numIndex >= 2) {
            int second = nums[--numIndex];
            int first = nums[--numIndex];
            
            char operation = op[--opIndex];
            
            switch(operation) {
                case '+': nums[numIndex++] = first + second;
                    break;
                case '-': nums[numIndex++] = first - second;
                    break;
                case '*': nums[numIndex++] = first * second;
                    break;
                case '/': nums[numIndex++] = first / second;
            }
        }
        
        // create num.
        if(input[i] >= '0' && input[i] <= '9') {
            numFound = 1;
            currNum = currNum * 10 + (input[i] - '0');
        } else {
            // add operator to operator stack.
            numFound = 0;
            op[opIndex++] = input[i];
        }
    }
    
    // at last just evaluate any remaining nums and operators.
    while(opIndex && numIndex >= 2) {
        int second = nums[--numIndex];
        int first = nums[--numIndex];
        
        char operation = op[--opIndex];
        
        switch(operation) {
            case '+': nums[numIndex++] = first + second;
                break;
            case '-': nums[numIndex++] = first - second;
                break;
            case '*': nums[numIndex++] = first * second;
                break;
            case '/': nums[numIndex++] = first / second;
        }
    }
    
    return nums[0];
}

int main() {
    // input string.
    char input[100];
    
    // take input from user.
    scanf("%[^\n]%*c", input);
    
    // at last the answer is the last stack element.
    printf("%d\n", expr(input));
    
    return 0;
}