#include "header.h"

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < n; ++i)
        {
            time[i] %= 60;
            m[time[i]].push_back(i);
        }
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            int remain = time[i] == 0 ? 0 : (60 - time[i]);
            if(m.count(remain))
            {
                auto& v = m[remain];
                auto upper = std::upper_bound(v.begin(), v.end(), i);
                res += distance(upper, v.end());
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
