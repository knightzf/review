#include "header.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr, *curr = head;
        while(curr) {
            ListNode* t = curr->next;
            curr->next = pre;
            pre = curr;
            curr = t;
        }
        return pre;
    }
};

int main()
{
    Solution s;
}