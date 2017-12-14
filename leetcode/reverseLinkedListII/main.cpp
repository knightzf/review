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
#include <memory>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        if(m == n)
        {
            return head;
        }

        ListNode* lastBefore = nullptr;
        ListNode* first = nullptr;
        ListNode* last = nullptr;
        ListNode* firstAfter = nullptr;

        ListNode* lastNode = nullptr;

        ListNode* t = head;

        int idx = 0;

        while(t)
        {
            ++idx;

            if(idx == m - 1)
            {
                lastBefore = t;
            }
            else if(idx == m)
            {
                first = t;
            }
            else if(idx == n)
            {
                last = t;
            }
            else if(idx == n + 1)
            {
                firstAfter = t;
            }

            if(idx >= m && idx <= n)
            {
                ListNode* temp = t->next;

                if(lastNode)
                {
                    t->next = lastNode;
                }

                lastNode = t;

                t = temp;
            }
            else
            {
                t = t->next;
            }
        }

        if(lastBefore)
        {
            lastBefore->next = last;
        }
        else
        {
            head = last;
        }

        first->next = firstAfter;

        return head;
    }
};

int main()
{
    Solution s;
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    ListNode* n = s.reverseBetween(a, 2, 4);

    while(n)
    {
        std::cout<<n->val<<" ";
        n = n->next;
    }
}
