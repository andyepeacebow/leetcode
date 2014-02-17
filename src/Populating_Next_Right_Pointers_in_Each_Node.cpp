/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *nxtLev = root;
        
        while (nxtLev != NULL) {
            TreeLinkNode *cur = nxtLev;
            nxtLev = nxtLev->left;
            while (cur != NULL && cur->left != NULL) {
                cur->left->next = cur->right;
                if (cur->next != NULL) {
                    cur->right->next = cur->next->left;
                } else {
                    cur->right->next = NULL;
                }
                cur = cur->next;
            }
        }
    }
};