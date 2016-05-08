class Solution {
public:

    int findMaxWithItself(TreeNode* node)
    {
        if(node == NULL)
        {
            return 0;
        }
        
        return findMaxWithOutItself(node->left) + findMaxWithOutItself(node->right) + node->val;
    }
    
    int findMaxWithOutItself(TreeNode* node)
    {
        if(node == NULL)
        {
            return 0;
        }
        
        return max(findMaxWithOutItself(node->left), findMaxWithItself(node->left)) + 
            max(findMaxWithOutItself(node->right), findMaxWithItself(node->right));
    }
    
    int rob(TreeNode* root) {
        int maxWithItself = findMaxWithItself(root);
        int maxWithoutItself = findMaxWithOutItself(root);
        
        return std::max(maxWithItself,maxWithoutItself);
    }
};