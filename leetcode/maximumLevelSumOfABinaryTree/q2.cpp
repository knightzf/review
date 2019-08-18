#include "header.h"

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> sum;
        function<void(TreeNode* node, int)> preorder = [&](TreeNode* node, int level) {
            if(!node) return;
            if(sum.size() == level) sum.push_back(0);
            sum[level] += node->val;
            preorder(node->left, level + 1);
            preorder(node->right, level + 1);
        };
        preorder(root, 0);
        int res = 0;
        for(int i = 1, n = sum.size(); i < n; ++i) {
            if(sum[i] > sum[res]) res = i;
        }
        return res + 1;
    }
};

int main()
{
    Solution s;
}
