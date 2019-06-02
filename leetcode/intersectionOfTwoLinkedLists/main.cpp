#include "header.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA, *b = headB;
        while(a != b) {
            a = a->next ? a->next : headA;
            b = b->next ? b->next : headB;
        }
        return a;
    }
};


int main()
{
    //Solution s;    
}