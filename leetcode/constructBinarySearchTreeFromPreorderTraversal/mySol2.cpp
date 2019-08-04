#include "header.h"

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        auto insert = [](TreeNode* node, int num) {
            TreeNode* pre = nullptr, *t = new TreeNode(num);
            while(node) {
                pre = node;
                if(node->val < num) node = node->right;
                else node = node->left;
            }
            if(pre->val < num) pre->right = t;
            else pre->left = t;
        };
        for(int i = 1, n = preorder.size(); i < n; ++i) {
            insert(root, preorder[i]);
        }
        return root;
    }
};

int main()
{
    Solution s;
}