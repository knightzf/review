#include "header.h"

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> v{a, b, c};
        sort(v.begin(), v.end());
        int maxmove = v[1] - v[0] - 1 + v[2] - v[1] - 1;
        int minmove = v[1] - v[0] <= 1 || v[2] - v[1] <= 1 ? 1 : 2;
        return {minmove, maxmove};
    }
};

int main()
{
    Solution s;
}