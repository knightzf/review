#include "header.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        impl(root, nullptr, res);
        return res;
    }

    void impl(TreeNode* node, TreeNode* parent, int& res)
    {
        if(node == nullptr) return;

        impl(node->left, node, res);
        if(node->left == nullptr && node->right == nullptr && parent != nullptr && node == parent->left)
            res += node->val;
        impl(node->right, node, res);
    }
};


int main()
{
    //Solution s;
}
