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
    ListNode *reverseBetween(ListNode *head, int m, int n) {

		ListNode *he = new ListNode(0);
		he->next = head;
		
		int cnt = 0;
		ListNode *cur = he;
		ListNode *he1, *pre = he, *sa, *last;
		while (cnt <= n) {
			if (cnt + 1 == m) {
				he1 = cur;
			}
			if (cnt == m) {
				sa = cur;
			}

			ListNode *nxt = cur->next;
			if (cnt >= m) {
				cur->next = pre;
			}
			pre = cur;

			last = nxt;
			if (cnt < n) {
				cur = nxt;
			}
			
			cnt ++;
		}
		sa->next = last;
		he1->next = cur;
		return he->next;
    }
};