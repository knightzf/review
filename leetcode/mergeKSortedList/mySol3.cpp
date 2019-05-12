#include "header.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct compare {
            bool operator()(ListNode* a, ListNode* b)
            {
                return a->val > b->val;
            }
        };

        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for(ListNode* node : lists) if(node) q.push(node);

        ListNode* res = nullptr, * node = nullptr;
        while(!q.empty())
        {
            auto t = q.top();
            if(!res) {
                res = t;
                node = res;
            } else {
                node->next = t;
                node = node->next;
            }

            if(t->next) q.push(t->next);
            q.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
}