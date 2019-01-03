#include "header.h"

class Solution {
public:
    map<pair<TreeNode*, int>, pair<int, int>> m;
    int minCameraCover(TreeNode* root) {
        m.clear();
        const auto& r = impl(root, 0);
        return r.first;
    }

    pair<int, int> impl(TreeNode* node, int pVal)
    {
        if(node == nullptr) return {0, 0};
        const auto& p = make_pair(node, pVal);
        if(m.count(p)) return m[p];

        pair<int, int> res = {1000, 0};

        {
            const auto& leftRes = impl(node->left, 1);
            const auto& rightRes = impl(node->right, 1);

            int t = leftRes.first + rightRes.first + 1;
            if(t < res.first)
            {
                res.first = t;
                res.second = 1;
            }
        }

        {
            const auto& leftRes = impl(node->left, 0);
            const auto& rightRes = impl(node->right, 0);

            int t = leftRes.first + rightRes.first;

            bool needSet = pVal == 0 && leftRes.second == 0 && rightRes.second == 0;

            if(t < res.first)
            {
                res.first = t + (needSet ? 1 : 0);
                res.second = (needSet ? 1 : 0);
            }
        }
        
        m[p] = res;

        return res;
    }
};
int main()
{
    Solution s;
}
