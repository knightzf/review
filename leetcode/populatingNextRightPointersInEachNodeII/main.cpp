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

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root)
    {
        impl(root, nullptr);
    }

    void impl(TreeLinkNode* node, TreeLinkNode* parent)
    {
        if(!node) return;

        if(parent)
        {
            if(node == parent->right ||(node == parent->left && !parent->right))
            {
                TreeLinkNode* t = parent->next;
                while(t)
                {
                    if(t->left)
                    {
                        node->next = t->left;
                        break;
                    }
                    else if(t->right)
                    {
                        node->next = t->right;
                        break;
                    }
                    t = t->next;
                }
            }
            else
            {
                node->next = parent->right;
            }
        }

        if(node->right)
        {
            impl(node->right, node);
        }

        if(node->left)
        {
            impl(node->left, node);
        }
    }
};

int main()
{
    Solution s;
    TreeLinkNode* a = new TreeLinkNode(1);
    TreeLinkNode* b = new TreeLinkNode(2);
    TreeLinkNode* c = new TreeLinkNode(3);
    a->left = b;
    a->right = c;

    s.connect(a);
}
