#include "header.h"

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        map<int, int> m;
        int res = 0;
        for(int i = 0, sum = 0; i < n; ++i) {
            sum += (hours[i] > 8 ? 1 : -1);
            if(sum > 0) res = i + 1;
            else if(!m.empty()){
                int t = 0;
                for(auto iter = m.begin(), endIter = m.upper_bound(sum - 1); iter != endIter; ++iter) {
                    t = max(t, i - iter->second);
                }
                res = max(res, t);
            }
            if(!m.count(sum)) m[sum] = i;
        }
        return res;
    }
};

int main()
{
    Solution s;
}

