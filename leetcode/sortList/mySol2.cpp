#include "header.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* p1 = head, *p2 = head->next;
        while(p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        ListNode* t = p1->next;
        p1->next = nullptr;
        p1 = sortList(head);
        p2 = sortList(t);

        ListNode dummy(0);
        ListNode* newHead = &dummy, *pre = newHead;
        while(p1 && p2) {
            if(p1->val <= p2->val) {
                pre->next = p1;
                pre = p1;
                p1 = p1->next;
            }
            else {
                pre->next = p2;
                pre = p2;
                p2 = p2->next;
            }            
        }
        if(p1) pre->next = p1;
        if(p2) pre->next = p2;
        return newHead->next;
    }
};

int main()
{
    //Solution s;    
}