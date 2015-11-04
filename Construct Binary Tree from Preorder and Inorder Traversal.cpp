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

    TreeNode *Tree(vector<int> &preorder,vector<int> &inorder,int start,int end,int *i)
    {
        if(start>end)
            return NULL;
        int j;
        TreeNode *head;
        for(j=start;j<=end;j++)
        {
            if(inorder[j]==preorder[*i])
            {
                head=new TreeNode(preorder[*i]);
                (*i)++;
                head->left=Tree(preorder,inorder,start,j-1,i);
                head->right=Tree(preorder,inorder,j+1,end,i);
                break;
            }
        }
       return head;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=0;
        return Tree(preorder,inorder,0,preorder.size()-1,&i);

    }
};
