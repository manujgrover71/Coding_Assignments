/*
 * Program to merge two sorted linked list into a linked list.
 * 
 * Question Link:
 * https://leetcode.com/problems/merge-two-sorted-lists/
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


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
    // create a dummy node.
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    // create another node that point to the dummy node.
    struct ListNode *curr = dummy;
    dummy->next = NULL;
    
    // till both the lists have some nodes.
    while(l1 != NULL && l2 != NULL) {
        // check if first list node value is smaller than second list node value.
        if(l1->val <= l2->val) {
            // make the current node next point to list one's node
            curr->next = l1;
            
            // move the first list node.
            l1 = l1->next;
        }else {
            // make the current node next point to list two's node.
            curr->next = l2;
            
            // move the second list node.
            l2 = l2->next;
        }
        
        // move the current node to next.
        curr = curr->next;
    }
    
    // if the first list is not empty, make the current node next point to that.
    if(l1 != NULL) {
        curr->next = l1;
    }
    
    // if the second list is not empty, make the current node next point to that.
    if(l2 != NULL) {
        curr->next = l2;
    }
    
    // return the dummy node's next node.
    return dummy->next;
}