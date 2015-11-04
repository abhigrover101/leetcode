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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode *> q;
        queue <int> lvl;
        q.push(root);
        lvl.push(0);
        int l=0,num,tl=0,prev=0;
        vector <vector<int> > ans;
        if(root==NULL)
            return ans;
        vector<int> temp;
        while(!q.empty())
        {
            root=q.front();
            tl=lvl.front();
            q.pop();
            lvl.pop();
            if(tl!=prev)
            {
                ans.push_back(temp);
                temp.clear();
            }
            temp.push_back(root->val);
            if(root->left)
            {
                q.push(root->left);
                lvl.push(tl+1);
            }
            if(root->right)
            {
                q.push(root->right);
                lvl.push(tl+1);
            }
            prev=tl;
        }
        ans.push_back(temp);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
