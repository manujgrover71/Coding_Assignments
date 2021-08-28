/* 
 * Implementation of queue using linked list.
 * 
 * Compilation: gcc queue_linked_list.c
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
    struct Node* next;
};

// two pointers for keeping the track of front and back.
struct Node* front;
struct Node* back;

/*
 * Function to check if the queue is empty or not.
 * 
 * Returns: 1 if queue is empty, 0 if not empty.
*/
int is_empty() {
    return (front == NULL);
}

/*
 * Function to get the front value from the queue without dequeuing it from the queue.
 * 
 * Returns: -1 if the queue is empty else the front value present in the queue.
*/
int peek() {
    if(!is_empty()) {
        return -1;
    }
    
    return front->val;
}

/*
 * Function to add the given value at the front of the queue.
 * 
 * Parameters:
 * num: the value to be added to the front of the queue.
 * 
 * Returns: nothing.
*/
void enqueue(int num) {
    // create a new node.
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    
    // assign the value and make the next point to null.
    temp->val = num;
    temp->next = NULL;
    
    // if the back pointer is null, this means the stack is empty
    // make the back and front pointer current node.
    if(back == NULL) {
        front = temp;
        back = temp;
        return;
    }
    
    back->next = temp;
    back = temp;   
}

/*
 * Function to get the front value from the queue
 * 
 * Returns: -1 if the queue is empty else value present at front of queue.
*/
int dequeue() {
    // check if the queue is empty or not.
    if(is_empty()) {
        return -1;
    }
    
    // get the front value.
    int res = front->val;
    
    // take the front node in new pointer.
    struct Node* temp = front;
    
    // move the front pointer.
    front = front->next;
    
    // if front is null now, it means the queue is empty
    // hence make the back null to.
    if(front == NULL) {
        back = NULL;
    }
    
    // free the memory
    free(temp);
    
    // return the result.
    return res;
}

/*
 * Function to initialise the queue pointers.
 * 
 * Returns: nothing.
*/
void initialize() {
    front = back = NULL;
}

int main() {
    // initialize the queue.
    initialize();
    
    // FOR TESTING PURPOSE
    for(int i = 0; i < 10; i++) {
        enqueue(i + 1);
    }
    
    for(int i = 0; i < 20; i++) {
        printf("%d ", dequeue());
    }
    
    printf("\n");
    
    for(int i = 0; i < 5; i++) {
        enqueue(i + 1);
    }
    
    for(int i = 0; i < 10; i++) {
        printf("%d ", dequeue());
    }
}