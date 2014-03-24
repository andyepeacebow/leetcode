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
	ListNode *last, *nxt;
	bool dfs(ListNode *pre, ListNode* node, int &cnt, int n) {
		if (cnt >= n) {
			nxt = node->next;
			last = node;
			node->next = pre;
			return true;
		} else {
			if (node->next == NULL) {
				return false;
			}
			else {
				cnt ++;
				bool ret = dfs(node, node->next, cnt, n);
				if (ret) {
					node->next = pre;
				}
				return ret;
			}
		}
	}

    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL) return NULL;
		if (k == 1) return head;

		ListNode *hd = new ListNode(0);
		hd->next = head;
		
		ListNode *pre, *cur;
		pre = hd;

		while (pre != NULL && pre->next != NULL) {
			cur = pre->next;
			int cnt = 1;
			dfs(pre, cur, cnt, k);
			if (cnt >= k) {
				ListNode *tmp = pre->next;
				pre->next->next = nxt;
				pre->next = last;
				pre = tmp;
			} else {
				break;
			}
		}

		return hd->next;
    }
};