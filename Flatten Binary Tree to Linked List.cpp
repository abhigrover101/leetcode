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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL)
            return;
        stack <TreeNode*> st;

        st.push(root);
        while(!st.empty())
        {
            root=st.top();
            st.pop();
            if(root->right)
                st.push(root->right);
            if(root->left)
                st.push(root->left);
            if(!st.empty())
            {
                root->right=st.top();
                root->left=NULL;
            }
            else return;
        }

        return;
    }
};
