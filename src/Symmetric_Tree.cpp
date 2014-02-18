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

    bool dfs(TreeNode *le, TreeNode *ri) {
        if (le == NULL && ri == NULL) return true;
        if ( (le != NULL && ri == NULL) || (le == NULL && ri != NULL)) return false;
        if (le->val != ri->val) return false;
        
        bool r1, r2;
        r1 = dfs(le->left, ri->right);
        r2 = dfs(le->right, ri->left);
        if  (!r1 || !r2) return false;
        return true;
    }
    
    bool isSymmetric(TreeNode *root) {
        bool same = dfs(root, root);
        
        return same;
    }
};