/*
 * Program to convert Infix expression to Postfix expression in C.
 * 
 * Compilation: gcc infix_to_prefix.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Assignment - 4(Stacks and Queues)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// max_size of the array.
int max_size;

// stack array.
char *stack;

// current top position
int position;

/*
 * Function to push elements to the top of stack.
 * 
 * Parameters:
 * value: the element to be added to the top of stack.
 * 
 * Returns: nothing.
*/
void push(char value) {
    if(position >= max_size) {
        // overflow...
        
        // double the stack size.
        max_size *= 2;
        
        // allocate additional memory
        stack = (int*) realloc(stack, max_size * sizeof(int));
    }
    
    // add element to top position
    stack[position++] = value;
}

/*
 * Function to check if the stack is empty or not.
 * 
 * Returns: 1 is stack is empty, 0 otherwise.
*/ 
int is_empty() {
    // if position is 0, the stack is empty
    return position == 0;
}

/*
 * Function that pop the top element from the stack and returns it.
 * 
 * Returns: Top element of the stack, -1 is the stack is empty.
*/
char pop() {
    // check if stack is empty.
    if(is_empty()) {
        // underflow..
        return '#';
    }
    
    // return the top element and decrement the top position.
    return stack[--position];
}

/*
 * Function that return the top element element of stack, without popping it out of the stack.
 *
 * Returns: the top element of the stack, -1 if the stack is empty.
*/
char peek() {
    // check if stack is empty.
    if(is_empty()) {
        // stack is empty.
        return '#';
    }
    
    // return the top element without changing the top position.
    return stack[position - 1];
}

// initialize the stack.
void createStack() {
    max_size = 10;
    position = 0;
    stack = (char *)malloc(max_size * sizeof(char));
}

// free stack memory.
void freeStack() {
    free(stack);
}

// get the precedence of operators.
int priority(char ch) {
    
    if(ch == '^') {
        return 2;  
    } else if(ch == '/' || ch == '*') {
        return 1;
    } else if(ch == '+' || ch == '-') {
        return 0;
    }
    
    return -1;
}

// check if the character is alphanumeric or not.
int checkAlphaNumeric(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

void infix_to_prefix(char str[], int n) {
    
    // initialize the stack.
    createStack();
    
    // resultant string.
    char res[n + 1];

    int j = 0;
    
    for(int i = 0; i < n; i++) {
        // if the character is alphanumeric, add it the result string.
        if(checkAlphaNumeric(str[i])) {
            
            res[j++] = str[i];
            
        }else if(str[i] == '(') {
            // if an opening bracket is encountered, push to stack.
            push('(');
            
        }else if(str[i] == ')') {
            
            while(!is_empty() && peek() != '(') {
                res[j++] = pop();
            }
            
            pop();
            
        }else {
            
            while(!is_empty() && priority(peek()) >= priority(str[i])) {
                res[j++] = pop();
            }
            
            push(str[i]);
        }
    }
    
    while(!is_empty()) {
        res[j++] = pop();
    }
    
    res[j++] =
    
    printf("%s", res);
    
    freeStack();
}

int main() {
    char str[100];
    
    scanf("%s", str);
    
    infix_to_prefix(str, strlen(str));
}