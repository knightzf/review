#include "header.h"

class Solution {
private:
    unordered_map<TreeNode*, int> m;
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        impl(root, 0);
        while(root)
        {
            if(!root->left && !root->right) return root;
            if(root->left && !root->right)
            {
                root = root->left;
            }
            else if(!root->left && root->right)
            {
                root = root->right;
            }
            else
            {
                if(m[root->left] == m[root->right])
                    return root;
                if(m[root->left] > m[root->right])
                {
                    root = root->left;
                }
                else
                {
                    root = root->right;
                }
            }
        }
    }

    void impl(TreeNode* node, int depth)
    {
        if(!node->left && !node->right)
        {
            m[node] = depth;
            return;
        }

        if(node->left && !node->right)
        {
            impl(node->left, depth + 1);
            m[node] = m[node->left] + 1;
            return;
        }

        if(!node->left && node->right)
        {
            impl(node->right, depth + 1);
            m[node] = m[node->right] + 1;
            return;
        }

        impl(node->left, depth + 1);
        impl(node->right, depth + 1);
        m[node] = max(m[node->left], m[node->right]) + 1;
    }
};

int main()
{
    Solution s;
}
