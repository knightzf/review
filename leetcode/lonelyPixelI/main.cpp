#include "header.h"

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if(picture.empty() || picture[0].empty()) return 0;
        int m = picture.size();
        int n = picture[0].size();
        unordered_map<int, vector<int>> rowMap;
        unordered_map<int, vector<int>> colMap;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(picture[i][j] == 'B')
                {
                    rowMap[i].emplace_back(j);
                    colMap[j].emplace_back(i);
                }
            }
        }

        int res = 0;
        for(const auto& p : rowMap)
        {
            if(p.second.size() == 1)
            {
                if(colMap[p.second[0]].size() == 1)
                    ++res;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
