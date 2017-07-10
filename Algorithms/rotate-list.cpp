// https://leetcode.com/problems/rotate-list/#/description
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == NULL || k == 0) return head;
        ListNode *root = head;
        int len = 1;
        while(root->next != NULL) len++, root = root->next;
        k %= len;
        if(k == 0) return head;
        ListNode *last = head;
        int p = len - k - 1;
        
        while(p--)  last = last->next;
        
        ListNode *ret = last->next;
        last->next = NULL;
        root->next = head;
        
        return ret;
    }
};
