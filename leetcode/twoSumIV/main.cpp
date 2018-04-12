#include "header.h"

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        return impl(root, root, k);
    }

    bool impl(TreeNode* node, TreeNode* root, int k)
    {
        if(node == nullptr) return false;
        if(impl(node->left, root, k)) return true;
        if(node->val * 2 != k)
        {
            if(binarySearh(k - node->val, root)) return true;
        }
        if(impl(node->right, root, k)) return true;
        return false;
    }

    bool binarySearh(int k , TreeNode* root)
    {
        while(root)
        {
            if(k < root->val) root = root->left;
            else if(k > root->val) root = root->right;
            else return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
}
