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
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> sumIdxMap;
        sumIdxMap[0] = 0;
        vector<int> sum(n + 1, 0);

        for(int i = 0; i < n; ++i)
        {
            sum[i + 1] = sum[i] + nums[i];
            sumIdxMap[sum[i + 1]] = i + 1;
        }

        /*for(int i : sum)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;*/

        int res = 0;
        for(int i = 0; i < n + 1; ++i)
        {
            int t = k + sum[i];
            if(sumIdxMap.find(t) != sumIdxMap.end() && sumIdxMap[t] - i > 0)
            {
                res = max(res, sumIdxMap[t] - i);
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    //vector<int> a{1, -1, 5, -2, 3};
    //s.maxSubArrayLen(a, 3);
    vector<int> a{-2, -1, 2, 1};
    s.maxSubArrayLen(a, 1);
}
