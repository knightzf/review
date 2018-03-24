#include "main.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isEachNodeValid(root) && isEachTreeValid(root);
    }

    bool isEachNodeValid(TreeNode* root)
    {
        if(root == nullptr || (!root->left && !root->right)) return true;
        return (root->left ? root->left->val < root->val : true) &&
            (root->right ? root->val < root->right->val : true)
            && isEachNodeValid(root->left) && isEachNodeValid(root->right);
    }

    bool isEachTreeValid(TreeNode* root)
    {
        if(root == nullptr || (!root->left && !root->right)) return true;
        if(root->left)
        {
            auto* p = root->left;
            while(p->right)
            {
                p = p->right;
            }
            if(root->val <= p->val) return false;
        }
        if(root->right)
        {
            auto* p = root->right;
            while(p->left)
            {
                p = p->left;
            }
            if(root->val >= p->val) return false;
        }
        return isEachTreeValid(root->left) && isEachTreeValid(root->right);
    }
};

int main()
{
    Solution s;
}
