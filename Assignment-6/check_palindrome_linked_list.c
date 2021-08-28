/*
 * Program to check if the given linked list is a palindrome or not.
 * 
 * Question Link:
 * https://leetcode.com/problems/palindrome-linked-list
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


bool isPalindrome(struct ListNode* head){
    
    // take two pointers, slow and fast.
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    // move the fast pointer double so the slow pointer comes to the middle when fast pointer is null or fast->next is null.
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // now reverse the second half.
    struct ListNode* prev = NULL;
    struct ListNode* next = slow;
    while(slow != NULL) {
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }
    
    // bring the pointer to head and last node of the linked list.
    slow = prev;
    fast = head;
    
    // now just keep compairing the node value.
    while(slow != NULL) {
        // if the value is not same, return false.
        if(slow->val != fast->val) {
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    
    // if we reach the end, return true.
    return true;
}