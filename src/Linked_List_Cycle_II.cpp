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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;

		ListNode *hd = new ListNode(0);
		hd->next = head;
		ListNode *slow = head, *fast = head;

		ListNode *meet = NULL;

		while (true) {
			if (fast->next == NULL || fast->next->next == NULL) {
				return NULL;
			}

			fast = fast->next->next;
			slow = slow->next;

			if (fast == slow) {
				meet = fast;
				break;
			}
		}

		fast = meet, slow = head;

		while (fast != slow) {
			fast = fast->next;
			slow = slow->next;
		}

		return fast;
    }
};