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

        map<long, vector<int>> sumIdxMap;
        sumIdxMap[0].push_back(0);

        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            //if(i != 0 && lower <= nums[i] && upper >= nums[i]) ++res;
            sum[i + 1] = sum[i] + nums[i];
            //if(i != 0 && lower <= sum[i + 1] && upper >= sum[i + 1]) ++res;
            sumIdxMap[sum[i + 1]].push_back(i + 1);
        }

        /*std::cout<<"res "<<res<<std::endl;

        for(int i : sum)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;

        for(auto p : sumIdxMap)
        {
            std::cout<<p.first<<std::endl;
            for(auto i : p.second)
            {
                std::cout<<"  "<<i<<"   ";
            }
            std::cout<<std::endl;
        }*/

        for(int i = 0; i < n + 1; ++i)
        {
            if(lower == upper)
            {
                long target = lower + sum[i];
                auto iter = sumIdxMap.find(target);
                if(iter != sumIdxMap.end())
                {
                    int t = findIdx(iter->second, i);
                    res += iter->second.size() - t;
                }
            }
            else
            {
                long lb = lower + sum[i];
                long ub = upper + sum[i];

                auto s = sumIdxMap.lower_bound(lb);
                auto e = sumIdxMap.upper_bound(ub);
                //std::cout<<"lb "<<lb<<" ub "<<ub<<std::endl;

                for(auto iter = s; iter != e; ++iter)
                {
                    int t = findIdx(iter->second, i);
                    //std::cout<<"t "<<i << " "<< iter->second.size()<< " "<< t<<std::endl;
                    res += iter->second.size() - t;
                }
            }
        }

        //if(lower <= 0 && upper >= 0) --res;

        return res;
    }
private:
    int findIdx(const vector<int>& v, int t)
    {
        if(v[0] > t) return 0;
        if(v.back() < t) return v.size();

        int s = 0, e = v.size() - 1;

        while(s < e - 1)
        {
            int mid = (s + e)/2;
            //std::cout<<"s "<<s<<" "<<e<<std::endl;
            if(v[mid] > t)
            {
                e = mid;
            }
            else if(v[mid] <= t)
            {
                s = mid;
            }
        }

        return v[s] > t ? s : (v[e] > t ? e : v.size());
    }
};

int main() {
    Solution s;
    if(0)
    {
        vector<int> a{-2, 5, -1};
        std::cout<<s.countRangeSum(a, -2, 2)<<std::endl;
    }
    if(0)
    {
        vector<int> a{0, 0};
        std::cout<<s.countRangeSum(a, 0, 0)<<std::endl;
    }
    if(0)
    {
        vector<int> a{1,4,-2,3,-4,3,0,-4,4};
        std::cout<<s.countRangeSum(a, 3, 6)<<std::endl;
    }
    {
        vector<int> a{-2147483647,0,-2147483647,2147483647};
        std::cout<<s.countRangeSum(a, -564, 3864)<<std::endl;
    }

}
