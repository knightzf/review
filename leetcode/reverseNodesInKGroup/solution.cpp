#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* prev = NULL;
        std::vector<ListNode*> nodeVec(k, NULL);
        ListNode* next = NULL;

        bool firstGroup = true;

        ListNode* current = head;

        while(true)
        {
            bool shouldBreak = false;
            for(size_t i = 0; i < k; ++i)
            {
                if(!current)
                {
                    shouldBreak = true;
                    break;
                }

                nodeVec[i] = current;
                current = current->next;
            }

            if(shouldBreak)
            {
                break;
            }

            next = nodeVec.back()->next;

            if(firstGroup)
            {
                head = nodeVec.back();
                firstGroup = false;
            }

            for(size_t i = 0; i < k; ++i)
            {
                if(i == 0)
                {
                    nodeVec[i]->next = next;
                }
                else
                {
                    nodeVec[i]->next = nodeVec[i - 1];
                }
            }

            if(prev)
            {
                prev->next = nodeVec.back();
            }

            prev = nodeVec.front();
        }

        return head;
    }
};

int main()
{
    Solution sol;
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    ListNode* result = sol.reverseKGroup(a, 3);
    while(result)
    {
        std::cout<<result->val<<" ";
        result = result->next;
    }
    std::cout<<std::endl;

    return 0;
}
