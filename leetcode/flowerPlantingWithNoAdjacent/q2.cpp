#include "header.h"

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> res(N, 0);
        unordered_map<int, vector<int>> m;
        for(const auto& p : paths)
        {
            m[p[0]].push_back(p[1]);
            m[p[1]].push_back(p[0]);
        }

        for(int i = 0; i < N; ++i)
        {
            int id = i + 1;
            vector<bool> colors(4, true);
            for(const auto& j : m[id])
            {
                if(res[j - 1] != 0) colors[res[j - 1] - 1] = false;
            }
            for(int k = 0; k < 4; ++k)
            {
                if(colors[k])
                {
                    res[i] = k + 1;
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
