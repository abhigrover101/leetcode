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
        ListNode *next,*curr=head;
        while(curr!=NULL)
        {
            next=curr->next;
            while(next && (next->val == curr->val))
            {
                free(next);
                curr->next=next->next;
                next=curr->next;
            }
            curr=curr->next;
        }

        return head;
    }
};
