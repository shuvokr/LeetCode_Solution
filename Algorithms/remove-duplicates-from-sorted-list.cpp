//Problem Description: https://leetcode.com/problems/remove-duplicates-from-sorted-list
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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* ret = (ListNode*)malloc(sizeof(struct ListNode)), *s = NULL;
        int last = -111111111, f = 1;
        while(head != NULL)
        {
            if(head->val == last)
            {
                head = head->next;
                continue;
            }
            last = head->val;
            if(f)
            {
                ret->val = last;
                ret->next = NULL;
                s = ret;
                f = 0;
            }
            else
            {
                ListNode* tmp = (ListNode*)malloc(sizeof(struct ListNode));
                tmp->val = last;
                tmp->next = NULL;
                ret->next = tmp;
                ret = ret->next;
            }
            head = head->next;
        }
        return s;
    }
};
