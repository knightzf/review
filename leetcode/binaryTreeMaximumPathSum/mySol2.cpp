#include "header.h"

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int res = root->val;
        function<int(TreeNode*)> inorder = [&](TreeNode* node)
        {
            if(!node) return 0;
            int leftMax = inorder(node->left);
            int rightMax = inorder(node->right);
            int sum = node->val;
            if(leftMax > 0) sum += leftMax;
            if(rightMax > 0) sum += rightMax;
            res = max(res, sum);
            return sum;
        };
        inorder(root);
        return res;
    }
};

int main()
{
    Solution s;
    
}