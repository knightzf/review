#include "header.h"

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        function<void(TreeNode*, int)> f = [&](TreeNode* node, int depth)
        {
            if(node == nullptr) return;
            if(res.size() == depth) res.emplace_back(vector<int>());
            f(node->left, depth + 1);
            f(node->right, depth + 1);
            res[depth].emplace_back(node->val);
        };
        f(root, 0);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution s;
}