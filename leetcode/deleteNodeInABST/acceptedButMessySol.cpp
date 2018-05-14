#include "header.h"

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root && root->val == key && !root->left && !root->right) return nullptr;

        TreeNode* node = root;
        TreeNode* prev = nullptr;
        while(node && node->val != key)
        {
            prev = node;
            if(key < node->val)
                node = node->left;
            else
                node = node->right;
        }

        if(node == nullptr) return root;

        if(!node->left && !node->right)
        {
            bool isleft = prev->left == node;
            if(isleft) prev->left = nullptr;
            else prev->right = nullptr;
        }
        else if(node->left)
        {
            prev = node->left;
            TreeNode* maxNode = node->left;
            while(maxNode && maxNode->right)
            {
                prev = maxNode;
                maxNode = maxNode->right;
            }

            node->val = maxNode->val;
            if(prev == maxNode)
                node->left = maxNode->left;
            else
                prev->right = maxNode->left;

        }
        else if(node->right)
        {
            prev = node->right;
            TreeNode* minNode = node->right;
            while(minNode && minNode->left)
            {
                prev = minNode;
                minNode = minNode->left;
            }

            node->val = minNode->val;
            if(prev == minNode)
                node->right = minNode->right;
            else
                prev->left = minNode->right;
        }

        return root;
    }
};

int main()
{
    //Solution s;
}
