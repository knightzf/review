#include "header.h"

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        ListNode* t = root;
        while(t != nullptr)
        {
            ++len;
            t = t->next;
        }

        int avg = len / k;
        int res = len % k;

        vector<ListNode*> v;
        t = root;
        for(int i = 0; i < res; ++i)
        {
            v.push_back(t);
            for(int j = 0; j < avg; ++j)
            {
                t = t->next;
            }
            ListNode* p = t;            
            t = t->next;
            p->next = nullptr;
        }

        for(int i = res; i < k; ++i)
        {
            if(avg > 0)
            {
                v.push_back(t);
                for(int j = 0; j < avg - 1; ++j)
                {
                    t = t->next;
                }
                ListNode* p = t;            
                t = t->next;
                p->next = nullptr;
            }
            else
            {
                v.push_back(nullptr);
            }
        }

        return v;
    }
};

int main() {
    Solution s;
}
