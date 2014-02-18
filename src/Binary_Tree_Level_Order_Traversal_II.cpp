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
    vector< vector<int> > ans;
    
    int dfs_hei(TreeNode *node) {
        if (node == NULL) return 0;
        
        int h1 = dfs_hei(node->left);
        int h2 = dfs_hei(node->right);
        int ret = 1 + max(h1, h2);
        return ret;
    }
    
    void dfs_set(TreeNode *node, int tot, int dep) {
        if (node == NULL) return;
        
        ans[tot - 1- dep].push_back(node->val);
        dfs_set(node->left, tot, dep + 1);
        dfs_set(node->right, tot, dep + 1);
    }
    
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        int hei = dfs_hei(root);
        
        for (int i = 0; i < hei; i ++) {
            vector<int> one;
            ans.push_back(one);
        }
        
        dfs_set(root, hei, 0);
        
        return ans;
    }
};