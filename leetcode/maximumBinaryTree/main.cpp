#include "header.h"

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> s;
        for(int num : nums) {
            TreeNode* node = new TreeNode(num);
            while(!s.empty() && s.back()->val < num) {
                node->left = s.back();
                s.pop_back();
            }
            if(!s.empty() && s.back()->val > num) s.back()->right = node;
            s.push_back(node);
        }
        return s.front();
    }
};


int main()
{
    //Solution s;
}