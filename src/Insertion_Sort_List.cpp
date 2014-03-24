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

	void insert(ListNode *srt, ListNode *cur) {
		ListNode *pre = srt;
		while (pre->next != NULL && pre->next->val < cur->val) {
			pre = pre->next;
		}
		cur->next = pre->next;
		pre->next = cur;
	}

    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) return NULL;

		ListNode *hd = new ListNode(0);

		ListNode *cur = head;
		while (cur != NULL) {
			ListNode *nxt = cur->next;
			insert(hd, cur);
			cur = nxt;
		}

		return hd->next;
    }
};