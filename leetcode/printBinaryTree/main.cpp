#include "header.h"

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int depth = 0;
        inorder(root, depth, 1);

        int n = (2 << depth - 1) - 1;
        vector<vector<string>> res(depth, vector<string>(n));

        print(res, root, 0, 0, n - 1);
        return res;
    }

    void print(vector<vector<string>>& res, TreeNode* node, int depth, int startIdx, int endIdx)
    {
        if(node == nullptr) return;
        int midIdx = (startIdx + endIdx) / 2;
        res[depth][midIdx] = to_string(node->val);
        print(res, node->left, depth + 1, startIdx, midIdx - 1);
        print(res, node->right, depth + 1, midIdx + 1, endIdx);
    }

    void inorder(TreeNode* node, int& depth, int d)
    {
        if(node == nullptr) return;

        depth = max(depth, d);
        inorder(node->left, depth, d + 1);
        inorder(node->right, depth, d + 1);
    }
};

int main() {
    Solution s;
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    a->left = b;
    s.printTree(a);
}
