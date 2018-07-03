#include "header.h"

class Solution {
private:
    unordered_map<TreeNode*, pair<int, int>> m;
public:
    int longestConsecutive(TreeNode* root) {
        m.clear();
        int res = 0;
        impl(root, res);
        return res;
    }

    void impl(TreeNode* node, int& res)
    {
        if(node == nullptr) return;
        if(m.count(node)) return;

        int des = 0;
        int asc = 0;

        if(node->left)
        {
            if(node->val == node->left->val + 1)
            {
                impl(node->left, res);
                des = m[node->left].second;
            }
            else if(node->val == node->left->val - 1)
            {
                impl(node->left, res);
                asc = m[node->left].first;
            }
        }

        if(node->right)
        {
            if(node->val == node->right->val + 1)
            {
                impl(node->right, res);
                des = max(des, m[node->right].second);
            }
            else if(node->val == node->right->val - 1)
            {
                impl(node->right, res);
                asc = max(asc, m[node->right].first);
            }
        }

        res = max(res, 1 + des + asc);
        m[node] = {1 + asc, 1 + des};

        impl(node->left, res);
        impl(node->right, res);
    }
};

int main()
{
    Solution s;
}
