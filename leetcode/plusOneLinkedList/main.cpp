#include "header.h"

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> s;
        ListNode* node = head;
        while(node)
        {
            s.push(node);
            node = node->next;
        }

        int carry = 0;
        if(!s.empty())
        {
            int t = s.top()->val + 1 + carry;
            if(t <= 9)
            {
                s.top()->val = t;
            }
            else
            {
                carry = t / 10;
                s.top()->val = t % 10;
                s.pop();

                while(!s.empty())
                {
                    t = s.top()->val + carry;
                    if(t > 9)
                    {
                        carry = t / 10;
                        s.top()->val = t % 10;
                        s.pop();
                    }
                    else
                    {
                        s.top()->val = t;
                        carry = 0;
                        break;
                    }
                }
            }
        }

        if(carry != 0)
        {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};

int main()
{
    Solution s;
}
