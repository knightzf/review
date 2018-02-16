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

class NumArray {
private:
    int n;
    vector<int> dp;
    std::map<int, int> changes;
    vector<int> localnums;
public:
    NumArray(vector<int> nums) {
        localnums = nums;
        n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            if(i == 0)
                dp.push_back(nums[i]);
            else
                dp.push_back(nums[i] + dp[i - 1]);
        }
    }

    void update(int i, int val) {
        changes[i] = val;
    }

    int sumRange(int i, int j) {
        int sumChanges = 0;
        for(auto iter = changes.begin(); iter != changes.end();)
        {
            sumChanges += iter->second - localnums[iter->first];
            localnums[iter->first] = iter->second;
            dp[iter->first] += sumChanges;
            changes.erase(iter++);
        }

        for(auto i : dp)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;

        return i == 0 ? dp[j] : (dp[j] - dp[i - 1]);

        /*auto start = changes.lower_bound(i);
        auto end = changes.upper_bound(j);

        if(start != changes.end())
        {
            int sumChanges = 0;
            for(auto iter = start; iter != end;)
            {
                t += iter->second - localnums[iter->first];
                sumChanges += iter->second - localnums[iter->first];
                localnums[iter->first] = iter->second;
                dp[iter->first] += sumChanges;
                changes.erase(iter++);
            }
        }

        for(auto i : dp)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;*/
    }
};


int main() {
    //Solution s;

    vector<int> t{9, -8};
    NumArray a(t);
    a.update(0, 3);
    std::cout<<a.sumRange(1, 1)<<std::endl;
    std::cout<<a.sumRange(0, 1)<<std::endl;
    a.update(1, -3);
    //a.update(0, -4);
    std::cout<<a.sumRange(0, 1)<<std::endl;
}
