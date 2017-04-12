//https://leetcode.com/problems/linked-list-cycle
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
    bool hasCycle(ListNode *head) 
    {
        map<ListNode*, bool> mp;
        mp.clear();
        while(head != NULL)
        {
            mp[head] = true;
            if(mp.find(head->next) != mp.end()) return true;
            head = head->next;
        }
        return false;
    }
};
