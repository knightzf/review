#include "header.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return isSameTree(root->left, root->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p && q) return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return p == nullptr && q == nullptr;
    }
};

int main()
{
    Solution s;
}