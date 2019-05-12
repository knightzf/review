#include "header.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        function<TreeNode*(int, int, int, int)> f = [&](int posStart, int posEnd, int inStart, int inEnd)
        {
            if(posStart == posEnd) return static_cast<TreeNode*>(nullptr);
            TreeNode* node = new TreeNode(postorder[posEnd - 1]);
            for(int i = inStart; i < inEnd; ++i)
            {
                if(node->val == inorder[i])
                {
                    node->left = f(posStart, posStart + i - inStart, inStart, i);
                    node->right = f(posStart + i - inStart, posEnd - 1, i + 1, inEnd);
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