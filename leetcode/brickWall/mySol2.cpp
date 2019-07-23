#include "header.h"

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> m;
        int count = 0;
        for(const auto& v : wall) {
            int t = 0;
            for(int i = 0; i < v.size() - 1; ++i) {
                t += v[i];
                ++m[t];
                count = max(count, m[t]);
            }
        }
        return wall.size() - count;
    }
};

int main()
{
    //Solution s;
}