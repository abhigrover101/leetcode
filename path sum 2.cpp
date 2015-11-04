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

    void path(TreeNode *root,int sum,vector<int> s,vector <vector<int> > &ans)
    {

        s.push_back(root->val);
        sum=sum-root->val;
        if(root->left)
            path(root->left,sum,s,ans);
        if(root->right)
            path(root->right,sum,s,ans);

        if(!root->left && !root->right && sum==0)
            ans.push_back(s);
        return;
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector <vector <int> > ans;
        vector<int> s;
        if(root==NULL)
        {
            return ans;
        }
        path(root,sum,s,ans);
        return ans;
    }
};
