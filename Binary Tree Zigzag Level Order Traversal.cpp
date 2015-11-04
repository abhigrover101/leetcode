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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode *> q;
        queue<int> lvl;
        vector <vector <int> > ans;
        vector<int> temp;
        if(root==NULL)
            return ans;
        q.push(root);
        lvl.push(0);
        int l=0,prev=0;
        while(!q.empty())
        {
            root=q.front();
            l=lvl.front();
            q.pop();
            lvl.pop();
            if(l!=prev)
            {
                if(prev%2==0)
                    ans.push_back(temp);
                else
                {
                    reverse(temp.begin(),temp.end());
                    ans.push_back(temp);
                }
                temp.clear();
            }
            temp.push_back(root->val);
            if(root->left)
            {
                q.push(root->left);
                lvl.push(l+1);
            }
            if(root->right)
            {
                q.push(root->right);
                lvl.push(l+1);
            }
            prev=l;
        }
        if(prev%2==0)
            ans.push_back(temp);
        else
        {
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        temp.clear();
        return ans;
    }
};
