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
    ListNode *deleteDuplicates(ListNode *head) {
        
        ListNode *cur = head;
        while (cur != NULL) {
            ListNode *nxt = cur->next;
            
            while (nxt != NULL && nxt->val == cur->val) {
                ListNode *tmp = nxt->next;
                delete nxt;
                nxt = tmp;
            }
            
            cur->next = nxt;
            cur = cur->next;
        }
        
        return head;
    }
};