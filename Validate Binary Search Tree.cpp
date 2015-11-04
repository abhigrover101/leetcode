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

    bool validate(TreeNode *root,int min,int max)
    {
        if(root==NULL)
            return true;
        if(root->val <= min || root->val >= max)
            return false;

        return validate(root->left,min,root->val) && validate(root->right,root->val,max);
    }

    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL)
            return true;
        return validate(root,INT_MIN,INT_MAX);

    }
};
