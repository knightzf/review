#include "header.h"

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        function<bool(TreeNode*, int)> f = [&](TreeNode* node, int sum)
        {
            if(!node) return false;
            if(!node->left && !node->right) return node->val + sum >= limit;
            bool left = f(node->left, sum + node->val);
            bool right = f(node->right, sum + node->val);
            if(!left) node->left = nullptr;
            if(!right) node->right = nullptr;
            return left || right;
        };

        if(!f(root, 0)) return nullptr;
        return root;
    }
};

int main()
{
    Solution s;
}

