// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *root = head;
        int len = 0;
        while(root != NULL) {
            len++, root = root->next;
        }
        n = len - n;
        root = head;
        ListNode *previousNode = new ListNode(NULL);
        if(!n) return head->next;
        while(n > 0) {
            previousNode = root;
            root = root->next;
            n--;
        }
        previousNode->next = root->next;
        delete(root);
        return head;
    }
};
