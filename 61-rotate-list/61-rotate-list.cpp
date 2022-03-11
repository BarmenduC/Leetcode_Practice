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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k ==0 || head == NULL || head->next==NULL) return head;
        ListNode* temp = head;
        int count =0;
        while(temp){
            count++;
            if(temp->next == NULL){
              temp->next = head;  
                break;
            } 
            temp = temp->next;
        }
        k = k%count;
        temp = head;
        int num = count -k -1;
        while(num--){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};