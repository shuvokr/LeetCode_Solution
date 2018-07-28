// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *head = headA, *ret = NULL;
        int cou1 = 0, cou2 = 0;
        vector<int> a, b;
		while(head)
        {
            a.push_back(head->val);
            head = head->next;
        }
        head = headB;
        while(head)
        {
            b.push_back(head->val);
            head = head->next;
        }
		if(a.empty() || b.empty()) return NULL;
        cou1 = a.size() - 1; cou2 = b.size() - 1;
        while(cou1 > -1 && cou2 > -1 && a[ cou1 ] == b[ cou2 ]) cou1--, cou2--; 
		cou1++; head = NULL;
        while(cou1 < a.size())
        {
            head = new ListNode(a[cou1++]);
        	if(!ret) ret = head;
			head = head->next;
		}
        return ret;
    }
};
