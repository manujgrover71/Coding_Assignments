/* 
 * Implementation of stack using linked list.
 * 
 * Compilation: gcc stack_linked_list.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Assignment - 6(Linked List)
*/ 

#include <stdio.h>
#include <stdlib.h>

// Node of linked list containing the value and pointer to the next node.
struct Node {
    int val;
    struct Node *next;
};

// head node pointer
struct Node* stack;

/*
 * Function to initialise the stack.
 * 
 * Returns: nothing.
*/
void initialize() {
    stack = NULL;
}

/*
 * Function to check if the stack is empty or not.
 * 
 * Returns: 1 if stack is empty, 0 if not empty.
*/
int is_empty() {
    return (stack == NULL);
}

/*
 * Function to get the top value from the stack without popping it from the stack.
 * 
 * Returns: -1 if the stack is empty else the top value present at stack.
*/
int peek() {
    if(!is_empty()) {
        return stack->val;
    }
    
    return -1;
}

/*
 * Function to push the given value at top of the stack.
 * 
 * Parameters:
 * num: the value to be pushed at the top of stack.
 * 
 * Returns: nothing.
*/
void push(int num) {
    // create a new node.
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    
    // give it the value
    node->val = num;
    
    // point the next pointer to the stack.
    node->next = stack;
    
    // move the stack pointer to this node.
    stack = node;
}

/*
 * Function to pop the top value of the stack.
 * 
 * Returns: -1 if the stack is empty else value present at top of stack.
*/
int pop() {
    if(is_empty()) {
        return -1;
    }
    
    // get the address in new node pointer.
    struct Node* temp = stack;
    
    // get the value
    int num = stack->val;
    
    // move the head pointer to next position.
    stack = stack->next;
    
    // free the memory
    free(temp);
    
    // return the value.
    return num;
}

int main() {
    // initialize the stack.
    initialize();
    
    
    // FOR TESTING PURPOSE
    for(int i = 0; i < 10; i++) {
        push(i + 1);
    }
    
    while(!is_empty()) {
        printf("%d", pop());
    }
}