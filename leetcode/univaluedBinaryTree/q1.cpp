#include "header.h"

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        int val = -1;

        function<bool(TreeNode*)> inorder = [&](TreeNode* node)
        {
            if(node == nullptr) return true;

            if(val == -1) val = node->val;
            else if(node->val != val) return false;

            return inorder(node->left) && inorder(node->right);
        };

        return inorder(root);
    }
};

int main()
{
    Solution s;
}
