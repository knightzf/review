#include "header.h"

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = -1;
        int value = 0;
        inorder(root, maxDepth, value, 0);
        return value;
    }

    void inorder(TreeNode* node, int& maxDepth, int& value, int currDepth)
    {
        if(node == nullptr) return;

        inorder(node->left, maxDepth, value, currDepth + 1);

        if(currDepth > maxDepth)
        {
            maxDepth = currDepth;
            value = node->val;
        }

        inorder(node->right, maxDepth, value, currDepth + 1);
    }
};

int main()
{
    Solution s;
}
