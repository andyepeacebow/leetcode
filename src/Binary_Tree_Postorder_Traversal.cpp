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
	vector<int> ans;

    vector<int> postorderTraversal(TreeNode *root) {
		if (root == NULL) return ans;

        stack<TreeNode*> sta;
		sta.push(root);
		TreeNode *pre = NULL;
		while (sta.empty() == false) {
			TreeNode *node = sta.top();
			sta.pop();
			if (pre != NULL && (pre == node->right || pre == node->left)) {
				ans.push_back(node->val);
				pre = node;
				continue;
			}
			if (node->left == NULL && node->right == NULL) {
				ans.push_back(node->val);
				pre = node;
			} else {
				sta.push(node);
				if (node->right != NULL) {
					sta.push(node->right);
				}
				if (node->left != NULL) {
					sta.push(node->left);
				}
			}
		}

		return ans;
    }
};