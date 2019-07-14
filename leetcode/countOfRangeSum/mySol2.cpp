#include "header.h"

struct RangeNode
{
    RangeNode* left;
    RangeNode* right;
    long val;
    int cnt;
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int res = 0;
        RangeNode* root = new RangeNode{nullptr, nullptr, 0, 1};
        for(long i = 0, n = nums.size(), sum = 0; i < n; ++i) {
            auto f = [&](long x) {
                RangeNode* node = root;
                int res = 0;
                while(node) {
                    if(node->val <= x) {
                        res += node->cnt;
                        node = node->right;
                    }
                    else {
                        node = node->left;
                    }
                }
                return res;
            };

            sum += nums[i];
            long left = sum - upper, right = sum - lower;\
            res += f(right) - f(left - 1);

            RangeNode* node = root;
            while(true) {
                if(sum <= node->val) {
                    ++node->cnt;
                    if(node->left) node = node->left;
                    else {
                        node->left = new RangeNode{nullptr, nullptr, sum, 1};
                        break;
                    }
                } else {
                    if(node->right) node = node->right;
                    else {
                        node->right = new RangeNode{nullptr, nullptr, sum, 1};
                        break;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{-2, 5, -1};
    cout<<s.countRangeSum(a, -2, 2)<<endl;
}