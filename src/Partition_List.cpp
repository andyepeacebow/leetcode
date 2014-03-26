class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) return NULL;

		ListNode *l1 = new ListNode(0);
		ListNode *l2 = new ListNode(0);

		ListNode *cur = head, *p1 = l1, *p2 = l2;
		while (cur != NULL) {
			if (cur->val < x) {
				p1->next = cur;
				p1 = p1->next;
			} else {
				p2->next = cur;
				p2 = p2->next;
			}
			cur = cur->next;
		}

		p2->next = NULL;

		if (l1->next == NULL) {
			return l2->next;
		} else {
			p1->next = l2->next;
			return l1->next;
		}
    }
};