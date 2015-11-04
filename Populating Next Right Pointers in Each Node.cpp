/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:

    TreeLinkNode *findnext(TreeLinkNode *root)
    {
        while(root!=NULL)
        {
            if(root->left)
                return root->left;
            else if(root->right)
                return root->right;
            else
                root=root->next;
        }

        return NULL;


    }
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL)
            return;
        root->next=NULL;
        TreeLinkNode *head=root,*next=root;
        while(next!=NULL)
        {
            head=next;
            if(head->left!=NULL)
                next=head->left;
            else if(head->right!=NULL)
                next=head->right;
            else
                next=findnext(head->next);

            while(head!=NULL)
            {
                if(head->left && head->right)
                    head->left->next=head->right;
                else if(head->left && head->right==NULL)
                    head->left->next=findnext(head->next);

                if(head->right!=NULL)
                    head->right->next=findnext(head->next);
                head=head->next;
            }
        }
        return;
    }
};
