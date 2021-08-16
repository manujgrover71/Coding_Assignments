/*
 * Implementation of stack using queue in C.
 * 
 * Question Link:
 * https://leetcode.com/problems/implement-stack-using-queues/
 * 
 * @author: Manuj Grover, @Roll_number: 1910990170
 * Assignment - 4(Stacks and Queues)
*/

typedef struct {
    int queue[105];
    int max_size;
    int front;
    int back;
} MyStack;

/** Initialize your data structure here. */

// get the number of elements in the queue.
int get_size(MyStack *obj) {
    int tempBack = obj->back;
    if(obj->front > obj->back)
        tempBack += obj->max_size;
    
    return tempBack - obj->front + 1;
}

// add the element to queue.
void enqueue(MyStack *obj, int value) {
    if((obj->front == 0 && obj->back == obj->max_size - 1) || ((obj->back + 1) % obj->max_size == obj->front)) {
        return;
    }
    if(obj->back == -1 || obj->back == obj->max_size - 1) {
        obj->back = 0;
        if(obj->front == -1)
            obj->front++;
        
        obj->queue[obj->back] = value;
    }else {
        obj->back++;
        obj->queue[obj->back] = value;
    }
    
}

// pop the front element from the queue.
int dequeue(MyStack *obj) {
    if(obj->front == -1) {
        return -1;
    }
    int res = obj->queue[obj->front];
    
    if(obj->front == obj->back) {
        obj->front = obj->back = -1;
    } else {
        obj->front++;
        if(obj->front == obj->max_size) {
            obj->front = 0;
        }
    }
    return res;
}

// checks if the queue is empty
int is_empty(MyStack *obj) {
    return obj->front == -1;
}

// checks the front element in the queue.
int peek(MyStack *obj) {
    if(is_empty(obj)) {
        return -1;
    }
    return obj->queue[obj->front];
}

MyStack* myStackCreate() {
    MyStack* st = (MyStack *)malloc(sizeof(MyStack));
    st->max_size = 100;
    st->front = st->back = -1;
    return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    
    enqueue(obj, x);
    
    int sz = get_size(obj);
    
    for(int i = 0; i < sz - 1; i++) {
        enqueue(obj, dequeue(obj));
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    return dequeue(obj);
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return peek(obj);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return is_empty(obj);
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/