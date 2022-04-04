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
    // Iterative Approach using three pointers; 
     ListNode* swapNodes(ListNode* head, int k) {
        ListNode * kp=head;
        for(int i=1;i<k;i++){
            kp=kp->next;
        }
        int * temp = & (kp->val);
        int count=k;
        while(kp!=NULL){
            kp=kp->next;
            count++;
        }
        kp=head;
        for(int i=1;i<count-k;i++){
            kp=kp->next;
        }
        swap(kp->val,*temp);
        return head;
    }

};