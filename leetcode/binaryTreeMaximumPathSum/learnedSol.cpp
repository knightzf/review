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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }

        maxSum = INT_MIN;

        maxPathDown(root);

        return maxSum;
    }

    int maxPathDown(TreeNode* node)
    {
        if(node == nullptr)
        {
            return 0;
        }

        int leftMax = std::max(0, maxPathDown(node->left));
        int rightMax = std::max(0, maxPathDown(node->right));

        maxSum = std::max(maxSum, leftMax + rightMax + node->val);

        return std::max(leftMax, rightMax) + node->val;
    }

private:
    int maxSum;
};

int main()
{
    Solution s;
    /*TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(-2);
    TreeNode* c = new TreeNode(-3);
    a->left = b;
    a->right = c;
    TreeNode* d = new TreeNode(1);
    TreeNode* e = new TreeNode(3);
    b->left = d;
    b->right = e;
    TreeNode* f = new TreeNode(-2);
    c->left = f;
    TreeNode* g = new TreeNode(-1);
    d->left = g;*/
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    a->right = b;
    b->right = c;
    c->right = d;
    d->right = e;
    std::cout<<s.maxPathSum(a)<<std::endl;
}
