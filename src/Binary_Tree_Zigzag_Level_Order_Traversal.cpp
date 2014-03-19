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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
		if (root == NULL) return res;

		vector<TreeNode*> vec[2];
		vector<int> once[2];
		int pre = 0, nxt = 1;

		vec[0].push_back(root);
		once[0].push_back(root->val);

		while (!vec[0].empty() || !vec[1].empty()) {
			TreeNode *no = vec[pre].back();
			vec[pre].pop_back();

			if (pre == 0) { // from right to left
				if (no->right != NULL) {
					vec[nxt].push_back(no->right);
					once[nxt].push_back(no->right->val);
				}
				if (no->left != NULL) {
					vec[nxt].push_back(no->left);
					once[nxt].push_back(no->left->val);
				}
			} else { // from left to right
				if (no->left != NULL) {
					vec[nxt].push_back(no->left);
					once[nxt].push_back(no->left->val);
				}
				if (no->right != NULL) {
					vec[nxt].push_back(no->right);
					once[nxt].push_back(no->right->val);
				}
			}

			if (vec[pre].empty()) {
				res.push_back(once[pre]);
				once[pre].clear();
				swap(pre, nxt);
			}

		}

		return res;
    }
};