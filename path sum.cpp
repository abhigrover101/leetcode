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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool a=false,b=false;
        if(root==NULL)
            return false;

        sum=sum-root->val;
        if(!root->left && !root->right && sum==0)
            return true;
        else if(!root->left && !root->right && sum!=0)
            return false;

        if(root->left)
            a=hasPathSum(root->left,sum);
        if(root->right)
            b=hasPathSum(root->right,sum);

        return a||b;

    }
};
