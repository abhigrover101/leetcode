/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *rev(ListNode *head,int num)
    {
        if(head==NULL)
            return NULL;
        int j=0;
        ListNode *prev=NULL,*cur=head,*next,*root=head;
        while(j<=num)
        {
            next=cur->next;;
            cur->next=prev;
            prev=cur;
            cur=next;
            j++;
        }
        root->next=cur;
        return prev;
    }


    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *root=head;

        int i=1;
        while(i<m-1)
        {
            root=root->next;
            i++;
        }
        if(m!=1)
            root->next=rev(root->next,n-m);
        else if(m==1)
            head=rev(head,n-m);
        return head;
    }
};
