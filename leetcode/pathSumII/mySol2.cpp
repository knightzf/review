#include "header.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> v;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int curr)
        {
            if(!node) return;
            v.push_back(node->val);            
            curr += node->val;
            if(curr == sum && !node->left && !node->right) res.push_back(v);
            dfs(node->left, curr);
            dfs(node->right, curr);
            v.pop_back();
        };
        dfs(root, 0);
        return res;
    }
};

int main()
{
    Solution s;
    
}