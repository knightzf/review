#include "header.h"

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>, int> s;
        for(const auto& d : dominoes) {
            ++s[{min(d[0], d[1]), max(d[0], d[1])}];
        }
        int res = 0;
        for(const auto& p : s) {
            if(p.second > 1) res += p.second * (p.second - 1) / 2;
        }
        return res;
    }
};

int main()
{
    Solution s;
}
