/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//The difference from v1 is we store the values for each node
//which sped up the run time and passed leetcode judging

class Solution {
public:
    std::map<TreeNode*, int> valueWithMap;
    std::map<TreeNode*, int> valueWithoutMap;
    
    int findMaxWithItself(TreeNode* node)
    {
        if(node == NULL)
        {
            return 0;
        }
        
        if(valueWithMap.find(node) != valueWithMap.end())
        {
            return valueWithMap[node];
        }
        else
        {
            int val = findMaxWithOutItself(node->left) + findMaxWithOutItself(node->right) + node->val;
            valueWithMap[node] = val;
            return val;
        }
    }
    
    int findMaxWithOutItself(TreeNode* node)
    {
        if(node == NULL)
        {
            return 0;
        }
        
        if(valueWithoutMap.find(node) != valueWithoutMap.end())
        {
            return valueWithoutMap[node];
        }
        else
        {
            int val = max(findMaxWithOutItself(node->left), findMaxWithItself(node->left)) + 
                max(findMaxWithOutItself(node->right), findMaxWithItself(node->right));
            valueWithoutMap[node] = val;    
            return val;
        }
    }
    
    int rob(TreeNode* root) {
        int maxWithItself = findMaxWithItself(root);
        int maxWithoutItself = findMaxWithOutItself(root);
        
        return std::max(maxWithItself,maxWithoutItself);
    }
};