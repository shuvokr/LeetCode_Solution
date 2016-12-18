//Problem Description: https://leetcode.com/problems/reverse-linked-list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) 
{
    struct ListNode* current = head;
    struct ListNode* next;
    struct ListNode* b = NULL;
    while (current != NULL)
    {
        next  = current->next;
        current->next = b;
        b = current;
        current = next;
    }
    return b;
}
