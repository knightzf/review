#include "header.h"

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;

        function<void(TreeNode*, const string&)> dfs = [&](TreeNode* node, const string& s) {
            if(!node) return;
            string t = s + (s.empty() ? "" : "->") + to_string(node->val);
            if(!node->left && !node->right) {
                res.emplace_back(t);
                return;
            }
            dfs(node->left, t);
            dfs(node->right, t);
        };

        dfs(root, "");
        return res;
    }
};

int main()
{
    //Solution s;
}