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
	vector<int> in, po;

	TreeNode *build(int is, int it, int ps, int pt) {
		TreeNode *node = new TreeNode(po[pt]);

		int idx = -1;
		for (int i = is; i <= it; i ++) {
			if (in[i] == po[pt]) {
				idx = i;
				break;
			}
		}

		int ln = idx - is;
		int rn = it - idx;
		if (ln > 0) {
			node->left = build(is, is + ln - 1, ps, ps + ln - 1);
		}
		if (rn > 0) {
			node->right = build(idx + 1, idx + rn, ps + ln, pt - 1);
		}

		return node;
	}

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
		if (!n) return NULL;

		in = inorder, po = postorder;

		TreeNode *root = build(0, n - 1, 0, n - 1);
		return root;
    }
};