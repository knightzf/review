#include "header.h"

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());
        int range = stones.back() - stones.front();
        int slots = range + 1 - n;
        if(slots == 0) return {0, 0};
        int maxMoves = slots;
        if(stones[1] - stones[0] > 1 && stones[n - 1] - stones[n - 2] > 1) {
            maxMoves -= min(stones[1] - stones[0], stones[n - 1] - stones[n - 2]) - 1;
        }
        int minMoves = maxMoves;
        for(int i = 0; i < n; ++i)
        {
            int end = stones[i] + n;
            auto iter = lower_bound(stones.begin(), stones.end(), end);
            int leftRemain = i;
            int rightRemain = distance(iter, stones.end());
            --iter;
            if((leftRemain == 1 && rightRemain == 0 && end - 1 != stones.back()) ||
               (leftRemain == 0 && rightRemain == 1 && end - 1 != *iter))
               ++leftRemain;
            minMoves = min(minMoves, leftRemain + rightRemain);
        }
        return {minMoves, maxMoves};
    }
};

int main()
{
    Solution s;
}
