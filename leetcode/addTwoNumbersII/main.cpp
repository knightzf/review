#include "header.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int m = 0, n = 0;
        stack<ListNode*> s1, s2;
        while(l1)
        {
            s1.push(l1);
            l1 = l1->next;
            ++m;
        }

        while(l2)
        {
            s2.push(l2);
            l2 = l2->next;
            ++n;
        }

        ListNode* prev = nullptr;
        int carry = 0;
        for(int i = 0; i < max(m, n); ++i)
        {
            int t = (s1.empty() ? 0 : s1.top()->val) + (s2.empty() ? 0 : s2.top()->val) + carry;
            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
            if(t >= 10)
            {
                t = t - 10;
                carry = 1;
            }
            else
                carry = 0;
            ListNode* newNode = new ListNode(t);
            newNode->next = prev;
            prev = newNode;
        }

        if(carry)
        {
            ListNode* newNode = new ListNode(1);
            newNode->next = prev;
            prev = newNode;
        }

        return prev;
    }
};

int main()
{
    Solution s;
}
