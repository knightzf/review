#include "header.h"

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.empty()) return m * n;
        int xOverlap = ops[0][0], yOverlap = ops[0][1];
        for(int i = 1, cnt = ops.size(); i < cnt; ++i)
        {
            xOverlap = min(xOverlap, ops[i][0]);
            yOverlap = min(yOverlap, ops[i][1]);
        }
        return xOverlap * yOverlap;
    }
};

int main() {
    Solution s;
}
