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
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* smallHead = nullptr;
        ListNode* smallTail = nullptr;
        ListNode* largeHead = nullptr;
        ListNode* largeTail = nullptr;

        ListNode* t = head;

        while(t)
        {
            if(t->val >= x)
            {
                if(largeHead == nullptr)
                {
                    largeHead = t;
                    largeTail = t;
                }
                else
                {
                    largeTail->next = t;
                    largeTail = t;
                }
            }
            else
            {
                if(smallHead == nullptr)
                {
                    smallHead = t;
                    smallTail = t;
                }
                else
                {
                    smallTail->next = t;
                    smallTail = t;
                }
            }

            t = t->next;
        }

        if(largeTail)
        {
            largeTail->next = nullptr;
        }

        if(smallHead)
        {
            smallTail->next = largeHead;
        }

        return smallHead ? smallHead : largeHead;
    }
};

int main()
{
    Solution s;
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(4);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(2);
    ListNode* e = new ListNode(5);
    ListNode* f = new ListNode(2);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    ListNode* r = s.partition(a, 3);

    while(r)
    {
        std::cout<<r->val<<" ";
        r = r->next;
    }
    std::cout<<std::endl;
}
