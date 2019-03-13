#include "header.h"

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return impl(preorder, 0, n);
    }

    TreeNode* impl(vector<int>& preorder, int startIdx, int endIdx)
    {
        if(startIdx == endIdx) return nullptr;
        TreeNode* n = new TreeNode(preorder[startIdx]);
        int i = startIdx + 1;
        for(; i < endIdx; ++i)
        {
            if(preorder[i] > preorder[startIdx]) break;
        }
        n->left = impl(preorder, startIdx + 1, i);
        n->right = impl(preorder, i, endIdx);
        return n;
    }
};

int main()
{
    Solution s;
}
