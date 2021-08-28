/*
 * Program to rotate a linked list k times.
 * 
 * Question Link:
 * https://leetcode.com/problems/rotate-list/
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


struct ListNode* rotateRight(struct ListNode* head, int k){
    // if k is 0 or head is null.
    if(!k || head == NULL) return head;
    
    int count = 0;
    struct ListNode* temp = head;
    
    // get the length of list.
    while(temp) {
        count++;
        temp = temp->next;
    }
    
    // take the k modulo length of list as we rotate the list length time, then we will obtain the original list.
    k %= count;
    
    // if new k is 0, return head.
    if(k == 0) {
        return head;
    }
    
    // take a new pointer to the head node.
    struct ListNode* curr = head;
    
    // move it the kthe last position.
    for(int i = 1; i < (count - k); i++) {
        curr = curr->next;
    }
    
    // take a new node and move it till the end.
    temp = curr;
    
    // take a new node which point to the just th next of current node.
    struct ListNode *res = curr->next;
    
    // move the current node till the last.
    while(curr->next != NULL) {
        curr = curr->next;
    }
    
    // make the last node point to the head.
    curr->next = head;
    
    // move the temp node point to null.
    temp->next = NULL;
    
    // return the new head.
    return res;
}