#include "header.h"

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            TreeNode* minNode = findMin(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }

    TreeNode* findMin(TreeNode* node) {
        while(node->left) node = node->left;
        return node;
    }
};

int main()
{
    //Solution s;
}