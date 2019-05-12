#include "header.h"

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());
        int maxMoves = max(stones[n - 1] - stones[1], stones[n - 2] - stones[0]) + 1 - (n - 1);
        int minMoves = maxMoves;
        for(int i = 0, j = 0; j < n; ++j)
        {
            while(stones[j] - stones[i] >= n) ++i;
            if(j - i + 1 == n - 1 && stones[j] - stones[i] == n - 2)
            {
                minMoves = min(minMoves, 2);
            }
            else
            {
                minMoves = min(minMoves, n - (j - i + 1));
            }
        }
        return {minMoves, maxMoves};
    }
};

int main()
{
    Solution s;
}
