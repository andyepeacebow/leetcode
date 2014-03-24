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
	int n;
	vector<int> pre, in;
	
	void dfs(TreeNode *node, int sp, int tp, int sm, int tm) {
		node->val = pre[sp];

		int ln, rn;
		// find the position of pre[sp] in inorder sequence
		for (int i = sm; i <= tm; i ++) {
			if (in[i] == node->val) {
				ln = i - sm;
				break;
			}
		}

		rn = tm - sm - ln;

		if (ln > 0) {
			node->left = new TreeNode(pre[sp + 1]);
			dfs(node->left, sp + 1, sp + ln, sm, sm + ln - 1);
		}
		if (rn > 0) {
			node->right = new TreeNode(pre[sp + 1 + ln]);
			dfs(node->right, sp + 1 + ln, tp, sm + ln + 1, tm);
		}
	}

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		n = preorder.size();
		if (n == 0) return NULL;

		pre = preorder, in = inorder;
        TreeNode *root = new TreeNode(0);
		dfs(root, 0, n - 1, 0, n - 1);
		return root;
    }
};