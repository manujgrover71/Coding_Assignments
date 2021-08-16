/* 
 * Program to check if the given string of parentheses is balanced or not.
 * 
 * Compilation: gcc balanced_parentheses.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Assignment-4(Stacks and Queues)
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// array for stack.
char *stack;
// max size for stack.
int max_size;
// current top position for stack.
int pos;

// function to push character on top of stack.
void push(char ch) {
    if(pos >= max_size) {
        max_size *= 2;   
        stack = (char *) realloc(max_size, sizeof(char));
    }
    stack[pos++] = ch;
}

// check if the stack is empty or not.
int is_empty() {
    return pos == 0;
}

// get the top character of stack.
char peek() {
    
    if(!is_empty()) {
        return stack[pos - 1];
    }
    
    return '#';
}

// pop the top character out of stack.
char pop() {
    
    if(is_empty()) {
        return '#';
    }
    
    return stack[--pos];
}

// initialize the stack.
void initialize_stack(int size) {
    max_size = size;
    stack = (char *)malloc(size * sizeof(char));
    pos = 0;
}

// free stack array memory
void free_stack() {
    free(stack);
}

int balanced_parentheses(char str[], int n) {
    initialize_stack(10);
    
    for(int i = 0; i < n; i++) {
        // if current character is an opening bracket, push to stack.
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            
            push(str[i]);
            
        }else {
            
            // if current character is closing bracket, check the top of stack and compare if
            // both are same type of bracket or not.
            
            if(str[i] == ')' && peek() != '(') {
                return 0;
            }
            
            if(str[i] == '}' && peek() != '{') {
                return 0;
            }
            
            if(str[i] == ']' && peek() != '[') {
                return 0;
            }
            
            // if yes, pop that opening bracket out of stack.
            pop();
        }
    }
    
    // lastly check if the stack is empty.
    int res = is_empty();
    
    // clear stack memory
    free(stack);
    
    // return the answer.
    return res;
}

int main() {
    // string.
    char str[100];
    
    // take the input
    scanf("%s", str);   
    
    // check if the string of parenthesis is balanced or not.
    printf(balanced_parentheses(str, strlen(str)) ? "true" : "false");
}