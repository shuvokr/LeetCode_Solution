//Problem Description: https://leetcode.com/problems/remove-linked-list-elements
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ret = (struct ListNode*) malloc(sizeof(struct ListNode)), *s = NULL;
        int flag = 1;
        while(head != NULL)
        {
            if(head->val != val)
            {
                if(flag) 
                {
                    ret->val = head->val;
                    ret->next = NULL;
                    s = ret;
                    flag = 0;
                }
                else
                {
                    ListNode* tmp = (struct ListNode*) malloc(sizeof(struct ListNode));
                    tmp->val = head->val;
                    tmp->next = NULL;
                    ret->next = tmp;
                    ret = ret->next;
                }
            }
            head = head->next;
        }
        return s;
    }
};
