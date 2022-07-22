/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* great = new ListNode(0);
        
        ListNode* smalltail  = small;
        ListNode* greattail = great;
        
        while(head!=NULL){
            if(head->val < x){
                smalltail->next = head;
                smalltail = smalltail->next;
            }
            else{
                greattail->next = head;
                greattail = greattail->next;
            }
            head = head -> next;
        }
        greattail->next = NULL;
        smalltail->next = great->next;
        
        return small->next;
    }
};