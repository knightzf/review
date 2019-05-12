#include "header.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        if(isValidBST(root->left) && isValidBST(root->right)) {
            if((!root->left || getValue(root->left, false) < root->val) &&
               (!root->right || getValue(root->right, true) > root->val)) return true;
        }
        return false;
    }

    int getValue(TreeNode* node, bool left) {
        if(left) while(node->left) node = node->left;
        else while(node->right) node = node->right; 
        return node->val;
    }
};


int main()
{
    Solution s;
}