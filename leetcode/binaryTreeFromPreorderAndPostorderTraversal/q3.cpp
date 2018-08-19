#include "header.h"

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        return impl(pre, 0, n - 1, post, 0, n - 1);
    }

    TreeNode* impl(vector<int>& prev, int preStart, int preEnd,
                   vector<int>& post, int posStart, int posEnd)
    {
        if(preStart == preEnd)
        {
            return new TreeNode(prev[preStart]);
        }

        TreeNode* root = new TreeNode(prev[preStart]);
        TreeNode* node = root;
        while(preStart + 1 <= preEnd && prev[preStart + 1] == post[posEnd - 1])
        {
            TreeNode * newNode = new TreeNode(prev[preStart + 1]);
            node->left = newNode;
            node = newNode;
            preStart++;
            posEnd--;
        }

        if(preStart < preEnd)
        {
            int i = preStart + 1;
            while(i <= preEnd && prev[i] != post[posEnd - 1])
            {
                ++i;
            }
            int j = posEnd - 1;
            while(j >= posStart && post[j] != prev[preStart + 1])
            {
                --j;
            }
            node->left = impl(prev, preStart + 1, i - 1, post, posStart, j);
            node->right = impl(prev, i, preEnd, post, j + 1, posEnd - 1);
        }

        return root;
    }
};

int main()
{
    Solution s;

}

