#include "header.h"

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int res = 0;
        for(int i = 0, n = ages.size(); i < n; ++i) {
            auto iter = upper_bound(ages.begin(), ages.end(), ages[i] / 2 + 7);
            auto jter = upper_bound(ages.begin(), ages.end(), ages[i]);
            if(iter < jter) res += distance(iter, jter) - 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
}