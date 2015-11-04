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

    int chkheight(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int left,right;
        left=chkheight(root->left);
        right=chkheight(root->right);

        if(left==-1 || right==-1)
            return -1;
        else if(abs(left-right)>1)
            return -1;
        else
            return max(left,right)+1;

    }

    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(chkheight(root)==-1)
            return false;
        else
            return true;

    }
};
