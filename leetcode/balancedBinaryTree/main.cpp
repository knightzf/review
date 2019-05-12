#include "header.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return isBalanced(root->left) && isBalanced(root->right) && 
            abs(depth(root->left) - depth(root->right)) <= 1;
    }

    int depth(TreeNode* node)
    {
        if(!node) return 0;
        return 1 + max(depth(node->left), depth(node->right));
    }
};

int main()
{
    Solution s;
}