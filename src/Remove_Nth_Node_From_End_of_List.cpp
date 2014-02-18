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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (n <= 0 || head == NULL) return head;
        
        ListNode *he = new ListNode(0);
        he->next = head;
        
        ListNode *fast, *slow;
        fast = slow = he;
        
        int dist = 0;
        while (fast->next != NULL && dist < n) {
            fast = fast->next;
            dist ++;
        }
        
        if (dist < n) return head; // list length is smaller than n
        
        while (fast->next != NULL) { // move together
            fast = fast->next;
            slow = slow->next;
        }
        
        if (slow->next == head) {
            head = head->next;
        } else {
            slow->next = slow->next->next;
        }
        
        return head;
    }
};