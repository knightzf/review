#include "header.h"

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        unordered_map<int, int> m;
        function<int(int)> dfs = [&](int startIdx)
        {
            if(startIdx == n) return 0;
            if(!m.count(startIdx))
            {
                int res = 0;
                int curMax = A[startIdx];
                for(int i = startIdx; i < startIdx + K && i < n; ++i)
                {
                    curMax = max(curMax, A[i]);
                    int t = curMax * (i - startIdx + 1) + dfs(i + 1);
                    res = max(res, t);
                }
                m[startIdx] = res;
            }
            return m[startIdx];
        };
        return dfs(0);
    }
};

int main()
{
    Solution s;
}

