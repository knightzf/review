#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    using Map = std::map<int, std::vector<pair<int, int>>>;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        Map m;
        impl(root, m, 0, 0);

        vector<vector<int>> res;
        std::for_each(m.begin(), m.end(), [&](Map::value_type& p){
                      std::sort(p.second.begin(), p.second.end(),
                                [](const std::pair<int, int>& a, const std::pair<int, int>& b){
                                    return a.first < b.first;
                                });
                       vector<int> t;
                       for_each(p.second.begin(), p.second.end(), [&](const std::pair<int, int>& b){
                                t.push_back(b.second);
                                });
                        res.emplace_back(t);
                      });
        return res;
    }

    void impl(TreeNode* node, Map& m, int idx, int depth)
    {
        if(node == nullptr) return;
        impl(node->left, m, idx - 1, depth + 1);
        m[idx].push_back(std::make_pair(depth, node->val));
        impl(node->right, m, idx + 1, depth + 1);
    }
};

int main()
{
    Solution s;
}
