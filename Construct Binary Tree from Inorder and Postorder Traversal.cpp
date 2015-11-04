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

    TreeNode* Tree(vector<int> &inorder,vector<int> &postorder,int start,int end,int *i)
    {
        if(start>end)
            return NULL;
        TreeNode *head;

        int j=0;
        for(j=start;j<=end;j++)
        {
            if(inorder[j]==postorder[(*i)])
            {
                head= new TreeNode(postorder[(*i)]);
                (*i)++;
                head->right=Tree(inorder,postorder,j+1,end,i);                  //search right part first
                head->left=Tree(inorder,postorder,start,j-1,i);
                break;
            }
        }
        if(j>end)
            return NULL;
        else
            return head;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=0;
        reverse(postorder.begin(),postorder.end());
        return Tree(inorder,postorder,0,postorder.size()-1,&i);

    }
};
