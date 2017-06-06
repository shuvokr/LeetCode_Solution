// https://leetcode.com/problems/add-two-numbers/#/description
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode start(NULL);
        ListNode* ret = &start;
        int carry = 0;
        while(l1 || l2)
        {
            if(l1 && l2)
            {
                int val = l1->val + l2->val + carry;
                carry = val / 10;
                val %= 10;
                ret->next = new ListNode(val);
                ret = ret->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1)
            {
                int val = l1->val + carry;
                carry = val / 10;
                val %= 10;
                ret->next = new ListNode(val);
                ret = ret->next;
                l1 = l1->next;
            }
            else if(l2)
            {
                int val = l2->val + carry;
                carry = val / 10;
                val %= 10;
                ret->next = new ListNode(val);
                ret = ret->next;
                l2 = l2->next;
            }
        }
        if(carry) ret->next = new ListNode(carry);
        return start.next;
    }
};
