/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* node) {
        if(node == NULL)
            return 0;
        else 
            return max(height(node->left), height(node->right)) + 1;
    }
    
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
            
        if(isBalanced(root->left) && isBalanced(root->right) &&
            abs(height(root->left) - height(root->right)) <= 1
            )
            return true;
        else
            return false;
        
    }
};
