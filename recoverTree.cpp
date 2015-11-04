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

    void find(TreeNode *root,TreeNode **prev,TreeNode **n1,TreeNode **n2)
    {
        if(root==NULL)
            return;
        find(root->left,prev,n1,n2);
        if((*prev)!=NULL && root->val < (*prev)->val && (*n1)==NULL && (*n2)==NULL)
        {
            *n1=(*prev);
            *n2=root;
        }
        else if((*prev)!=NULL && root->val < (*prev)->val)
            *n2=root;
        (*prev)=root;
        find(root->right,prev,n1,n2);
        return;
    }

    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *prev=NULL,*n1=NULL,*n2=NULL,*temp=NULL;

        temp=new TreeNode(0);
        find(root,&prev,&n1,&n2);
        if(n1!=NULL || n2!=NULL)
        {
            temp->val=n1->val;
            n1->val=n2->val;
            n2->val=temp->val;
        }
        return;

    }
};
