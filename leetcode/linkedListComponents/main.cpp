#include "header.h"

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> nums(G.begin(), G.end());
        int res = 0;
        bool found = false;
        while(head)
        {
            if(nums.find(head->val) != nums.end())
            {
                if(found == false)
                {
                    ++res;
                    found = true;
                }
            }
            else
            {
                found = false;
            }
            head = head->next;
        }
        return res;
    }
};

int main()
{
    Solution s;
    ListNode* a = new ListNode(0);
    ListNode* b = new ListNode(1);
    ListNode* c = new ListNode(2);
    ListNode* d = new ListNode(3);
    a->next = b; b->next = c; c->next = d;
    ListNode* e = new ListNode(4);
    d->next = e;

    vector<int> G{0, 3, 1, 4};
    std::cout<<s.numComponents(a, G)<<std::endl;
}
