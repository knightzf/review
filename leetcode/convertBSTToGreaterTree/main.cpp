#include "header.h"

class Solution {
private:
    int sum;
public:
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        posorder(root);
        return root;
    }

    void posorder(TreeNode* node)
    {
        if(node == nullptr) return;
        posorder(node->right);
        sum += node->val;
        node->val = sum;
        posorder(node->left);
    }
};

int main()
{
    Solution s;
}
