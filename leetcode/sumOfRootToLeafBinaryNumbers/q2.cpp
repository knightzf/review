#include "header.h"

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        long res = 0;
        int mod = 1e9 + 7;

        function<void(TreeNode*, long)> impl = [&](TreeNode* node, long val)
        {
            if(node == nullptr) return;
            val = (val * 2 + node->val) % mod;
            impl(node->left, val);
            impl(node->right, val);
            if(!node->left && !node->right) {
                res += val;
                res %= mod;
            }
        };

        impl(root, 0);
        return res;
    }
};

int main()
{
    Solution s;
}
