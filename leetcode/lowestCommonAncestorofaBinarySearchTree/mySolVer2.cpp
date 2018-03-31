#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;

        if(root == p || root == q) return root;

        auto* c1 = lowestCommonAncestor(root->left, p, q);
        auto* c2 = lowestCommonAncestor(root->right, p, q);

        if(c1 && c2) return root;
        if(c1) return c1;
        if(c2) return c2;
        return nullptr;
    }
};

int main()
{
    Solution s;
}
