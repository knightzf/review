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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> result;

    int sum(TreeNode* node)
    {
        if(node)
        {
            int total = node->val + sum(node->left) + sum(node->right);
            result.push_back(total);
            return total;
        }

        return 0;
    }

    bool checkEqualTree(TreeNode* root)
    {
        sum(root);

        if(result.size() <= 1)
        {
            return false;
        }

        int max = result.back();
        if(std::abs(max % 2) == 1)
            return false;

        std::sort(result.begin(), result.end());

        return std::find(result.begin(), result.end(), max/2) != result.end();
    }
};
int main()
{
    Solution sol;

    TreeNode* root = new TreeNode(0);
    TreeNode* a = new TreeNode(-4);
    TreeNode* b = new TreeNode(-3);
    root->left = a; root->right = b;
    TreeNode* c = new TreeNode(-1);
    a->left = c;
    TreeNode* d = new TreeNode(3);
    c->left = d;
    TreeNode* e = new TreeNode(-2);
    d->left = e;
    TreeNode* f = new TreeNode(8);
    b->left = f;
    TreeNode* g = new TreeNode(-9);
    f->left = g;
    TreeNode* h = new TreeNode(4);
    g->left = h;


    std::cout<<sol.checkEqualTree(root)<<std::endl;

	return 0;
}
