/*
 * Program to remove duplicate value nodes from a sorted linked list.
 * 
 * Question Link:
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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


struct ListNode* deleteDuplicates(struct ListNode* curr){
    // create a dummy node.
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    // make the dummy node's next point to the head.
    dummy->next = curr;
    
    // create a new node that points to the dummy node.
    struct ListNode* prev = dummy;
    
    // while the head node is not null.
    while(curr != NULL) {
        // if the current element is a duplicate element.
        if(curr->next != NULL && curr->val == curr->next->val) {
            // move the current pointer to the last occurance of the element.
            while(curr->next != NULL && curr->val == curr->next->val) {
                curr = curr->next;
            }
            
            // make the prev node next point to the next element of current node 
            // i.e. the element just next to the duplicate element.
            prev->next = curr->next;
        }else {
            // else just move the prev pointer to the next as prev->next = current.
            prev = prev->next;
        }
        // move the current pointer.
        curr = curr->next;
    }
    
    // return the dummy node's next node.
    return dummy->next;
}