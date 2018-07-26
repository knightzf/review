#include "header.h"

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1)
        {
            TreeNode* t = new TreeNode(v);
            t->left = root;
            return t;
        }

        inorder(root, v, d, 1);
        return root;
    }

    void inorder(TreeNode* node, int v, int d, int currentD)
    {
        if(node == nullptr) return;

        if(currentD == d - 1)
        {
            TreeNode* newLeft = new TreeNode(v);
            TreeNode* newRight = new TreeNode(v);
            newLeft->left = node->left;
            newRight->right = node->right;
            node->left = newLeft;
            node->right = newRight;
            return;
        }

        inorder(node->left, v, d, currentD + 1);
        inorder(node->right, v, d, currentD + 1);
    }
};

int main() {
    //Solution s;
}
