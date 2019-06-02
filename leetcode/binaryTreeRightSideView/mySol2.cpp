#include "header.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode*, int)> preorder = [&](TreeNode* node, int level) {
            if(!node) return;
            if(level == res.size()) res.push_back(0);
            res[level] = node->val;
            preorder(node->left, level + 1);
            preorder(node->right, level + 1);
        };
        preorder(root, 0);
        return res;
    }
};

int main()
{
    Solution s;
}