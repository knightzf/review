#include "header.h"

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m{{0, 1}};
        function<int(TreeNode*, int)> f = [&](TreeNode* node, int curr){
            if(!node) return 0;
            curr += node->val;
            int res = 0;
            if(m.count(curr - sum)) {
                res += m[curr - sum];
            }
            ++m[curr];
            res += f(node->left, curr);
            res += f(node->right, curr);
            --m[curr];
            return res;
        };
        return f(root, 0);
    }
};

int main()
{
    //Solution s;
}