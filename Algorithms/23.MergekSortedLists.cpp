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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ret = NULL;
        ListNode *result = ret;
        while(true){
            int mn = INT_MAX, pos = -1;
            for(int i = 0; i < lists.size(); i++) {
                mn = lists[i] != NULL && mn > lists[i]->val ? lists[i]->val : mn;
                pos = lists[i] != NULL && mn == lists[i]->val ? i : pos;
            }
            if(pos == -1) break;
            
            if(ret == NULL) {
                ret = new ListNode(lists[pos]->val);
                result = ret;
            }
            else {
                ret->next = new ListNode(lists[pos]->val);
                ret = ret->next;
            }
            
            lists[pos] = lists[pos]->next;
        }
        return result;
    }
};
