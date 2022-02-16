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
    ListNode* swapPairs(ListNode* head) {
    // return empty if head is empty
        if (head == nullptr) 
            return nullptr;
    // set head to the second element if the list is >2 elements, or to the first if the list is ==1 element
        ListNode *prev = nullptr, *theHead = (head->next) ? head->next : head;
        while (head && head->next) {
        // swap first and second nodes. If there is a previous node, relink its "next" to the new first node
            SwapNode(prev, head, head->next);
        // keep record of second (now first) node for relinking
            prev = head;
        // now the head is in the second element spot; increment by one
            head = head->next;
        }  
        return theHead;
    }
    void SwapNode(ListNode *prev, ListNode *nd1, ListNode *nd2) {
    // temporary for swapping linkage
        ListNode *newNode = nd2->next;
        nd2->next = nd1;
        nd1->next = newNode;
    // relink the previous element that is pointing to the second element (previous first element),
    // to now link to the new first element (previous second element)
        if (prev)
            prev->next = nd2;
    }
};