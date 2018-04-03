#include "header.h"

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p->right)
        {
            p = p->right;
            while(p->left) p = p->left;
            return p;
        }

        stack<TreeNode*> v;
        TreeNode* node = root;
        while(node != p)
        {
            v.push(node);
            if(p->val < node->val)
                node = node->left;
            else
                node = node->right;
        }

        while(!v.empty())
        {
            if(v.top()->left == p)
            {
                return v.top();
            }
            else
            {
                p = v.top();
                v.pop();
            }
        }

        return nullptr;
    }
};

int main()
{
    Solution s;
}
