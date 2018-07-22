#include "header.h"

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return impl(root1) == impl(root2);
    }

    vector<int> impl(TreeNode* node)
    {
        vector<int> res;
        inorder(node, res);
        return res;
    }

    void inorder(TreeNode* node, vector<int>& res)
    {
        if(node == nullptr) return;
        inorder(node->left, res);
        if(!node->left && !node->right) res.push_back(node->val);
        inorder(node->right, res);
    }
};

int main()
{
    Solution s;
}
