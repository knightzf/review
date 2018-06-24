#include "header.h"

class Solution {
private:
    bool visited;
    int prev;
public:
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        visited = false;
        prev = 0;
        inorder(root, res);
        return res;
    }

    void inorder(TreeNode* node, int& res)
    {
        if(node == nullptr) return;

        inorder(node->left, res);

        if(!visited)
        {
            visited = true;
        }
        else
        {
            res = min(res, abs(prev - node->val));
        }

        prev = node->val;

        inorder(node->right, res);
    }
};

int main()
{
    Solution s;
}
