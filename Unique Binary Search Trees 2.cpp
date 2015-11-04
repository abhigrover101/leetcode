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

    void generate(vector <TreeNode *> &trees,int start,int end)
    {
        if(start>end)
        {
            trees.push_back(NULL);
            return;
        }

        if(start==end)
        {
            TreeNode *h=new TreeNode(start);
            trees.push_back(h);
            return;
        }

        int i,j,k;

        for(i=start;i<=end;i++)
        {
            vector <TreeNode *> le,ri;
            le.clear();
            ri.clear();
            generate(le,start,i-1);
            generate(ri,i+1,end);
            for(j=0;j<le.size();j++)
            {
                for(k=0;k<ri.size();k++)
                {
                    TreeNode *head=new TreeNode(i);
                    head->left=le[j];
                    head->right=ri[k];
                    trees.push_back(head);
                }
            }
        }
    }

    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector <TreeNode *> trees;
        generate(trees,1,n);
        return trees;

    }
};
