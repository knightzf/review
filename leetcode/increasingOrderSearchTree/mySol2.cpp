#include "header.h"

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> v;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if(!node) return;
            inorder(node->left);
            v.push_back(node);
            inorder(node->right);
        };
        inorder(root);
        for(int i = 0, n = v.size(); i < n; ++i) {
            v[i]->left = nullptr;
            v[i]->right = i == n - 1 ?  nullptr : v[i + 1];
        }
        return v[0];
    }
};


int main()
{
    Solution s;
}