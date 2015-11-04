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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if(head==NULL || head->next==NULL)
            return head;

        ListNode *start=head->next,*current=head,*prev=NULL,*root=NULL;
        int flag=0;
        while(current!=NULL)
        {
            if(current==NULL)
                break;
            flag=0;
            while(start && current->val==start->val)
            {
                flag=1;
                start=start->next;
            }

            if(flag==0)
            {
                if(root==NULL)
                    root=current;
                if(prev==NULL)
                    prev=current;
                else if(prev!=NULL)
                {
                    prev->next=current;
                    prev=current;
                }
                if(start!=NULL)
                    start=start->next;
                current=current->next;
            }
            if(flag==1)
            {
                if(prev!=NULL)
                    prev->next=start;
                current=start;
                if(start)
                    start=start->next;
            }
        }
        return root;
    }
};
