#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        impl(root, res);
        return res;
    }

    bool impl(TreeNode* node, int& res)
    {
        if(node == nullptr) return true;

        bool left = impl(node->left, res);
        bool right = impl(node->right, res);

        if(left && right)
        {
            if(node->left && node->val != node->left->val)
            {
                return false;
            }

            if(node->right && node->val != node->right->val)
            {
                return false;
            }

            std::cout<<"found "<<node<<std::endl;
            ++res;
            return true;
        }

        return false;
    }
};


int main() {
    Solution s;
    TreeNode* a = new TreeNode(5);
    TreeNode* b = new TreeNode(1);
    TreeNode* c = new TreeNode(5);
    TreeNode* d = new TreeNode(5);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(5);

    a->left = b;
    a->right = c;
    b->left = e;
    b->right = f;
    c->right = d;

    std::cout<<"a "<<a<<std::endl;
    std::cout<<"b "<<b<<std::endl;
    std::cout<<"c "<<c<<std::endl;
    std::cout<<"d "<<d<<std::endl;
    std::cout<<"e "<<e<<std::endl;
    std::cout<<"f "<<f<<std::endl;

    s.countUnivalSubtrees(a);
}
