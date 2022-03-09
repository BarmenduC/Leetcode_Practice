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
  ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
       map<int,int> mymap;
        ListNode* temp=head;
        while(temp!=NULL){
            mymap[temp->val]++;
            temp=temp->next;
        }
        ListNode* temp1=head;
        ListNode* last=head;
        map<int,int>::iterator itr;
        for(itr=mymap.begin();itr!=mymap.end();itr++){
            if(itr->second<2){
            temp1->val=itr->first;
                last=temp1;
            temp1=temp1->next;
            }
        }
        int a=mymap.size();
        int x=0;
         ListNode* temp3=head;
        for(itr=mymap.begin();itr!=mymap.end();itr++){
            if(mymap.at(temp3->val)>1)x++;
            temp3=temp3->next;
        }
        if(x>=a)return NULL;
        last->next=NULL;
        return head;
    }
};