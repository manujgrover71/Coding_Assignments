/*
 * Program to find the largest rectangle in the histogram.
 *
 * Question Link:
 * https://leetcode.com/problems/largest-rectangle-in-histogram/
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Assignment - 4(Stacks and Queues).
 */

// max size for stack.
int max_size = 0;
// stack array.
int *stack;
int position = 0;

// initialize the stack.
void createStack() {
    max_size = 10;
    position = 0;
    stack = (int *)malloc(max_size * sizeof(int));
}

// push the element on top of stack.
void push(int value) {
    if(position >= max_size) {
        max_size *= 2;
        stack = (int*) realloc(stack, max_size * sizeof(int));
    }
    stack[position++] = value;
}

// check if stack is empty or not.
int is_empty() {
    return position == 0;
}

// pop the top element from the stack.
int pop() {
    if(is_empty()) {
        return -1;
    }
    return stack[--position];
}

// get the top element from the stack.
int peek() {
    if(is_empty()) {
        return -1;
    }
    return stack[position - 1];
}

// free the used memory.
void freeStack() {
    free(stack);
}

int max(int a, int b) {
    return a > b ? a : b;
}

int largestRectangleArea(int* heights, int heightsSize){
    
    // left smaller and right smaller.
    int left[heightsSize], right[heightsSize];
    
    // create stack.
    createStack();
    
    // find the left smaller index for each i-th element.
    for(int i = 0; i < heightsSize; i++) {
        while(!is_empty() && heights[peek()] >= heights[i]) {
            pop();
        }
        
        if(is_empty()) {
            left[i] = -1;
        }else {
            left[i] = peek();
        }
        
        push(i);
    }
    
    // free the stack memory.
    freeStack();
    // create another stack.
    createStack();
    
    // find the right smaller index for each i-th element.
    for(int i = heightsSize - 1; i >= 0; i--) {
        while(!is_empty() && heights[peek()] >= heights[i]) {
            pop();
        }
        
        if(is_empty()) {
            right[i] = heightsSize;
        }else 
            right[i] = peek();
        
        push(i);
    }
    
    int ans = 0;
    
    // find the answer for each i-th tower.
    for(int i = 0; i < heightsSize; i++) {
        ans = max(ans, heights[i] * (right[i] - left[i] - 1));
    }
    
    // return the answer.
    return ans;
}