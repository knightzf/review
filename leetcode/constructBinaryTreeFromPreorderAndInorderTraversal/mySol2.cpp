#include "header.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        function<TreeNode*(int, int, int, int)> f = [&](int preStart, int preEnd, int inStart, int inEnd)
        {
            if(preStart == preEnd) return static_cast<TreeNode*>(nullptr);
            TreeNode* node = new TreeNode(preorder[preStart]);
            for(int i = inStart; i < inEnd; ++i)
            {
                if(preorder[preStart] == inorder[i])
                {
                    node->left = f(preStart + 1, preStart + 1 + i - inStart, inStart, i);
                    node->right = f(preStart + 1 + i - inStart, preEnd, i + 1, inEnd);
                    break;
                }
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