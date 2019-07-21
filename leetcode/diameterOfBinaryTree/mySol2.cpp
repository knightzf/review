#include "header.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        int res = 0;
        function<int(TreeNode*)> f = [&](TreeNode* node) {
            if(!node) return 0;
            if(!node->left && !node->right) return 1;
            int left = f(node->left);
            int right = f(node->right);
            res = max(res, left + right);
            return max(left, right) + 1;
        };
        f(root);
        return res;
    }
};

int main()
{
    //Solution s;
}