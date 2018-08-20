#include "header.h"

class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> m;
        int sum = inorder(root, m);
        --m[sum];
        return ((sum & 1) == 0 && m[sum / 2] > 0);
    }

    int inorder(TreeNode* node, unordered_map<int, int>& m)
    {
        if(node == nullptr) {
            return 0;
        }

        int res = node->val + inorder(node->left, m) + inorder(node->right, m);
        ++m[res];
        return res;
    }
};

int main() {
    Solution s;
}
