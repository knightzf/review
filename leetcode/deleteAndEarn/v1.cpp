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

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        std::map<int, int> m;
        for(auto i : nums)
        {
            ++m[i];
        }

        return impl(m);
    }

    int impl(std::map<int, int>& numCount)
    {
        if(numCount.empty())
        {
            return 0;
        }

        int max = 0;
        for(const auto& item : numCount)
        {
            if(item.second)
            {
                int v = item.first;
                --numCount[v];
                bool hasLess = numCount.find(v - 1) !=  numCount.end();
                int lessCount =  hasLess ? numCount[v - 1] : 0;
                bool hasMore = numCount.find(v + 1) !=  numCount.end();
                int moreCount = hasMore ? numCount[v + 1] : 0;

                if(hasLess)
                    numCount[v - 1] = 0;

                if(hasMore)
                    numCount[v + 1] = 0;

                int t = v + impl(numCount);
                max = max > t ? max : t;

                ++numCount[v];
                if(hasLess)
                    numCount[v - 1] = lessCount;

                if(hasMore)
                    numCount[v + 1] = moreCount;
            }
        }

        return max;
    }
};

int main()
{
    Solution s;
    vector<int> nums{2, 2, 3, 3, 3, 4};
    std::cout<<s.deleteAndEarn(nums)<<std::endl;
}
