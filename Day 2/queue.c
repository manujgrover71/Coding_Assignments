/*
 * Implementation of queue in C.
 * 
 * Compilation: gcc queue.c
 * Execution: ./a.out
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Date: 05/07/2021
*/

#include <stdio.h>

// queue array.
int *queue;

// max size of queue.
int max_size;

// front and back point for queue.
int front = -1, back = -1;

/*
 * Function to enqueue elements to the queue.
 * 
 * Parameters:
 * value: the value to be enqueued.
 * 
 * Returns: nothing.
*/ 
void enqueue(int value) {
    
    // check for overflow.
    if((front == 0 && back == max_size - 1) || ((back + 1) % max_size == front)) {
        // overflow..
        return;
    }
    
    // if back == -1, then the queue is empty.
    // if back == max_size - 1, then the back pointer is at last of the array.
    if(back == -1 || back == max_size - 1) {
        // bring it to the front.
        back = 0;
        
        // if queue was empty, initiliaze it.
        if(front == -1)
            front++;
        
        // add element to queue.
        queue[back] = value;
    }else {
        // else just add element to the queue.
        back++;
        queue[back] = value;
    }
    
}

/*
 * Functiont to dequeue element from the queue.
 * 
 * Returns: -1 if there is underflow, else the element at the front position of queue.
*/
int dequeue() {
    
    // check for underflow.
    if(front == -1) {
        // underflow..
        return -1;
    }
    
    // get the front element.
    int res = queue[front];
    
    // if queue has only one element.
    if(front == back) {
        // reset it.
        front = back = -1;
    } else {
        // else just move the front pointer.
        front++;
        
        // if the front pointer is at max_size, bring to 0.
        if(front == max_size) {
            front = 0;
        }
    }
    
    // return the front element.
    return res;
}

/*
 * Function to check if the queue is empty or not.
 * 
 * Returns: 1 if queue is empty, 0 otherwise.
*/
int is_empty() {
    return front == -1;
}

/*
 * Function to get the front element from queue without dequeuing it.
 * 
 * Returns: the front element of queue, -1 if queue was empty.
*/ 
int peek() {
    
    if(is_empty()) {
        // queue is empty.
        return -1;
    }
    
    return queue[front];
}

int main() {
    // max size of queue.
    max_size = 10;
    
    // initialize queue.
    queue = (int*) malloc(max_size * sizeof(int));
    
    
    // FOR TESTING PURPOSE.
    for(int i = 0;  i < 20; i++) {
        if(i & 1) {
            // dequeue every 2nd element.
            dequeue();
        }
        
        enqueue(i + 1);
    }
    
    while(!is_empty()) {
        printf("%d ", dequeue());
    }
    
    // free the queue array memory.
    free(queue);
}