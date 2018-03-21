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
#include <iterator>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return impl(head, k);
    }

    ListNode* impl(ListNode* node, int k) {
        int cnt = 0;
        std::vector<ListNode*> v;
        while(node && cnt < k)
        {
            v.push_back(node);
            node = node->next;
            ++cnt;
        }

        if(cnt == k)
        {
            for(int i = k - 1; i > 0; --i)
            {
                v[i]->next = v[i - 1];
            }

            v[0]->next = impl(node, k);
            return v[k - 1];
        }

        return v.empty() ? nullptr : v[0];
    }
};

int main() {
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

    ListNode* r = s.reverseKGroup(a, 1);
    while(r)
    {
        std::cout<<r->val<<" ";
        r = r->next;
    }
    std::cout<<std::endl;
}
