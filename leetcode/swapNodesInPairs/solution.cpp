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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* pre = NULL;
        ListNode* a = head;
        ListNode* b = NULL;
        ListNode* next = NULL;

        bool begin = true;

        while(true)
        {
            if(a && a->next)
            {
                b = a->next;
                next = b->next;
            }
            else
            {
                break;
            }

            b->next = a;
            a->next = next;

            if(begin)
            {
                head = b;
                begin = false;
            }
            else
            {
                pre->next = b;
            }

            pre = a;
            a = a->next;
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
    a->next = b;
    b->next = c;
    c->next = d;

    a = sol.swapPairs(a);

    while(a)
    {
        std::cout<<a->val<<" ";
        a = a->next;
    }
    std::cout<<std::endl;
    return 0;
}
