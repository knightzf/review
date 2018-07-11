#include "header.h"

class Solution {
private:
    int res;
public:
    int findTilt(TreeNode* root) {
        res = 0;
        impl(root);
        return res;
    }

    int impl(TreeNode* node)
    {
        if(node == nullptr) return 0;
        int a = impl(node->left);
        int b = impl(node->right);
        res += abs(a - b);
        return a + b + node->val;
    }
};

int main()
{
    Solution s;
}
