#include "header.h"

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int res = 0;
        impl(nullptr, root, res);
        return res;
    }

    void impl(TreeNode* parent, TreeNode* node, int& res)
    {
        if(node == nullptr) return;

        impl(node, node->left, res);
        impl(node, node->right, res);

        if(node->val > 1)
        {
            parent->val += node->val - 1;
            res += node->val - 1;
        }
        else if(node->val < 1)
        {
            parent->val += node->val -1;
            res += 1- node->val;
        }
    }
};

int main()
{
    Solution s;
}

