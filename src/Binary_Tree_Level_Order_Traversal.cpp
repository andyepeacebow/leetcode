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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector< vector<int> > ans;
        if (root == NULL) return ans;
        
        queue<TreeNode*> que;
        que.push(root);
        int curLevCnt = 1, nextLevCnt = 0;
        int cnt = 0;
        vector<int> line;
        
        while (que.empty() == false) {
            TreeNode *cur = que.front();
            que.pop();
            line.push_back(cur->val);
            
            if (cur->left != NULL) {
                que.push(cur->left);
                nextLevCnt ++;
            }
            if (cur->right != NULL) {
                que.push(cur->right);
                nextLevCnt ++;
            }
            
            cnt ++;
            if (cnt >= curLevCnt) {
                curLevCnt = nextLevCnt;
                nextLevCnt = cnt = 0;
                ans.push_back(line);
                line.clear();
            }
        }
        
        return ans;
    }
};