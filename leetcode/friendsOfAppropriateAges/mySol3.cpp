#include "header.h"

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int res = 0;
        for(int i = 0, n = ages.size(), startIdx = 0, endIdx = 0; i < n; ++i) {
			int t = ages[i] / 2 + 7;
			while(ages[startIdx] <= t) ++startIdx;
			while(ages[endIdx] <= ages[i]) ++endIdx;
            if(startIdx < endIdx) res += endIdx - startIdx;
        }
        return res;
    }
};

int main()
{
    Solution s;
}