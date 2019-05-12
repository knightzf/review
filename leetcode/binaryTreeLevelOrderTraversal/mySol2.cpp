#include "header.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int, vector<int>> v;
        function<void(TreeNode*, int)> inorder = [&](TreeNode* node, int depth)
        {
            if(!node) return;
            inorder(node->left, depth + 1);
            v[depth].emplace_back(node->val);
            inorder(node->right, depth + 1);
        };
        inorder(root, 0);
        vector<vector<int>> res;
        for_each(v.begin(), v.end(), [&](const auto& p){res.emplace_back(p.second);});
        return res;
    }
};

int main()
{
    Solution s;
}