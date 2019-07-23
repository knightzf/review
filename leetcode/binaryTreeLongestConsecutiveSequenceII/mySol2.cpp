#include "header.h"

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> m;
        int res = 0;
        function<void(TreeNode*)> f = [&](TreeNode* node) {
            if(!node) return;
            if(m.count(node)) return;
            f(node->left);
            f(node->right);
            m[node] = make_pair(1, 1);
            if(node->left) {
                if(node->left->val == node->val + 1) {
                    m[node].first = max(m[node].first, m[node->left].first + 1);
                }else if(node->left->val == node->val - 1) {
                    m[node].second = max(m[node].second, m[node->left].second + 1);
                }
            }
            if(node->right) {
                if(node->right->val == node->val + 1) {
                    m[node].first = max(m[node].first, m[node->right].first + 1);
                }else if(node->right->val == node->val - 1) {
                    m[node].second = max(m[node].second, m[node->right].second + 1);
                }
            }
            res = max(res, m[node].first + m[node].second - 1);
        };
        f(root);
        return res;
    }
};

int main()
{
    //Solution s;
}