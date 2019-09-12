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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *tree = head;
        vector<int> v;
        while(tree != NULL) {
            v.push_back(tree->val);
            tree = tree->next;
        }
        tree = head;
        for(int i = 0; i < m - 1; i++) {
            tree->val = v[i];
            tree = tree->next;
        }
        for(int i = n - 1; i > m - 2; i--) {
            tree->val = v[i];
            tree = tree->next;
        }
        for(int i = n; i < v.size(); i++) {
            tree->val = v[i];
            tree = tree->next;
        }
        v.clear();
        return head;
    }
};
