#include "header.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> v;
        ListNode* node = head;
        for(int i = 0; i < k; ++i)
        {
            if(!node) return head;
            v.emplace_back(node);
            node = node->next;
        }

        ListNode* p = reverseKGroup(v.back()->next, k);
        for(int i = k - 1; i > 0; --i)
        {
            v[i]->next = v[i - 1];
        }
        v[0]->next = p;
        return v.back();
    }
};

int main()
{
    Solution s;
}