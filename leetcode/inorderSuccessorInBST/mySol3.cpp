#include "header.h"

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = nullptr;
        function<void(TreeNode*)> f = [&](TreeNode* node)
        {
            if(!node) return;
            if(node->val > p->val) {
                res = node;
                f(node->left);
            }
            else{
                f(node->right);
            }
        };
        f(root);
        return res;
    }
};

int main()
{
    Solution s;
}