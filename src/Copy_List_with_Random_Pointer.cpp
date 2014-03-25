class Solution {
public:
	unordered_map<RandomListNode *, int> node2pos;

    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;

		RandomListNode *hd = new RandomListNode(0), *cur1 = head, *cur2 = hd->next, *pre = hd;
		int pos = 0;
		while (cur1 != NULL) {
			node2pos[cur1] = pos;
			pos ++;
			cur1 = cur1->next;
		}

		cur1 = head;
		vector<RandomListNode*> vec2;
		while (cur1 != NULL) {
			cur2 = new RandomListNode(cur1->label);
			vec2.push_back(cur2);
			pre->next = cur2;
			pre = cur2;
			cur1 = cur1->next;
		}

		cur1 = head, cur2 = hd->next;
		while (cur1 != NULL) {
			if (cur1->random == NULL) {
				cur2->random = NULL;
			} else {
				int pos = node2pos[ cur1->random ];
				cur2->random = vec2[pos];
			}
			cur1 = cur1->next;
			cur2 = cur2->next;
		}

		return hd->next;
    }
};