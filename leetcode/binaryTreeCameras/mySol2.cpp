#include "header.h"

class Solution {
private:
    int cnt = 0;
public:
    int minCameraCover(TreeNode* root) {
        int r = dfs(root);
        return r == 0 ? 1 : 0 + cnt;
    }

    // 0 means leaf and not covered
    // 1 with parent of leaf with camera
    // 2 with covered
    int dfs(TreeNode* node) {
        if(!node) return 2;
        int left = dfs(node->left), right = dfs(node->right);
        if(left == 0 || right == 0) {
            ++cnt;
            return 1;
        }
        return left == 1 || right == 1 ? 2 : 0;
    }
};

int main()
{
    Solution s;
}