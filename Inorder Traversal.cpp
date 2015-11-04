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

    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

       stack<TreeNode *> st;
       vector<int> ans;
       if(root==NULL)
            return ans;
       st.push(root);
       root=root->left;
       while(!st.empty() || root!=NULL)
       {
            while(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            ans.push_back((st.top()->val));
            root=st.top()->right;
            st.pop();
       }
       return ans;
    }
};
