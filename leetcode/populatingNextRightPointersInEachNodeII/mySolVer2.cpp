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

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        impl(root, nullptr);
    }

    void impl(TreeLinkNode* node, TreeLinkNode* parent)
    {
        if(node == nullptr) return;
        if(parent)
        {
            if(node == parent->left && parent->right)
            {
                node->next = parent->right;
            }
            else
            {
                auto* p = parent->next;
                while(p)
                {
                    if(p->left)
                    {
                        node->next = p->left;
                        break;
                    }
                    if(p->right)
                    {
                        node->next = p->right;
                        break;
                    }
                    p = p->next;
                }
            }
        }

        impl(node->right, node);
        impl(node->left, node);
    }
};

int main() {
    Solution s;
}
