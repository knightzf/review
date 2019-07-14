#include "header.h"

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> sum(n + 1, 0);
        for(int i = 0; i < n; ++i) sum[i + 1] = sum[i] + nums[i];

        function<int(int, int)> mergeSort = [&](int i, int j) {
            if(j - i <= 1) return 0;
            int m = (i + j) / 2;
            int res = mergeSort(i, m) + mergeSort(m, j);
            for(int k = i, p = m, q = m; k < m; ++k) {
                while(p < j && sum[p] - sum[k] < lower) ++p;
                while(q < j && sum[q] - sum[k] <= upper) ++q;
                res += q - p;
            }
            inplace_merge(sum.begin() + i, sum.begin() + m, sum.begin() + j);
            return res;
        };
        return mergeSort(0, n + 1);
    }
};

int main()
{
    Solution s;
    vector<int> a{-2, 5, -1};
    cout<<s.countRangeSum(a, -2, 2)<<endl;
}