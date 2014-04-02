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
	int ans;

	int dfs(TreeNode *node) {
		if (node == nullptr) return 0;
		
		int le = dfs(node->left);
		int ri = dfs(node->right);
		int v = node->val;
		int whole = v + le + ri;
		int once = max(v, max(v + le, v + ri));
		ans = max(ans, max(whole, once));
		return once;
	}

    int maxPathSum(TreeNode *root) {
		ans = std::numeric_limits<int>::min();
		dfs(root);
		return ans;
    }
};