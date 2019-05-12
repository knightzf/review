#include "header.h"

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* pre = nullptr;
        vector<TreeNode*> v;
        function<void(TreeNode*)> inorder = [&](TreeNode* node)
        {
            if(node == nullptr) return;
            inorder(node->left);
            if(pre != nullptr && pre->val > node->val) {
                if(v.empty() || v.back() != pre) v.emplace_back(pre);
                v.emplace_back(node);
            }
            pre = node;
            inorder(node->right);
        };
        inorder(root);
        swap(v.front()->val, v.back()->val);
    }
};



int main()
{
    Solution s;
}