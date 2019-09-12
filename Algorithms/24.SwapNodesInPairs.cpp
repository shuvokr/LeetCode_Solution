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
    ListNode* swapPairs(ListNode* head) {
        ListNode *tree = head;
        while(tree != NULL) {
            if(tree-> next == NULL) break;
            swap(tree->val, tree->next->val);
            tree = tree->next;
            tree = tree->next;
        }
        return head;
    }
};
