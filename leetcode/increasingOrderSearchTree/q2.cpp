#include "header.h"

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root, v);
        for(int i = 0, n = v.size(); i < n; ++i)
        {
            v[i]->left = nullptr;
            if(i != n - 1)
            {
                v[i]->right = v[i + 1];
            }
            else
            {
                v[i]->right = nullptr;
            }
        }
        return v[0];
    }

    void inorder(TreeNode* node, vector<TreeNode*>& v)
    {
        if(node == nullptr) return;

        inorder(node->left, v);
        v.push_back(node);
        inorder(node->right, v);
    }
};

int main()
{
    Solution s;
}
