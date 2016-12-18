//Problem Description: https://leetcode.com/problems/palindrome-linked-list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) 
{
    struct ListNode* cur = head;
    int len = 0, mid;
    while(cur != NULL) len++, cur = cur->next;
    mid = len >> 1;
    
    struct ListNode* current = head;
    struct ListNode* next;
    while (mid--) current = current->next;
    
    if(len&1) current = current->next;
    
    struct ListNode* b   = NULL;
    while (current != NULL)
    {
        next  = current->next;
        current->next = b;
        b = current;
        current = next;
    }
    
    while(b != NULL)
    {
        if(head->val != b->val) return false;
        head = head->next;
        b = b->next;
    }
    
    return true;
}
