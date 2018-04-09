#include "header.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        unordered_map<TreeNode*, int> m;
        impl(root, res, m);
        return res > 0 ? res - 1 : res;
    }

    void impl(TreeNode* node, int& res, unordered_map<TreeNode*, int>& m)
    {
        if(node == nullptr) return;
        impl(node->left, res, m);
        impl(node->right, res, m);
        int t = longestPath(node->left, m) + longestPath(node->right, m) + 1;
        res = max(res, t);
    }

    int longestPath(TreeNode* node, unordered_map<TreeNode*, int>& m)
    {
        if(node == nullptr) return 0;
        if(node->left == nullptr && node->right == nullptr) return 1;
        if(m.find(node) == m.end())
            m[node] = max(longestPath(node->left, m), longestPath(node->right, m)) + 1;
        return m[node];
    }
};

int main()
{
    Solution s;
}
