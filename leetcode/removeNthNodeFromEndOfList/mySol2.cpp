#include "header.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode*> q;
        ListNode* node = head;
        while(node)
        {
            q.push(node);
            if(q.size() > n + 1) q.pop();
            node = node->next;
        }

        if(q.size() == n) {
            q.pop();
            if(q.empty()) return nullptr;
            return q.front();
        } else {
            ListNode* t = q.front();
            q.pop();
            q.pop();
            t->next = (q.empty() ? nullptr : q.front());
            return head;
        }
    }
};

int main()
{
    Solution s;
}