#include "header.h"

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        function<void(TreeNode*, TreeNode*, int)> dfs = [&](TreeNode* node, TreeNode* parent, int len) {
            if(!node) return;
            if(parent && node->val == parent->val + 1) ++len;
            else len = 1;
            res = max(res, len);
            dfs(node->left, node, len);
            dfs(node->right, node, len);
        };
        dfs(root, nullptr, 1);
        return res;
    }
};

int main()
{
    //Solution s;
}