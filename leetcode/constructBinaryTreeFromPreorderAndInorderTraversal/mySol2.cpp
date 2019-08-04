#include "header.h"

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        function<TreeNode*(int, int, int, int)> f = [&](int i, int j, int x, int y) {
            if(i == j) return (TreeNode*)0;
            TreeNode* node = new TreeNode(pre[i]);
            if(i + 1 == j) return node;
            if(pre[i] == post[y - 1]) {
                int t = pre[i + 1];
                int k = x;
                while(k < y && post[k] != t) ++k;
                int len = k - x + 1;
                node->left = f(i + 1, i + 1 + len, x, x + len);
                node->right = f(i + 1 + len, j, x + len, y - 1);
            } else {
                node->left = f(i + 1, j, x + 1, y);
            }
            return node;
        };
        return f(0, n, 0, n);
    }
};


int main()
{
    Solution s;
}