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

using namespace std;

struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head == nullptr)
        {
            return head;
        }

        ListNode* n = head;
        int len = 1;
        while(n->next != nullptr)
        {
            n = n->next;
            ++len;
        }

        int steps = k % len;

        if(steps == 0)
        {
            return head;
        }

        steps = len - steps;

        ListNode* start = head;
        for(int i = 0; i < steps - 1; ++i)
        {
            start = start->next;
        }

        ListNode* newHead = start->next;

        start->next = NULL;

        ListNode* t = newHead;
        while(t && t->next != nullptr)
        {
            t = t->next;
        }

        t->next = head;

        return newHead;
    }
};


int main()
{
    Solution sol;
    return 0;
}
