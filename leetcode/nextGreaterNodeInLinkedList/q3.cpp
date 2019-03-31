#include "header.h"

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        while(head != nullptr)
        {
            v.push_back(head->val);
            head = head->next;
        }

        deque<int> q;
        vector<int> res(v.size(), 0);
        for(int i = v.size() - 1; i >= 0; --i)
        {
            while(!q.empty() && q.back() <= v[i])
            {
                q.pop_back();
            }

            if(!q.empty())
            {
                res[i] = q.back();
            }
            
            q.push_back(v[i]);
        }
        return res;
    }
};

int main()
{
    Solution s;
}

