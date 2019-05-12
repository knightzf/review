#include "header.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0); dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* curr = nullptr;
        for(int i = 0; i < m - 1; ++i)
        {
            pre = pre->next;
        }
        curr = pre->next;
        for(int i = 0; i < n - m; ++i)
        {
            ListNode* temp = pre->next;
            pre->next = curr->next;
            curr->next = curr->next->next;
            pre->next->next = temp;
        }
        return pre->next;
    }
};

int main()
{
    Solution s;
}