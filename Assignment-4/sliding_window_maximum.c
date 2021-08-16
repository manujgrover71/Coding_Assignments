/*
 * Program to find the maximum element in every window of size k in array of length n.
 * 
 * Question Link:
 * https://leetcode.com/problems/sliding-window-maximum/
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Assignment - 4(Stacks and Queues)
*/

// queue array.
int *queue;

// max size for queue
int max_size;

// front and back pointer for stack.
int front = -1, back = -1;


// initialize the queue
void initialize_queue(int n) {
    max_size = n;
    queue = (int *) malloc(max_size * sizeof(int));
    front = back = -1;
}

// push the element in queue.
void push_back(int value) {
    
    if((front == 0 && back == max_size - 1) || ((back + 1) % max_size == front)) {
        return;
    }
    
    if(back == -1 || back == max_size - 1) {
        back = 0;
    
        if(front == -1)
            front++;
        
        queue[back] = value;
    }else {
        back++;
        queue[back] = value;
    }
    
}

// pop the element in the front of queue.
int pop_front() {
    
    if(front == -1) {
        // underflow..
        return -1;
    }
    
    int res = queue[front];
    
    if(front == back) {
        front = back = -1;
    } else {
        front++;
        
        if(front == max_size) {
            front = 0;
        }
    }
    
    return res;
}


// pop the element n the back of queue.
int pop_back() {
    
    if(front == -1) {
        // underflow..
        return -1;
    }
    
    int res = queue[back];
    
    if(front == back) {
        front = back = -1;
    } else {
        back--;
        
        if(front > back) {
            back = max_size - 1;
        }
    }
    
    return res;
}

// check if the queue is empty
int is_empty() {
    return front == -1;
}

// get the element in the front without popping it out of queue.
int peekFront() {
    
    if(is_empty()) {
        // queue is empty.
        return -1;
    }
    
    return queue[front];
}

// get the element in the back wihout popping it out of queue.
int peekBack() {
    if(is_empty()) {
        return -1;
    }
    
    return queue[back];
}

// free the queue array memory
void freeQueue() {
    free(queue);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    
    // initialize the queue.
    initialize_queue(k);
    // initialize the answer array.
    int *ans = (int*) malloc((numsSize - k + 1) * sizeof(int));
    
    // keep the queue monotonic with at most k element present in it.
    for(int i = 0; i < numsSize; i++) {
        // remove smaller element from the queue.
        while(!is_empty() && nums[peekBack()] <= nums[i]) {
            pop_back();
        }
        
        // remove elements which are out of the window of length k.
        while(!is_empty() && peekFront() <= i - k) {
            pop_front();
        }
        
        // push current element.
        push_back(i);
        
        // get the answer for current window.
        if(i >= k - 1) {
            ans[i - k + 1] = nums[peekFront()];
        }
    }
    
    // free the queue memory
    freeQueue();
    
    // total size of answer array.
    *returnSize = numsSize - k + 1;
    
    return ans;
}