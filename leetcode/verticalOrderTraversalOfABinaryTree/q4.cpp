#include "header.h"

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<int>>> m;
        function<void(TreeNode*, int, int)> f = [&](TreeNode* node, int x, int y)
        {
            if(node == nullptr) return;
            m[x][y].insert(node->val);

            f(node->left, x - 1, y + 1);
            f(node->right, x + 1, y + 1);
        };

        f(root, 0, 0);
        vector<vector<int>> res(m.size());
        int i = 0;
        for(auto& p : m)
        {
            for(auto& q : p.second)
            {
                for(int k : q.second)
                {
                    res[i].push_back(k);
                }
            }
            ++i;
        }
        return res;
    }
};

int main()
{
    Solution s;
}
