class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return NULL;
		int len = 0;
		ListNode *cur = head;
		while (cur != NULL) {
			len ++;
			cur = cur->next;
		}

		k %= len;
		if (k == 0) return head;

		// find last k nodes
		ListNode *hd = new ListNode(0), *pre = hd, *sa;
		hd->next = head;
		cur = hd;
		int cnt = 0;
		while (cur->next != NULL) {
			cur = cur->next;
			cnt ++;
			if (cnt >= k) {
				if (cur->next == NULL) {
					sa = pre;
				}
				pre = pre->next;
			}
		}
		
		cur->next = hd->next;
		sa->next = NULL;

		return pre;
    }
};