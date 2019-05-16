#include "header.h"

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        function<void(TreeNode*, int)> inorder = [&](TreeNode* node, int sum) {
            if(node == nullptr) return;
            sum += node->val;
            if(!node->left && !node->right) res += sum;
            else {
                inorder(node->left, sum * 10);
                inorder(node->right, sum * 10);
            }
        };
        inorder(root, 0);
        return res;
    }
};


int main()
{
    Solution s;
    
}