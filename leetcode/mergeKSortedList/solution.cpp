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

class Comp{
public:
    bool operator()(const ListNode* a, const ListNode* b) const
    {
        return a->val < b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode* head = NULL;
        ListNode* temp = NULL;

        std::multiset<ListNode*, Comp> nodeMap;
        for(const auto& head : lists)
        {
            if(head)
            {
                nodeMap.insert(head);
            }
        }

        while(!nodeMap.empty())
        {
            auto iter = nodeMap.begin();
            ListNode* minNode = *iter;

            if(!head)
            {
                head = minNode;
                temp = minNode;
            }
            else
            {
                temp->next = minNode;
                temp = temp->next;
            }

            if(minNode->next)
            {
                nodeMap.insert(minNode->next);
            }
            nodeMap.erase(iter);
        }

        return head;
    }
};

int main()
{
    Solution sol;
    ListNode* a = new ListNode(0);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(5);
    a->next = b;
    b->next = c;
    std::vector<ListNode*> v{a};
    ListNode* n = sol.mergeKLists(v);
    while(n)
    {
        std::cout<<n->val<<" ";
        n = n->next;
    }
    std::cout<<std::endl;
    return 0;
}
