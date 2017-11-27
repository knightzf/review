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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* findNextValid(ListNode* node)
    {
        while(node && node->next && node->next->val == node->val)
        {
            int val = node->val;
            while(node && node->val == val)
            {
                node = node->next;
            }
        }

        return node;
    }

    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* newHead = findNextValid(head);

        if(newHead == nullptr)
        {
            return newHead;
        }

        ListNode* node = newHead;
        while(node && node->next)
        {
            node->next = findNextValid(node->next);
            node = node->next;
        }

        return newHead;
    }
};

int main()
{
    /*ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(3);
    ListNode* e = new ListNode(4);
    ListNode* f = new ListNode(4);
    ListNode* g = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;*/

    /*ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(1);
    ListNode* c = new ListNode(1);
    ListNode* d = new ListNode(2);
    ListNode* e = new ListNode(3);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;*/

    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(2);
    a->next = b;
    b->next = c;

    Solution sol;
    ListNode* res = sol.deleteDuplicates(a);

    while(res)
    {
        std::cout<<res->val<<" ";
        res = res->next;
    }

    std::cout<<std::endl;
}
