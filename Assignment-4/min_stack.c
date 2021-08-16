/*
 * Implementation of min stack using C.
 * 
 * Question Link:
 * https://leetcode.com/problems/min-stack/
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Assignment - 4(Stacks and Queues)
*/


// using 2 indicies for each element, [value, min_element till now]
// every even index contain the element, and the very next element is the current min.
typedef struct {
    int stack[60000];
    int pos;
} MinStack;

/** initialize your data structure here. */

int min(int a, int b) {
    return a < b ? a : b;
}

// initialize the stack.
MinStack* minStackCreate() {
    MinStack* st = (MinStack *)malloc(sizeof(MinStack));
    st->pos = 0;
    return st;
}

// push the element to the top with appropriate min value.
void minStackPush(MinStack* obj, int val) {
    int currentMin = min(val, minStackGetMin(obj));
    
    obj->stack[obj->pos++] = val;
    obj->stack[obj->pos++] = currentMin;
}

// pop the element out of stack, decrease the position by 2.
void minStackPop(MinStack* obj) {
    int val = obj->stack[obj->pos - 2];
    obj->pos -= 2;
    
    return val;
}

// return the top element.
int minStackTop(MinStack* obj) {
    return obj->stack[obj->pos - 2];
}

// get the min element.
int minStackGetMin(MinStack* obj) {
    
    if(obj->pos == 0) {
        return INT_MAX;
    }
    
    return obj->stack[obj->pos - 1];
}

// free the memory.
void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/