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
    ListNode *swapPairs(ListNode *head) {
        ListNode *cur = head;
        ListNode *pre = NULL;
        
        while (cur != NULL) {
            ListNode *nxt = cur->next;
            if (nxt == NULL) break;
            
            ListNode *save = nxt;
            cur->next = save->next;
            save->next = cur;
            if (head == cur) {
                head = save;
            }
            if (pre != NULL) {
                pre->next = save;
            }
            pre = cur;
            cur = cur->next;
        }
        
        return head;
    }
};