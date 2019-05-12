#include "header.h"

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> v{a, b, c};
        sort(v.begin(), v.end());
        int x = v[1] - v[0] - 1;
        int y = v[2] - v[1] - 1;
        
        int minMove = 2;
        if(x == 0 && y == 0) minMove = 0;
        else if(x == 0 || y == 0 || x == 1 || y == 1) minMove = 1;
        return {minMove, x + y};
    }
};

int main()
{
    Solution s;
}
