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
	TreeNode *pre;

	void pre_order(TreeNode *node) {
		if (node == NULL) return;

		TreeNode *tmp = node->right;
		if (pre != NULL) {
			pre->right = node;
			pre->left = NULL;
		}
		pre = node;
		pre_order(node->left);
		pre_order(tmp);
	}
	
    void flatten(TreeNode *root) {
        if (root == NULL) return;

		pre = NULL;
		pre_order(root);
    }
};