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

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode* copyRandomList(RandomListNode *head)
    {
        if(head == nullptr) return nullptr;

        std::unordered_map<RandomListNode*, RandomListNode*> ptrMap;

        RandomListNode* newHead = new RandomListNode(head->label);
        newHead->random = head->random;

        ptrMap[head] = newHead;

        RandomListNode* p = head->next;
        RandomListNode* pre = newHead;

        while(p)
        {
            RandomListNode* node = new RandomListNode(p->label);
            node->random = p->random;
            ptrMap[p] = node;

            pre->next = node;
            pre = node;

            p = p->next;
        }

        p = newHead;
        while(p)
        {
            if(p->random)
            {
                p->random = ptrMap[p->random];
            }

            p = p->next;
        }

        return newHead;
    }
};

int main()
{
    Solution s;
}
