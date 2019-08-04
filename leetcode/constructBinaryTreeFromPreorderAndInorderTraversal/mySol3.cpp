#include "header.h"

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        vector<TreeNode*> v{new TreeNode(pre[0])};
        for(int i = 1, j = 0; i < n; ++i) {
            TreeNode* node = new TreeNode(pre[i]);
            while(v.back()->val == post[j])
                v.pop_back(), ++j;
            if(!v.back()->left) v.back()->left = node;
            else v.back()->right = node;
            v.push_back(node);
        }
        return v[0];
    }
};


int main()
{
    Solution s;
}