#include "header.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head && head->next)
        {
            auto p1 = head;
            auto p2 = head->next;
            auto p = swapPairs(p2->next);
            p2->next = p1;
            p1->next = p;
            return p2;
        }
        return head;
    }
};

int main()
{
    Solution s;
}