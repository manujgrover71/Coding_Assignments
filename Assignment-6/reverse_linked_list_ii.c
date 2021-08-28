/*
 * Program to reverse a portion of linked list from position left to right.
 * 
 * Question Link:
 * https://leetcode.com/problems/reverse-linked-list-ii/
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


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    // create a dummy node.
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    // create another node that will move till the left position
    struct ListNode* currLeft = dummy;
    
    // create another node that will be just 1 step behind the node.
    struct ListNode* prevLeft = NULL;
    
    // make the dummy node's next point to the head.
    dummy->next = head;
    
    // move the currLeft node till the left position, also make sure that the prevLeft node is just one step behind.
    for(int i = 0; i < left; i++) {
        prevLeft = currLeft;
        currLeft = currLeft->next;
    }
    
    // create a new node currRight that will start from currLeft and will move till the right position.
    struct ListNode* currRight = currLeft;
    
    // create another node prevRight, that will be just 1 step behind the currRight node.
    struct ListNode* prevRight = prevRight;
    
    // take an extra node to help in reversing the left to right position part of linkedlist.
    struct ListNode* next = currRight;
    
    // move from left to right and keep on reversing the nodes.
    for(int i = left; i <= right; i++) {
        next = currRight->next;
        currRight->next = prevRight;
        prevRight = currRight;
        currRight = next;
    }
    
    // now the part from left to right position is reversed and our
    // prevLeft is standing at left - 1 position
    // prevRight is standing at right - 1 position
    // currLeft is standing at left position
    // currRight is standing at right position
    
    // now just make the prevLeft next point to prevRight
    // and currLeft next point to currRight.
    prevLeft->next = prevRight;
    currLeft->next = currRight;
    
    // return the dummy node's next node.
    return dummy->next;
}