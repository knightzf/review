#include "header.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        function<TreeNode*(int, int)> f = [&](int startIdx, int endIdx)
        {
            if(startIdx >= endIdx) return (TreeNode*)0;
            int midIdx = (startIdx + endIdx) / 2;
            TreeNode* node = new TreeNode(nums[midIdx]);
            node->left = f(startIdx, midIdx);
            node->right = f(midIdx + 1, endIdx);
            return node;
        };
        return f(0, n);
    }
};

int main()
{
    Solution s;
}