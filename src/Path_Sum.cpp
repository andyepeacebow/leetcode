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

    bool dfs(TreeNode *node, int cur, int tar) {
        if (node->left == NULL && node->right == NULL) {
            bool ret = cur + node->val == tar;
            return ret;
        }
        
        bool r1 = false, r2 = false;
        if (node->left != NULL) {
            r1 = dfs(node->left, cur + node->val, tar);
        }
        if (node->right != NULL) {
            r2 = dfs(node->right, cur + node->val, tar);
        }
        
        bool ret = r1 || r2;
        return ret;
    }
    
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        
        bool res = dfs(root, 0, sum);
        return res;
    }
};