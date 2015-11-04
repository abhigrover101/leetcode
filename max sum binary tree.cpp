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
    int maxsum(TreeNode *root,int *ans)
    {
        if(root==NULL)
            return 0;
        int left=maxsum(root->left,ans);
        int right=maxsum(root->right,ans);
        if(*ans<left+right+root->val)
           * ans=left+right+root->val;
        if(*ans<root->val)
            *ans=root->val;
        if(*ans < root->val + left)
            *ans=root->val + left;
        if(*ans < root->val + right)
            *ans=root->val + right;
        if(root->val + max(left,right) > root->val)
            return max(left,right)+root->val;
        else
            return root->val;
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans=-INT_MAX;
        maxsum(root,&ans);
        return ans;
    }
};
