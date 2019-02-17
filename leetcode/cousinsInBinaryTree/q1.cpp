#include "header.h"

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, pair<int, TreeNode*>> m;

        function<void(TreeNode*, TreeNode*, int)> f = [&](TreeNode* parent, TreeNode* node, int depth)
        {
            if(node == nullptr) return;
            m[node->val] = make_pair(depth, parent);

            f(node, node->left, depth + 1);
            f(node, node->right, depth + 1);
        };

        f(nullptr, root, 0);

        const auto& p = m[x];
        const auto& q = m[y];
        return p.first == q.first && p.second != q.second;
    }
};

int main()
{
    Solution s;
}
