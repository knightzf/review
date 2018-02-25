#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if(n == 0) return 0;

        vector<long> sum(n + 1, 0);
        for(int i = 0; i < n; ++i)
        {
            sum[i + 1] = sum[i] + nums[i];
        }

        int res = 0;
        mergesortWithCount(sum, 0, n, lower, upper, res);

        return res;
    }

    void mergesortWithCount(vector<long>& sum, int startIdx, int endIdx, int lower, int upper, int& res)
    {
        if(startIdx == endIdx) return;

        int midIdx = (startIdx + endIdx) / 2;
        mergesortWithCount(sum, startIdx, midIdx, lower, upper, res);
        mergesortWithCount(sum, midIdx + 1, endIdx, lower, upper, res);

        vector<int> temp(endIdx - startIdx + 1);

        int i = startIdx, r = 0;
        int j = midIdx + 1, k = midIdx + 1, t = midIdx + 1;
        for (; i <= midIdx; ++i, ++r) {
            while (k <= endIdx && sum[k] - sum[i] < lower) k++;
            while (j <= endIdx && sum[j] - sum[i] <= upper) j++;
            while (t <= endIdx && sum[t] < sum[i]) temp[r++] = sum[t++];
            temp[r] = sum[i];
            res += j - k;
        }

        for(int i = 0; i < t - startIdx; ++i)
        {
            sum[startIdx + i] = temp[i];
        }
    }
};



int main() {
    Solution s;
    {
        vector<int> a{0, 0};
        std::cout<<s.countRangeSum(a, 0, 0)<<std::endl;
    }
    //if(0)
    {
        vector<int> a{-2, 5, -1};
        std::cout<<s.countRangeSum(a, -2, 2)<<std::endl;
    }
    //if(0)
    {
        vector<int> a{-1, 1};
        std::cout<<s.countRangeSum(a, 0, 0)<<std::endl;
    }
    {
        vector<int> a{2147483647,-2147483648,-1,0};
        std::cout<<s.countRangeSum(a, -1, 0)<<std::endl;
    }

}
