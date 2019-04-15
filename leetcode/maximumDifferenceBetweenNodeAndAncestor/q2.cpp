#include "header.h"

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        function<void(TreeNode*, int, int)> f = [&](TreeNode* node, int a, int b)
        {
            if(node == nullptr) return;

            res = max(max(res, abs(node->val - a)), abs(node->val - b));

            a = min(a, node->val);
            b = max(b, node->val);

            f(node->left, a, b);
            f(node->right, a, b);
        };
        f(root, root->val, root->val);
        return res;
    }
};

int main()
{
    Solution s;
}
