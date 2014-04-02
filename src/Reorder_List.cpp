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
    void reorderList(ListNode *head) {
        if (head == NULL) return;

		int len = 0;
		ListNode *cur = head;
		while (cur != NULL) {
			len ++;
			cur = cur->next;
		}

		ListNode *hd = new ListNode(0);
		hd->next = head;
		cur = hd->next;
		ListNode *pre = hd, *last;
		int half = (len + 1) / 2, cnt = 0;

		// reverse the latter half
		while (cur != NULL) {
			ListNode *nxt = cur->next;
			if (cnt > half) {
				cur->next = pre;
			}
			if (cnt == half) {
				cur->next = NULL;
				pre->next = NULL;
			}
			if (cnt == len - 1) {
				last = cur;
			}
			pre = cur;
			cur = nxt;
			cnt ++;
		}

		ListNode *a = hd->next, *b = last;
		cur = hd;
		int turn = 0;
		for (int i = 0; i < len; i ++) {
			if (turn == 0) {
				cur->next = a;
				a = a->next;
			} else {
				cur->next = b;
				b = b->next;
			}
			cur = cur->next;
			turn = 1 - turn;
		}
    }
};