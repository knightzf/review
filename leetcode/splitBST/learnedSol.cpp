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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        return impl(root, V);
    }

    vector<TreeNode*> impl(TreeNode* root, int V)
    {
        if(root == nullptr) return vector<TreeNode*>{nullptr, nullptr};

        if(root->val <= V)
        {
            auto res = impl(root->right, V);
            root->right = res[0];
            res[0] = root;
            return res;
        }
        else
        {
            auto res = impl(root->left, V);
            root->left = res[1];
            res[1] = root;
            return res;
        }
    }

};

int main() {
    Solution s;
    TreeNode* a = new TreeNode(4);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(6);
    TreeNode* d = new TreeNode(1);
    TreeNode* e = new TreeNode(3);
    TreeNode* f = new TreeNode(5);
    TreeNode* g = new TreeNode(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    s.splitBST(a, 2);
}
