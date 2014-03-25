class Solution {
public:
    ListNode *sortList(ListNode *head) {
		if (head == NULL) return NULL;
		int len = 0;
		ListNode *cur = head;
		while (cur != NULL) {
			len ++;
			cur = cur->next;
		}

		ListNode *res = merge_sort(&head, len);
		return res;
    }

	ListNode *merge_sort(ListNode **node, int len) {
		if (len == 1) {
			ListNode *tmp = new ListNode((*node)->val);
			*node = (*node)->next;
			return tmp;
		}

		ListNode *le = merge_sort(node, len >> 1);
		ListNode *ri = merge_sort(node, len - (len >> 1));
		ListNode *res = merge(le, ri);
		return res;
	}

	ListNode *merge(ListNode *le, ListNode *ri) {
		ListNode *hd = new ListNode(0);
		ListNode *cur = hd;
		while (le != NULL && ri != NULL) {
			if (le->val <= ri->val) {
				cur->next = le;
				le = le->next;
			} else {
				cur->next = ri;
				ri = ri->next;
			}
			cur = cur->next;
		}

		while (le != NULL) {
			cur->next = le;
			le = le->next;
			cur = cur->next;
		}
		while (ri != NULL) {
			cur->next = ri;
			ri = ri->next;
			cur = cur->next;
		}
		return hd->next;
	}
};