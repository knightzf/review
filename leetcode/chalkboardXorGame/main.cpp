#include "header.h"

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        if(nums.empty()) return false;

        std::unordered_map<int, int> oddMap;
        std::unordered_map<int, int> evenMap;

        int v = 0;
        for(int n : nums)
        {
            if(oddMap.find(n) != oddMap.end())
            {
                evenMap[n] = oddMap[n] + 1;
                oddMap.erase(n);
            }
            else if(evenMap.find(n) != evenMap.end())
            {
                oddMap[n] = evenMap[n] + 1;
                evenMap.erase(n);
            }
            else
            {
                oddMap[n] = 1;
            }
            v = v ^ n;
        }

        if(v == 0) return true;

        return impl(oddMap, evenMap, true);
    }

    bool impl(std::unordered_map<int, int>& oddMap,
              std::unordered_map<int, int>& evenMap,
              bool isAlice)
    {
        if(!evenMap.empty())
        {
            oddMap[evenMap.begin()->first] = evenMap.begin()->second - 1;
            evenMap.erase(evenMap.begin());
            return impl(oddMap, evenMap, !isAlice);
        }

        if(oddMap.begin()->second > 1)
        {
            evenMap[oddMap.begin()->first] = oddMap.begin()->second - 1;
            oddMap.erase(oddMap.begin());
        }
        else
        {
            oddMap.erase(oddMap.begin());
        }

        if(oddMap.empty()) return isAlice ? false : true;

        return impl(oddMap, evenMap, !isAlice);
    }
};
int main()
{
    Solution s;
    //vector<int> a{1,0,1,0,0,2,2,0,0,1};
    vector<int> a{1,2,3};
    std::cout<<s.xorGame(a)<<std::endl;
}
