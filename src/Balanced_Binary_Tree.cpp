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

    int dfs(TreeNode *node) {
        if (node == NULL) return 0;
        
        int h1 = dfs(node->left);
        int h2 = dfs(node->right);
        
        if (h1 < 0 || h2 < 0) return -1;
        if (abs(h1 - h2) >= 2) return -1;
        
        int h = 1 + max(h1, h2);
        return h;
    }
    
    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;
        
        int ret = dfs(root);
        if (ret < 0) return false;
        else return true;
    }
};