#include "header.h"

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return f(root, 0).first;
    }

    pair<TreeNode*, int> f(TreeNode* node, int level)
    {
        if(!node) return make_pair(nullptr, -1);
        if(!node->left && !node->right) return make_pair(node, level);
        const auto& left = f(node->left, level + 1);
        const auto& right = f(node->right, level + 1);
        if(left.second == right.second) return make_pair(node, right.second);
        return left.second > right.second ? left : right;
    }
};

int main()
{
}
