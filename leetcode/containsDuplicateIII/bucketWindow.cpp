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
#include <iterator>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0) return false;

        int w = t + 1;
        std::map<long, long> map;
        for(int i = 0; i < nums.size(); ++i)
        {
            long val = nums[i];
            long bucketId = getBucketId(val, w);

            if(map.find(bucketId) != map.end()) return true;

            if(map.find(bucketId - 1) != map.end() && std::abs(val - map[bucketId - 1]) <= t) return true;

            if(map.find(bucketId + 1) != map.end() && std::abs(val - map[bucketId + 1]) <= t) return true;

            map[bucketId] = val;

            if(i >= k) map.erase(getBucketId(nums[i - k ], w));
        }

        return false;
    }

    long getBucketId(int num, int w)
    {
        if(num < 0) return (num + 1) / w - 1;
        return num / w;
    }
};

int main() {
    Solution s;
    vector<int> a {-1, 2147483647};
    std::cout<<s.containsNearbyAlmostDuplicate(a, 1, 2147483647)<<std::endl;
    //vector<int> a {3, 6, 0, 4};
    //std::cout<<s.containsNearbyAlmostDuplicate(a, 2, 2)<<std::endl;
}
