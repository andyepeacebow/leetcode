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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            if (cur->right != NULL) st.push(cur->right);
            if (cur->left != NULL) st.push(cur->left);
        }
        
        return ans;
    }
};