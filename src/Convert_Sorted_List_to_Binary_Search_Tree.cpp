/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

	TreeNode* build_tree(int tot) {
		queue<TreeNode*> que;
		int cnt = 1;
		TreeNode *root = new TreeNode(cnt);

		que.push(root);
		while (true) {
			if (cnt >= tot) break;
		
			TreeNode *cur = que.front();
			que.pop();

			cnt ++;
			cur->left = new TreeNode(cnt);
			que.push(cur->left);

			if (cnt >= tot) break;

			cnt ++;
			cur->right = new TreeNode(cnt);
			que.push(cur->right);
		}

		return root;
	}

	ListNode *lnode;
	void set_val(TreeNode* tnode) {
		if (tnode == NULL) return;

		set_val(tnode->left);
		tnode->val = lnode->val;
		lnode = lnode->next;
		set_val(tnode->right);
	}

    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) return NULL;

		int len = 0;
		ListNode* cur = head;
		while (cur != NULL) {
			cur = cur->next;
			len ++;
		}

		TreeNode *root = build_tree(len);

		lnode = head;
		set_val(root);

		return root;
    }
};