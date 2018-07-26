#include "header.h"

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                res = max(res, abs(arrays[i][0] - arrays[j].back()));
                res = max(res, abs(arrays[i].back() - arrays[j][0]));
            }
        }
        return res;
    }
};

int main() {
    //Solution s;
}
