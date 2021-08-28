/* 
 * Implementation of deque using linked list.
 * 
 * Compilation: gcc deque_linked_list.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Assignment - 6(Linked List)
*/ 
#include <stdio.h>
#include <stdlib.h>

// Node of linked list containing the value and pointer to the next node and previous node.
struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};

// two pointers for keeping the track of front and back.
struct Node* front;
struct Node* back;

/*
 * Function to initialise the deque pointers.
 * 
 * Returns: nothing.
*/
void initialize() {
    front = back = NULL;
}

/*
 * Function to check if the deque is empty or not.
 * 
 * Returns: 1 if deque is empty, 0 if not empty.
*/
int is_empty() {
    return (back == NULL);
}

/*
 * Function to add the given value at the back of the deque.
 * 
 * Parameters:
 * num: the value to be added to the back of the deque.
 * 
 * Returns: nothing.
*/
void push_back(int num) {
    
    // if back is null, meaning the deque is empty
    if(back == NULL) {
        // create a new node.
        back = (struct Node*)malloc(sizeof(struct Node));
        
        // give it the value.
        back->val = num;
        
        // make the next and prev pointer to point at null.
        back->next = NULL;
        back->prev = NULL;
        
        // make the fron pointer the back one.
        front = back;
        return;
    }
    
    // else make a new node.
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    
    // give it the value.
    temp->val = num;
    
    // make the next pointer point to null.
    temp->next = NULL;
    
    // make the previous pointer point to back pointer.
    temp->prev = back;
    
    // make the current back's next pointer point to current node.
    back->next = temp;
    
    // make the current node the new back.
    back = temp;
}

/*
 * Function to add the given value at the front of the deque.
 * 
 * Parameters:
 * num: the value to be added to the front of the deque.
 * 
 * Returns: nothing.
*/
void push_front(int num) {
    
    // if back is null, meaning the deque is empty
    if(back == NULL) {
        // create a new node.
        back = (struct Node*)malloc(sizeof(struct Node));
        
        // give it the value.
        back->val = num;
        
        // make the next and prev pointer to point at null.
        back->next = NULL;
        back->prev = NULL;
        
        // make the fron pointer the back one.
        front = back;
        return;
    }
    
    // else make a new node.
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    
    // give it the value.
    temp->val = num;
    
    // make the next pointer point to null.
    temp->next = NULL;
    
    // make the previous pointer point to back pointer.
    temp->prev = back;
    
    // make the current front's prev pointer point to current node.
    front->prev = temp;
    
    // make the current node the new front.
    front = temp;
}

/*
 * Function to deque the value present at the back of the deque.
 * 
 * Returns: -1 if the deque is empty else the value present at back of the deque.
*/
int pop_back() {
    
    // if the deque is empty.
    if(is_empty()) {
        return -1;
    }
    
    // get the value present at the back of the deque.
    int res = back->val;
    
    // get the back pointer in new temp pointer.
    struct Node* temp = back;
    
    // move the back pointer.
    back = back->prev;
    
    // if the back is now null, meaning the deque is empty, reset the front node.
    if(back == NULL) {
        front = NULL;
    }else {
        // else make the back pointer's next node to null.
        back->next = NULL;
    }
    
    // make the temp pointer's next and prev to point at null.
    temp->next = NULL;
    temp->prev = NULL;
    
    // free the memory.
    free(temp);
    
    // return the value.
    return res;
}

/*
 * Function to deque the value present at the front of the deque.
 * 
 * Returns: -1 if the deque is empty else the value present at front of the deque.
*/
int pop_front() {
    if(is_empty()) {
        return -1;
    }
    
    // get the value present at the front of the deque.
    int res = front->val;
    
    // get the front pointer in new temp pointer.
    struct Node* temp = front;
    
    // move the front pointer.
    front = front->next;
    
    // if the front is now null, meaning the deque is empty, reset the back node.
    if(front == NULL) {
        back = NULL;
    }else {
        // else make the front pointer's prev node to null.
        front->prev = NULL;
    }
    
    // make the temp pointer's next and prev to point at null.
    temp->next = NULL;
    temp->prev = NULL;
    
    // free the memory.
    free(temp);
    
    // return the value.
    return res;
}

/*
 * Function to get the front value from the deque without dequeuing it from the deque.
 * 
 * Returns: -1 if the deque is empty else the front value present in the deque.
*/
int peek_front() {
    if(is_empty()) {
        return -1;
    }
    
    return front->val;
}

/*
 * Function to get the back value from the deque without dequeuing it from the deque.
 * 
 * Returns: -1 if the deque is empty else the back value present in the deque.
*/
int peek_back() {
    if(is_empty()) {
        return -1;
    }
    
    return back->val;
}

/*
 * Function to check if a particular value is present in the deque or not.
 * 
 * Parameters:
 * num: the value to be checked.
 * 
 * Returns: 1 if the value is present, 0 otherwise.
*/
int check_element(int num) {
    struct Node* temp = front;
    
    while(temp != NULL) {
        if(temp->val == num) {
            return 1;
        }
        temp = temp->next;
    }
    
    return 0;
}

int main() {
    
    // initialize the deque
    initialize();
    
    // FOR TESTING PURPOSE
    for(int i = 0; i < 10; i++) {
        push_back(i + 1);
        push_front((i + 1) * 10);
    }
    
    for(int i = 0; i < 10; i++) {
        printf("%d ", check_element(i + 1));
        printf("%d ", check_element((i + 1) * 10));
    }
    
    while(!is_empty()) {
        printf("%d ", pop_back());
        printf("%d ", pop_front());
    }
    
}