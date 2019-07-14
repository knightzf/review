#include "header.h"

class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, vector<int>> m{{nullptr, vector<int>{0, 0}}};
        vector<vector<TreeNode*>> v;
        function<void(TreeNode*, int)> bfs = [&](TreeNode* node, int level) {
            if(!node) return;
            if(v.size() == level) v.emplace_back(vector<TreeNode*>{node});
            else v[level].emplace_back(node);
            bfs(node->left, level + 1);
            bfs(node->right, level + 1);
        };
        bfs(root, 0);
        for(int i = v.size() - 1; i >= 0; --i) {
            for(auto* node : v[i]) {
                m[node].emplace_back(node->val + m[node->left][1] + m[node->right][1]);
                m[node].emplace_back(max(m[node->left][0], m[node->left][1]) +
                             max(m[node->right][0], m[node->right][1]));
            }
        }
        return max(m[root][0], m[root][1]);
    }
};

int main()
{
    Solution s;
}