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
    ListNode* middle(ListNode* head){
        if(!head or !head->next) return head;
        ListNode *slow = head, *fast = head->next;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* a, ListNode* b){
        if(!a) return b;
        if(!b) return a;
        ListNode* temp;
        if(a->val<= b->val){
            temp = a;
            temp->next = merge(a->next, b);
        }
        else{
            temp = b;
            temp->next = merge(a, b->next);
        }
        return temp;
    }
    public: ListNode* sortList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* mid = middle(head);
        ListNode* a = head;
        ListNode* b = mid->next;
        mid->next = NULL;
        a = sortList(a); //merge sort on left half
        b = sortList(b); //merge sort on right half
        ListNode* temp = merge(a, b); //merge procedure
        return temp;
    }
};