/*
 * Implementation of stack functions in C.
 * 
 * Compilation: gcc stack.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Date: 03/08/2021
*/
#include <stdio.h>
#include <stdlib.h>

// max_size of the array.
int max_size = 0;

// stack array.
int *stack;

// current top position
int position = 0;

/*
 * Function to push elements to the top of stack.
 * 
 * Parameters:
 * value: the element to be added to the top of stack.
 * 
 * Returns: nothing.
*/
void push(int value) {
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
int pop() {
    // check if stack is empty.
    if(is_empty()) {
        // underflow..
        return -1;
    }
    
    // return the top element and decrement the top position.
    return stack[--position];
}

/*
 * Function that return the top element element of stack, without popping it out of the stack.
 *
 * Returns: the top element of the stack, -1 if the stack is empty.
*/
int peek() {
    // check if stack is empty.
    if(is_empty()) {
        // stack is empty.
        return -1;
    }
    
    // return the top element without changing the top position.
    return stack[position - 1];
}


int main() {
    
    // initial size.
    max_size = 10;
    // allocate the memory
    stack = (int*) malloc(max_size * sizeof(int));
    
    // FOR TESTING PURPOSE
    // add elements, more the initial size to make the stack size increase when necessary.
    for(int i = 0; i < 20; i++) {
        push(i);
    }
    
    // print the elements.
    while(!is_empty()) {
        printf("%d ", pop());
    }
    
    // de-allocate the memory of array used for stack.
    free(stack);
}