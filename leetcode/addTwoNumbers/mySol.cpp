#include "header.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = nullptr;
        ListNode* t = nullptr;
        int carry = 0;
        while(l1 || l2)
        {
            int sum = 0;
            if(l1 && l2)
            {
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1)
            {
                sum = l1->val + carry;
                l1 = l1->next;
            }
            else
            {
                sum = l2->val + carry;
                l2 = l2->next;
            }

            if(sum > 9)
            {
                sum = sum % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            if(res == nullptr)
            {
                res = new ListNode(sum);
                t = res;
            }
            else
            {
                t->next = new ListNode(sum);
                t = t->next;
            }          
        }
        if(carry) t->next = new ListNode(carry);
        return res;
    }
};

int main()
{
    Solution s;
}