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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        
        ListNode *head;
        if (l2 == NULL || (l1 != NULL && l1->val <= l2->val)) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        
        ListNode *pre = head;
        while (l1 != NULL && l2 != NULL) {
            ListNode *tmp;
            if (l1->val <= l2->val) {
                pre->next = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        
        if (l1 != NULL) {
            pre->next = l1;
        }
        
        if (l2 != NULL) {
            pre->next = l2;
        }
        
        return head;
    }
};