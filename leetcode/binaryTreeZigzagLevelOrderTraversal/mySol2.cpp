#include "header.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        function<void(TreeNode*, int)> preorder = [&](TreeNode* node, int depth)
        {
            if(!node) return;
            if(res.size() == depth) res.emplace_back(vector<int>{});
            res[depth].emplace_back(node->val);
            preorder(node->left, depth + 1);
            preorder(node->right, depth + 1);
        };
        preorder(root, 0);
        
        for(int i = 0; i < res.size(); ++i) {
            if(i & 1) reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};

int main()
{
    Solution s;
}