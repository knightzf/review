#include "header.h"

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        double diff = fabs(root->val - target);
        function<void(TreeNode*)> preorder = [&](TreeNode* node)
        {
            if(!node) return;
            double t = fabs(node->val - target);
            if(t <= diff) {
                diff = t;
                res = node->val;
            }
            if(node->val > target) preorder(node->left);
            else preorder(node->right);            
        };
        preorder(root);
        return res;
    }
};

int main()
{
    //Solution s;
}