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
    int idx;
    int n;
    
    TreeNode *build_tree() {
        int nc = 1;
        queue<TreeNode*> que;
        TreeNode *root = new TreeNode(nc);
        que.push(root);
        
        while (nc < n) {
            TreeNode *cur = que.front();
            que.pop();
            
            nc ++;
            cur->left = new TreeNode(nc);
            que.push(cur->left);
            if (nc >= n) break;
            
            nc ++;
            cur->right = new TreeNode(nc);
            que.push(cur->right);
        }
        
        return root;
    }
    
    void dfs_set_val(TreeNode *node, vector<int> &vec) {
        if (node == NULL) return;
        
        dfs_set_val(node->left, vec);
        node->val = vec[idx], idx ++;
        dfs_set_val(node->right, vec);
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        n = num.size();
        if (n == 0) return NULL;
        
        idx = 0;
        TreeNode *root = build_tree();
        dfs_set_val(root, num);
        return root;
    }
};