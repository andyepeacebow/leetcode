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
	vector<TreeNode *> generateTrees(int n) {
		return dfs(1, n);
	}
	vector<TreeNode *> dfs(int s, int t) {
		if (s > t) {
			vector<TreeNode *> ans(1, nullptr);
			return ans;
		}

		vector<TreeNode*> ans;
		for (int i = s; i <= t; i ++) {
			vector<TreeNode*> le = dfs(s, i - 1);
			vector<TreeNode*> ri = dfs(i + 1, t);

			for (int j = 0; j < le.size(); j ++) {
				for (int k = 0; k < ri.size(); k ++) {
					TreeNode *cur = new TreeNode(i);
					cur->left = le[j];
					cur->right = ri[k];
					ans.push_back(cur);
				}
			}
		}

		return ans;
	}
};