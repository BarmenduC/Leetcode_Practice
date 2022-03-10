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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* output = new ListNode(0);
        ListNode* realOutput = output;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr)
        {
            const auto val1 = l1 == nullptr ? 0 : l1->val;
            const auto val2 = l2 == nullptr ? 0 : l2->val;
            output->next = new ListNode((val1 + val2 + carry) % 10);
            carry = (val1 + val2 + carry) / 10; 
            output = output->next;
            l1 = l1 == nullptr ? nullptr : l1->next;
            l2 = l2 == nullptr ? nullptr : l2->next;
        }
        if (carry > 0)
        {
            output->next = new ListNode(carry);
        }
        return realOutput->next;
    }
};