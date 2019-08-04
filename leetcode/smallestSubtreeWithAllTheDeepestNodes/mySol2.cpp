#include "header.h"

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* res = nullptr;
        int curr = 0;
        function<int(TreeNode*, int)> f = [&](TreeNode* node, int depth) {
            if(!node) return depth - 1;
            int left = f(node->left, depth + 1), right = f(node->right, depth + 1);
            int t = max(left, right);
            if(t > curr || (t == curr && left == right)) {
                curr = t;
                res = node;
            }
            return t;
        };
        f(root, 0);
        return res;
    }
};

int main()
{
    Solution s;
}