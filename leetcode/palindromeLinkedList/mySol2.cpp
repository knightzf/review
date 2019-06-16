#include "header.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head, *pre = nullptr;
        while(fast && fast->next) {
            fast = fast->next->next;
            ListNode* temp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = temp;
        }

        if(fast) slow = slow->next;

        while(slow) {
            if(slow->val != pre->val) return false;
            slow = slow->next;
            pre = pre->next;
        }
        return true;
    }
};

int main()
{
    Solution s;
}