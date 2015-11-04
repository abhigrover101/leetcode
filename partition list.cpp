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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL)
            return NULL;
        int flag=0;
        ListNode *curr=head,*greater=NULL,*n=head->next;

        while(n!=NULL && curr!=NULL)
        {

            if(head->val>=x && greater==NULL)
            {
                flag=1;
                greater=head;
            }
            if(greater==NULL && n->val>=x)
            {
                greater=curr;
            }

            if(n->val < x && greater!=NULL)
            {
                curr->next=curr->next->next;
                if(flag==0)
                {
                    n->next=greater->next;
                    greater->next=n;
                    greater=n;
                }
                else
                {
                    n->next=greater;
                    head=n;
                    greater=n;
                    flag=0;
                }
            }
            if((curr->next!=NULL && curr->next->val >=x) || greater==NULL)
                curr=curr->next;
            if(curr!=NULL)
                n=curr->next;
        }
        return head;
    }
};
