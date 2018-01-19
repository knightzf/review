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
        std::map<long, std::set<int>> map;
        for(int i = 0; i < nums.size(); ++i)
        {
            long val = nums[i];
            //std::cout<<"val "<<val<<std::endl;
            map[val].insert(i);

            auto iter = map.find(val);

            if(iter->second.size() > 0 && t >= 0)
            {
                auto jter = iter->second.find(i);
                if(jter != iter->second.begin())
                {
                    auto p = jter; --p;
                    while(true)
                    {
                        if(*jter - *p <= k) return true;

                        if(p == iter->second.begin()) break;

                        --p;
                    }
                }

                auto p = jter; ++p;
                while(p != iter->second.end())
                {
                    if(*p - *jter <= k) return true;
                    ++p;
                }
            }

            if(iter != map.begin())
            {
                auto p = iter; --p;
                while(val - p->first <= t)
                {
                    for(auto m = p->second.begin(); m != p->second.end(); ++m)
                    {
                        if(std::abs(*m - i) <= k) return true;
                    }

                    if(p == map.begin()) break;

                    --p;
                }
            }

            auto p = iter; ++p;
            while(p != map.end() && p->first - val <= t)
            {
                for(auto m = p->second.begin(); m != p->second.end(); ++m)
                {
                    if(std::abs(*m - i) <= k) return true;
                }

                ++p;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> a {-1, 2147483647};
    std::cout<<s.containsNearbyAlmostDuplicate(a, 1, 2147483647)<<std::endl;
    //vector<int> a {3, 6, 0, 4};
    //std::cout<<s.containsNearbyAlmostDuplicate(a, 2, 2)<<std::endl;
}
