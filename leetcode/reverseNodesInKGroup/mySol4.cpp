#include "header.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        for(int i = 0; i < k - 1; ++i)
        {
            if(!node) break;
            node = node->next;
        }
        if(!node) return head;
        
        auto p = reverseKGroup(node->next, k);
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = curr;
        while(prev != node)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head->next = p;

        return node;
    }
};


int main()
{
    Solution s;
}