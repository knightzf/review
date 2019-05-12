#include "header.h"

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int res = INT_MAX;
        if(root->left) res = minDepth(root->left);
        if(root->right) res = min(res, minDepth(root->right));
        return res + 1;
    }
};


int main()
{
    Solution s;
    
}