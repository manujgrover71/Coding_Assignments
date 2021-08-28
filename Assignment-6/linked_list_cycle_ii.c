/*
 * Program to find the node where the cycle of linked list start.
 * 
 * Question Link:
 * https://leetcode.com/problems/linked-list-cycle-ii/
 * 
 * @author: Manuj Grover, @Roll_Number: 1910990170
 * Assignment - 6(Linked List)
* /


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *detectCycle(struct ListNode *head) {
    
    // take two node slow and fast.
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    // move fast pointer two times.
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        // if we get the same node on both slow and fast pointers, we found the cycle.
        if(slow == fast) {
            
            // now just move the head and slow at the same time, when both are same
            // that node will be the starting of cycle.
            while(slow != head) {
                slow = slow->next;
                head = head->next;
            }
            
            return slow;
        }
    }
    
    return NULL;
}