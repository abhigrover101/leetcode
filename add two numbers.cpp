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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ans,*re;
        ans= new ListNode(0);
        re=ans;
        int carry=0,num=0;
        while(l1!=NULL || l2!=NULL)
        {
            if(l1!=NULL && l2!=NULL)
            {
                num=(l1->val+l2->val+carry)%10;
                carry=(l1->val+l2->val+carry)/10;
                ListNode *temp;
                temp=new ListNode(num);
                l1=l1->next;
                l2=l2->next;
                ans->next=temp;
                ans=ans->next;
            }
            else if(l1!=NULL && l2==NULL)
            {
                num=(l1->val+carry)%10;
                carry=(l1->val+carry)/10;
                ListNode *temp;
                temp=new ListNode(num);
                l1=l1->next;
                ans->next=temp;
                ans=ans->next;
            }
            else if(l1==NULL && l2!=NULL)
            {
                num=(l2->val+carry)%10;
                carry=(l2->val+carry)/10;
                ListNode *temp;
                temp=new ListNode(num);
                l2=l2->next;
                ans->next=temp;
                ans=ans->next;
            }
        }
        if(carry!=0)
        {
            ListNode *temp;
            temp= new ListNode(carry);
            ans->next=temp;
        }
        return re->next;
    }
};
