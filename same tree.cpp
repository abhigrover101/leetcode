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
    bool isSameTree(TreeNode *r1, TreeNode *r2) {
        if(r1==NULL && r2==NULL)
            return true;
        else if(r1!=NULL && r2!=NULL)
        {
            if(r1->val==r2->val)
            {
                return isSameTree(r1->left,r2->left) && isSameTree(r1->right,r2->right);
            }
            else
                return false;
        }
        else
            return false;

    }
};
