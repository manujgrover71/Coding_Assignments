/*
 * Program to remove nth node from the last of a linked list.
 * 
 * Question Link:
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    // create a dummy node.
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    // take two node that point to the dummy node.
    struct ListNode* curr = dummy;
    struct ListNode* ref = dummy;
    
    // make the dummy node's next point to the head.
    dummy->next = head;

    // move first node n times.
    for(int i = 0; i <= n; i++) {
        curr = curr->next;
    }
    
    // now we know that the first node is at len_of_linked_list - n + 1 distance.
    // if we move the first node to the null position, we move the second node at the same time.
    // at the last the second node will be at the n + 1 distance from the last.
    while(curr != NULL) {
        curr = curr->next;
        ref = ref->next;
    }

    // hence just make the n + 1 node point to the n - 1 node from the last.
    ref->next = ref->next->next;
    
    // at the end return the dummy node's next pointer.
    return dummy->next;
}