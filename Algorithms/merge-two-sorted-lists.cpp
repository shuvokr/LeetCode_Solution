// https://leetcode.com/problems/merge-two-sorted-lists/#/description
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode start(NULL);
        ListNode* ret = &start;
        while(l1 || l2)
        {
            if(l1 && l2)
                if(l1->val < l2->val)
                {
                    ret->next = new ListNode(l1->val);
                    l1 = l1->next;
                    ret = ret->next;
                }
                else
                {
                    ret->next = new ListNode(l2->val);
                    l2 = l2->next;
                    ret = ret->next;
                }
            else if(l1)
            {
                ret->next = new ListNode(l1->val);
                l1 = l1->next;
                ret = ret->next;
            }
            else
            {
                ret->next = new ListNode(l2->val);
                l2 = l2->next;
                ret = ret->next;
            }
        }
        return start.next;
    }
};
