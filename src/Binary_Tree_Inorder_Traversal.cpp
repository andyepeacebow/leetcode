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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while (!st.empty() || cur != NULL) {
            while (cur != NULL) {
                st.push(cur);
                cur = cur->left;
            }
            
            cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            
            cur = cur->right;
        }
        
        return ans;
    }
};