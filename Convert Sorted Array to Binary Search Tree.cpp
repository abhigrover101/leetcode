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

    TreeNode *convert(vector<int> &num,int start,int end)
    {
        if(start>end)
            return NULL;
        TreeNode *head=new TreeNode(num[(start+end)/2]);
        head->left=convert(num,start,(start+end)/2-1);
        head->right=convert(num,(start+end)/2+1,end);
        return head;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return convert(num,0,num.size()-1);

    }
};
