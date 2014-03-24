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
	vector<int> vec;

	void dfs(TreeNode *node) {
		if (node == NULL) return;

		dfs(node->left);
		vec.push_back(node->val);
		dfs(node->right);
	}

    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;

		dfs(root);
		int pre = vec[0];
		for (int i = 1; i < vec.size(); i ++) {
			if (pre >= vec[i]) {
				return false;
			}
			pre = vec[i];
		}
		return true;
    }
};
