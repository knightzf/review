#include "header.h"

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> m;
        impl(root, m);
        map<int, vector<int>> cm;
        for(const auto& p : m)
            cm[p.second].push_back(p.first);
        if(!cm.empty())
            return cm.rbegin()->second;
        return {};
    }

    int impl(TreeNode* node, unordered_map<int, int>& m)
    {
        if(node == nullptr) return 0;
        int sum = node->val;
        if(node->left) sum += impl(node->left, m);
        if(node->right) sum += impl(node->right, m);
        ++m[sum];
        return sum;
    }
};

int main()
{
    Solution s;
}
