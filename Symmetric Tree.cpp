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

    bool chk(TreeNode *r1,TreeNode *r2)
    {
        if(r1==NULL && r2==NULL)
            return true;
        else if(r1!=NULL && r2!=NULL)
        {
            if(r1->val==r2->val)
            {
                return chk(r1->left,r2->right) && chk(r1->right,r2->left);
            }
            else
                return false;
        }
        else
            return false;
    }

    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL)
            return true;
        return chk(root->left,root->right);
    }
};
