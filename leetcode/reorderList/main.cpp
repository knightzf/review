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
    void reorderList(ListNode* head)
    {
        std::vector<ListNode*> v;
        while(head)
        {
            v.push_back(head);
            head = head->next;
        }

        int n = v.size();

        if(n < 3) return;

        int i = 0;
        int j = n - 1;

        while(i < j)
        {
            if(i + 1 == j)
            {
                v[j]->next = nullptr;
                break;
            }

            v[i]->next = v[j];
            ++i;
            v[j]->next = v[i];
            --j;
        }

        if(i == j) v[i]->next = nullptr;
    }
};


int main()
{
    Solution s;
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    a->next = b;
    b->next = c;
    //c->next = d;

    s.reorderList(a);

    while(a)
    {
        std::cout<<a->val<<" ";
        a = a->next;
    }
    std::cout<<std::endl;
}
