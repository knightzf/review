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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode* root = nullptr, *prevNode = nullptr;

        auto cmp = [](ListNode* a, ListNode* b){ return a->val > b->val; };
        std::priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);

        for(int i = 0; i < lists.size(); ++i)
        {
            if(lists[i])
                q.push(lists[i]);
        }

        while(!q.empty())
        {
            if(root == nullptr) root = q.top();

            ListNode* node = q.top();
            if(prevNode) prevNode->next = node;
            prevNode = node;
            if(node->next) q.push(node->next);

            q.pop();
        }

        return root;
    }
};

int main() {
    Solution s;
}
