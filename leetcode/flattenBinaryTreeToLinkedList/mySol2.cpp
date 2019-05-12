#include "header.h"

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        function<void(TreeNode*)> preorder = [&](TreeNode* node)
        {
            if(!node) return;
            if(prev) { prev->left = nullptr; prev->right = node; }
            prev = node;
            TreeNode* left = node->left, *right = node->right;
            preorder(left);            
            preorder(right);
        };
        preorder(root);
    }
};

int main()
{
    Solution s;
    
}