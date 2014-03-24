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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
		if (n == 0) return NULL;

		ListNode *hd = new ListNode(0);
		ListNode *cur = hd;
		while (true) {
			bool goon = false;
			int idx = 0, small = 0x6fffffff;
			for (int i = 0; i < n; i ++) {
				if (lists[i] == NULL) continue;
				
				goon = true;
				if (lists[i]->val < small) {
					small = lists[i]->val;
					idx = i;
				}
			}

			if (!goon) break;

			cur->next = lists[idx];
			lists[idx] = lists[idx]->next;
			cur = cur->next;
			cur->next = NULL;
		}

		return hd->next;
    }
};