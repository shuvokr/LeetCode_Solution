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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode *rev = NULL, *notRev = NULL, *ret = NULL;
        int cou = 0;
        while(head != NULL) {
            if(cou == 0) {
                rev = new ListNode(head->val);
                notRev = new ListNode(head->val);
            }
            else {
                ListNode *temp = new ListNode(head->val);
                temp->next = rev;
                rev = temp;
                
                temp = new ListNode(head->val);
                ListNode *cur = notRev;
                while(cur->next != NULL) cur = cur->next;
                cur->next = temp;
            }
            cou++;
            head = head->next;
            if(cou == k) {
                cou = 0;
                if(ret == NULL) {
                    ret = rev;
                }
                else {
                    ListNode *cur = ret;
                    while(cur->next != NULL) cur = cur->next;
                    cur->next = rev;
                }
            }
        }
        if(cou && cou != k) {
            if(ret == NULL) {
                    ret = notRev;
                }
                else {
                    ListNode *cur = ret;
                    while(cur->next != NULL) cur = cur->next;
                    cur->next = notRev;
                }
        }
        return ret;
    }
};
