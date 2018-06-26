#include "header.h"

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for(const auto& s: timePoints)
        {
            v.push_back(stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2)));
        }
        sort(v.begin(), v.end());

        int n = v.size();
        int res = INT_MAX;
        for(int i = 0; i < n; ++i)
        {
            int nextIdx = i == (n - 1) ? 0 : (i + 1);
            res = min(res, (v[nextIdx] >= v[i] ? (v[nextIdx] - v[i]) : (24 * 60 + v[nextIdx] - v[i])));
        }
        return res;
    }
};

int main()
{
    Solution s;
}
