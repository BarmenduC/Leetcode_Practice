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
      bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return false;
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast && slow){
            slow=slow->next;
            if(fast->next)
                fast=fast->next->next;
            else return false;
            if(fast == slow)
                return true;
        }
        return false;
    }
};