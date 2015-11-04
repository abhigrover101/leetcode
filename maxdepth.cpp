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

    int depth(TreeNode *root,int *height)
    {
        if(root==NULL)
            return 0;
        int left=depth(root->left,height),right=depth(root->right,height);
        if(*height<max(left,right)+1)
            *height=max(left,right)+1;
        return max(left,right)+1;
    }

    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL)
            return 0;
        int height=0;
        depth(root,&height);
        return height;
    }
};
