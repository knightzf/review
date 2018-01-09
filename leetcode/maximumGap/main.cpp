#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
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

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        if(n < 2) return 0;

        int min = INT_MAX;
        int max = INT_MIN;

        for(int i = 0; i < n; ++i)
        {
            min = std::min(min, nums[i]);
            max = std::max(max, nums[i]);
        }

        if(min == max) return 0;

        int bucketSize = (max - min) / (n - 1);
        if(bucketSize == 0) bucketSize = 1;
        //std::cout<<bucketSize<<std::endl;
        int numBuckets = (max - min + 1) / bucketSize + 1;

        vector<std::pair<int, int>> buckets(numBuckets, std::make_pair(INT_MAX, INT_MIN));

        for(int i = 0; i < n; ++i)
        {
            int diff = nums[i] - min;
            auto& p = buckets[diff/bucketSize];
            p.first = std::min(p.first, nums[i]);
            p.second = std::max(p.second, nums[i]);
        }

        /*for(int i = 0; i < numBuckets; ++i)
        {
            std::cout<<buckets[i].first<<" "<<buckets[i].second<<std::endl;
        }*/

        int maxGap = 0;
        for(int i = 0; i < numBuckets; ++i)
        {
            while(i < numBuckets && buckets[i].first == INT_MAX && buckets[i].second == INT_MIN)
            {
                ++i;
            }

            int j = i + 1;
            while(j < numBuckets && buckets[j].first == INT_MAX && buckets[j].second == INT_MIN)
            {
                ++j;
            }

            if(j < numBuckets && buckets[j].first != INT_MAX && buckets[j].second != INT_MIN)
                maxGap = std::max(maxGap, buckets[j].first - buckets[i].second);
        }

        return maxGap;
    }
};

int main()
{
    Solution s;
    vector<int> a{100, 3, 2, 1};
    std::cout<<s.maximumGap(a)<<std::endl;
}
