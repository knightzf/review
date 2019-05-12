#include "header.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int res = 0;
        function<void(TreeNode*, int)> preorder = [&](TreeNode* node, int depth)
        {
            if(!node) return;
            res = max(res, depth);
            preorder(node->left, depth + 1);
            preorder(node->right, depth + 1);
        };
        preorder(root, 1);
        return res;
    }
};

int main()
{
    Solution s;
}