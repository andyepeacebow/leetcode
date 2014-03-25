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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL || l2 == NULL) {
			if (l1 != NULL) return l1;
			else if (l2 != NULL) return l2;
			else return NULL;
		}

		int ca = 0;
		ListNode *hd1 = new ListNode(0);
		ListNode *hd2 = new ListNode(0);
		hd1->next = l1;
		hd2->next = l2;
		
		ListNode *a = hd1, *b = hd2;
		int len1 = 0, len2 = 0;
		while (a->next != NULL || b->next != NULL) {
			int sum = 0;
			int v1 = a->next == NULL ? 0 : a->next->val;
			int v2 = b->next == NULL ? 0 : b->next->val;
			sum = v1 + v2 + ca;
			ca = sum / 10;
			sum %= 10;
			if (a->next != NULL) {
				a->next->val = sum;
				a = a->next;
				len1 ++;
			}
			if (b->next != NULL) {
				b->next->val = sum;
				b = b->next;
				len2 ++;
			}
		}

		if (len1 >= len2) {
			if (ca > 0) {
				a->next = new ListNode(ca);
			}
			return hd1->next;
		} else {
			if (ca > 0) {
				b->next = new ListNode(ca);
			}
			return hd2->next;
		}
		
    }
};