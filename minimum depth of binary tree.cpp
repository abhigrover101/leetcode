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

    void depth(TreeNode *root,int height,int *ans)
    {
        if(root->left==NULL && root->right==NULL && height+1 < *ans)
        {
            *ans=height+1;
            return;
        }
        if(root->left)
            depth(root->left,height+1,ans);
        if(root->right)
            depth(root->right,height+1,ans);
        return;
    }

    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL)
         return 0;
        int ans=INT_MAX;
        depth(root,0,&ans);
        return ans;
    }
};
