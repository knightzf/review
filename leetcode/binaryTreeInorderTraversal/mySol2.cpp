#include "header.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        while(root) {
            s.push(root);
            root = root->left;
        }

        vector<int> res;
        while(!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            res.emplace_back(node->val);
            if(node->right)
            {
                TreeNode* t = node->right;
                while(t) {
                    s.push(t);
                    t = t->left;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}