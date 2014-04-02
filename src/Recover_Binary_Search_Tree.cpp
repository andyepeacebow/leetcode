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
	TreeNode *first, *second, *last;

	void dfs(TreeNode *cur) {
		if (cur == nullptr) return;

		dfs(cur->left);
		if (last != nullptr && last->val > cur->val) {
			if (first == nullptr) {
				first = last;
				second = cur;
			} else {
				second = cur;
			}
		}
		last = cur;
		dfs(cur->right);
	}

    void recoverTree(TreeNode *root) {
        if (root == nullptr) return;
		else if (root->left == nullptr && root->right == nullptr) return; // less than 2 two nodes

		last = first = second = nullptr;
		dfs(root);
		swap(first->val, second->val);
    }
};