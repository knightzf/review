#include "header.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* p1 = head, *p2 = head->next;
        while(p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        ListNode* mid = p1->next;
        p1->next = nullptr;
        ListNode* pre = nullptr;
        while(mid) {
            ListNode* temp = mid->next;
            mid->next = pre;
            pre = mid;
            mid = temp;
        }

        p1 = head;
        p2 = pre;
        while(p1 && p2) {
            ListNode* temp = p1->next;
            p1->next = p2;
            p2 = p2->next;
            if(temp != nullptr) p1->next->next = temp;
            p1 = temp;
        }
    }
};

int main()
{
    Solution s;
    
}