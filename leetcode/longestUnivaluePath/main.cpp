#include "header.h"

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        impl(root, res);
        return res;
    }

    pair<int, int> impl(TreeNode* node, int& max)
    {
        if(node == nullptr) return {0, 0};
        pair<int, int> res{0, 0};
        if(node->left)
        {
            const auto& left = impl(node->left, max);
            if(node->val == node->left->val) {
                res.first = 1 + std::max(left.first, left.second);
            }
        }
        if(node->right)
        {
            const auto& right = impl(node->right, max);
            if(node->val == node->right->val) {
                res.second = 1 + std::max(right.first, right.second);
            }
        }
        max = std::max(max, res.first + res.second);
        return res;
    }
};

int main() {
    Solution s;
}
