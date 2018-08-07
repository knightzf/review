#include "header.h"

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        map<int, unordered_set<int>> m;
        for(int i = 0; i < n; ++i)
        {
            for(int num : nums[i])
            {
                m[num].insert(i);
            }
        }

        vector<int> res{-100000, 100000};
        vector<int> counter(n, 0);
        int cnt = 0;
        auto startIter = m.begin();
        for(const auto& p : m)
        {
            for(int idx : p.second)
            {
                if(counter[idx] == 0)
                    ++cnt;
                ++counter[idx];
            }

            if(cnt == n)
            {
                while(cnt == n)
                {
                    for(int idx : startIter->second)
                    {
                        --counter[idx];
                        if(counter[idx] == 0)
                            --cnt;
                    }
                    if(cnt != n)
                    {
                        if(p.first - startIter->first < res[1] - res[0] ||
                           (p.first - startIter->first == res[1] - res[0] && p.first < res[0]))
                        {
                            res = vector<int>{startIter->first, p.first};
                            if(res[1] == res[0]) return res;
                        }
                    }
                    ++startIter;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a{{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    s.smallestRange(a);
}
