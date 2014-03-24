class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL) return NULL;

        ListNode *hd = new ListNode(0);
		hd->next = head;

		ListNode *pre = hd;
		while (pre->next != NULL) {
			ListNode *cur = pre->next;
			int cnt = 0;
			while (cur->next != NULL && cur->val == cur->next->val) {
				cur = cur->next;
				cnt ++;
			}

			if (cnt == 0) {
				pre = cur;
			} else {
				pre->next = cur->next;
			}
		}

		return hd->next;
    }
};