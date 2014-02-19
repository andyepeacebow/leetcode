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
        TreeLinkNode *cur = root;
        
        while (cur != NULL) {
            TreeLinkNode *nxtLev = NULL;
            TreeLinkNode *s1 = NULL;
            TreeLinkNode *s2 = NULL;
            
            // deal with one level
            while (cur != NULL) {
                if (cur->left != NULL) {
                    if (nxtLev == NULL) {
                        nxtLev = cur->left;
                    }
                    if (s1 == NULL) {
                        s1 = cur->left;
                    } else {
                        s2 = cur->left;
                    }
                }
                if (s1 != NULL && s2 != NULL) {
                    s1->next = s2;
                    s1 = s2;
                    s2 = NULL;
                }
                if (cur->right != NULL) {
                    if (nxtLev == NULL) {
                        nxtLev = cur->right;
                    }
                    if (s1 == NULL) {
                        s1 = cur->right;
                    } else {
                        s2 = cur->right;
                    }
                }
                if (s1 != NULL && s2 != NULL) {
                    s1->next = s2;
                    s1 = s2;
                    s2 = NULL;
                }
                cur = cur->next;
            }
            
            cur = nxtLev;
        }
    }
};