#include "header.h"

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int prev = 0;
        function<void(TreeNode*)> postOrder = [&](TreeNode* node)
        {
            if(node == nullptr) return;
            postOrder(node->right);
            node->val += prev;
            prev = node->val;
            postOrder(node->left);
        };
        postOrder(root);
        return root;
    }
};

int main()
{
    Solution s;
}
