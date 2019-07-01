#include "header.h"

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, multimap<int, int>> m;
        function<void(TreeNode*, int, int)> f = [&](TreeNode* node, int col, int row)
        {
            if(!node) return;
            m[col].emplace(row, node->val);
            f(node->left, col - 1, row + 1);
            f(node->right, col + 1, row + 1);
        };
        f(root, 0, 0);
        vector<vector<int>> res;
        for(auto& p : m) {
            res.emplace_back(vector<int>{});
            for(auto& t : p.second) res.back().emplace_back(t.second);
        }
        return res;
    }
};

int main()
{
    //Solution s;
}